#include "head.h"



int main(){
    System systema;
    Sudoku candidate;
    int i,j,admitidos,total_steps,num_unfixed,icords[2],jcords[2],delta_En,repetidos,prev_energy,resets;
    double beta,ttot,admitancia;
    clock_t inicio,final,timeo;
    //FILE *f =fopen("results/facil.txt","w");
    //if(f==NULL) return 1;
    timeo=time(NULL);
    
    system("cls");
    srand(timeo);
    
    

    //Inicializamos el sudoku (Uso uno de ejemplo de internet)
  int pregunta[9][9] = {
    {0,0,0,0,5,0,3,0,0},
    {7,0,0,2,4,0,0,0,0},
    {0,0,0,0,3,0,6,0,2},
    {5,0,2,3,9,0,0,6,0},
    {0,3,6,8,7,0,5,0,0},
    {0,0,0,0,6,0,7,0,4},
    {0,0,7,4,0,0,0,5,3},
    {0,0,8,0,0,5,4,1,6},
    {2,0,0,0,0,0,8,0,7}
};

    //Copiamos la matriz de la pregunta en el sudoku
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            systema.sudoku.mat[i][j].val=pregunta[i][j];
        }
    }

    set_fixed(&systema.sudoku,&num_unfixed);

    //Inicializamos el sistema
    systema.beta_initial=0.01;
    systema.termalization_steps=20;
    systema.beta_step=0.01;


    printf("--SUDOKU INICIAL--\n");
    print_sudoku(systema.sudoku);
    initialize_sudoku(&systema.sudoku);
    wait();
    system("cls");
    printf("--SUDOKU INICIALIZADO--\n");
    print_sudoku(systema.sudoku);

    // Inicializamos el candidato (como nos de la gana)
    copy_sudoku(systema.sudoku,&candidate);
    systema.energy=energy(systema.sudoku);
    printf("\nEnergia inicial: %d, GL=%i, SEMILLA=%ld\n", systema.energy,num_unfixed,timeo);
    wait();
    //Contador de iteraciones exactas
    resets=0;
    total_steps = 0;
    repetidos = 0;
    prev_energy = systema.energy;

    beta=systema.beta_initial;

    //Iniciamos cronometro
    inicio=clock();

    while(systema.energy!=0){
        admitidos=0;
        //fprintf(f,"%.2f %i %.2f\n", beta, systema.energy,admitancia);
        for(i=0;i<systema.termalization_steps;i++){
            change(systema.sudoku,&candidate,icords,jcords);
            delta_En=delta_E(systema.sudoku,candidate,icords,jcords);
            metropolis_step(&systema,candidate,beta,&admitidos,delta_En);
            total_steps++;
            if(systema.energy==0) break;
        }
        admitancia=admitidos/((double)systema.termalization_steps)*100.0;

        //Añadimos esto para cuando se queda estancado
        if(systema.energy == prev_energy){
            repetidos++;
        }
        else{
            prev_energy = systema.energy;
            repetidos = 0;
        }

        //Si se queda atascado en un minimo local, comenzamos del principio
        if(repetidos >= 15){
            //initialize_sudoku(&systema.sudoku);
            //copy_sudoku(systema.sudoku,&candidate);
            systema.energy=energy(systema.sudoku);
            prev_energy = systema.energy;
            repetidos = 0;
            beta = systema.beta_initial;
            resets++;
        }

        printf("Energia=%i , Admitancia=%.1f%%\n",systema.energy,admitancia);
        
        
        beta+=systema.beta_step;   
    }

    final=clock();

    ttot=(double)(final-inicio)/CLOCKS_PER_SEC;
    
    system("cls");
    printf("--SUDOKU FINAL--\n");
    print_solution(systema.sudoku);
    //fprintf(f,"%.2f %i %.2f\n", beta, systema.energy,admitancia);
    printf("beta=%.2f, Energia=%i, Admitancia=%.2f%% Resets=%i.\n", beta, systema.energy,admitancia,resets);
    printf("Se han hecho %d iteraciones.\n", total_steps);
    printf("El programa ha tardado %.3f segundos\n\n", ttot);
    //fclose(f);
    return 0;
}