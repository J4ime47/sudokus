#include "head.h"

int main(){
    System system;
    Sudoku candidate;
    int i,j;
    double beta;

    srand(time(NULL));
    
    //Inicializamos el sistema
    system.beta_initial=0.001;
    system.beta_final=100.0;
    system.termalization_steps=50000;
    system.beta_step=0.01;
    
    //Inicializamos el sudoku (Uso uno de ejemplo de internet)
    int pregunta[9][9] = {
        {0,3,7,2,0,0,0,0,0},
        {0,0,0,0,7,0,4,0,0},
        {0,2,0,8,0,6,9,7,0},
        {0,0,0,0,0,1,6,5,0},
        {0,0,6,0,0,0,2,0,0},
        {0,4,0,9,0,0,8,0,0},
        {2,5,0,0,0,4,0,9,6},
        {6,0,0,0,0,2,0,0,0},
        {4,7,3,0,0,8,0,2,5}
    };

    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            system.sudoku.mat[i][j].val=pregunta[i][j];
        }
    }
    

    set_fixed(&system.sudoku);

    printf("Sudoku inicial\n");
    print_sudoku(system.sudoku);
    initialize_sudoku(&system.sudoku);
    printf("\nSudoku después de inicializar:\n");
    print_sudoku(system.sudoku);
    // Inicializamos el candidato
    copy_sudoku(&system.sudoku,&candidate);
    system.energy=energy(system.sudoku);
    printf("\nEnergía inicial: %d\n", system.energy);

    for(beta=system.beta_initial;beta<system.beta_final;beta+=system.beta_step){
        for(i=0;i<system.termalization_steps;i++){
            change(system.sudoku,&candidate);
            metropolis_step(&system,candidate,beta);
        }
        printf("%d\n ",system.energy);
        if(system.energy==0) break;

    }
    printf("\n--SUDOKU FINAL--\n");
    print_sudoku(system.sudoku);

    return 0;
}