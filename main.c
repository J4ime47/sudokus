#include "head.h"



int main(){
    System system;
    Sudoku candidate;
    int i,j,admitidos;
    double beta,ttot,admitancia;
    clock_t inicio,final;
    
    

    srand(time(NULL));
    
    //Inicializamos el sistema
    system.beta_initial=0.1;
    system.termalization_steps=10000;
    system.beta_step=0.01;
    
    //Inicializamos el sudoku (Uso uno de ejemplo de internet)
    int pregunta[9][9] = {
        {8,0,0,0,0,0,0,0,0},
        {0,0,3,6,0,0,0,0,0},
        {0,7,0,0,9,0,2,0,0},
        {0,5,0,0,0,7,0,0,0},
        {0,0,0,0,4,5,7,0,0},
        {0,0,0,1,0,0,0,3,0},
        {0,0,1,0,0,0,0,6,8},
        {0,0,8,5,0,0,0,1,0},
        {0,9,0,0,0,0,4,0,0}
    };

    //Copiamos la matriz de la pregunta en el sudoku
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            system.sudoku.mat[i][j].val=pregunta[i][j];
        }
    }

    set_fixed(&system.sudoku);

    printf("Sudoku inicial\n");
    print_sudoku(system.sudoku);
    initialize_sudoku(&system.sudoku);
    printf("\nSudoku despues de inicializar:\n");
    print_sudoku(system.sudoku);
    // Inicializamos el candidato (como nos de la gana)
    copy_sudoku(system.sudoku,&candidate);
    system.energy=energy(system.sudoku);
    printf("\nEnergia inicial: %d\n", system.energy);

    //Contador de iteraciones exactas
    int total_steps = 0;

    beta=system.beta_initial;

    //Iniciamos cronometro
    inicio=clock();

    while(system.energy!=0){
        admitidos=0;
        for(i=0;i<system.termalization_steps;i++){
            change(system.sudoku,&candidate);
            metropolis_step(&system,candidate,beta,&admitidos);
            total_steps++;
            if(system.energy==0) break;
        }
        admitancia=admitidos/((double)system.termalization_steps)*100.0;
        printf("beta=%.3f, energia=%d, admitancia=%.1f%%\n", beta, system.energy,admitancia);
        beta+=system.beta_step;
        
    }

    final=clock();

    ttot=(double)(final-inicio)/CLOCKS_PER_SEC;
    
    
    printf("\n--SUDOKU FINAL--\n");
    print_sudoku(system.sudoku);
    printf("Se han hecho %d iteraciones.\n", total_steps);
    printf("El programa ha tardado %.2f segundos", ttot);

    return 0;
}