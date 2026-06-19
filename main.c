#include "head.h"



int main(){
    System systema;
    Sudoku candidate;
    int i,j,admitidos,total_steps;
    double beta,ttot,admitancia;
    clock_t inicio,final;
    FILE *f =fopen("results/extremo.txt","w");
    if(f==NULL) return 1;
    
    
    system("cls");
    srand(time(NULL));
    
    //Inicializamos el sistema
    systema.beta_initial=0.1;
    systema.termalization_steps=10000;
    systema.beta_step=0.01;
    
    //Inicializamos el sudoku (Uso uno de ejemplo de internet)
    int pregunta[9][9] = {
        {0,0,4,3,0,1,0,7,0},
        {0,0,2,0,0,0,3,0,0},
        {8,0,0,0,0,0,0,0,1},
        {0,0,0,0,9,0,0,2,0},
        {0,2,0,0,0,8,0,6,0},
        {0,0,5,0,7,0,1,0,0},
        {0,4,0,0,5,0,0,9,0},
        {0,0,0,0,0,7,6,0,0},
        {0,9,0,0,0,6,7,0,0}
    };

    //Copiamos la matriz de la pregunta en el sudoku
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            systema.sudoku.mat[i][j].val=pregunta[i][j];
        }
    }

    set_fixed(&systema.sudoku);

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
    printf("\nEnergia inicial: %d\n", systema.energy);
    wait();
    //Contador de iteraciones exactas
    total_steps = 0;

    beta=systema.beta_initial;

    //Iniciamos cronometro
    inicio=clock();

    while(systema.energy!=0){
        admitidos=0;
        for(i=0;i<systema.termalization_steps;i++){
            change(systema.sudoku,&candidate);
            metropolis_step(&systema,candidate,beta,&admitidos);
            total_steps++;
            if(systema.energy==0) break;
        }
        admitancia=admitidos/((double)systema.termalization_steps)*100.0;
        fprintf(f,"%.2f %i %.2f\n", beta, systema.energy,admitancia);
        beta+=systema.beta_step;
        if(total_steps%50000==0){
            system("cls");
            printf("--INTENTO %i--.\n",total_steps);
            print_sudoku(systema.sudoku);
            printf("beta=%.2f, Energia=%i, Admitancia=%.2f%%.\n", beta, systema.energy,admitancia);
        }    
    }

    final=clock();

    ttot=(double)(final-inicio)/CLOCKS_PER_SEC;
    
    system("cls");
    printf("--SUDOKU FINAL--\n");
    print_solution(systema.sudoku);
    printf("beta=%.2f, Energia=%i, Admitancia=%.2f%%.\n", beta, systema.energy,admitancia);
    printf("Se han hecho %d iteraciones.\n", total_steps);
    printf("El programa ha tardado %.2f segundos\n\n", ttot);
    fclose(f);
    return 0;
}