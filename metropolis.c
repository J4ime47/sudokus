#include "head.h"

//Initializes de sudoku with a completely random configuration
void initialize_sudoku(Sudoku *sudoku){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            if(!sudoku->mat[i][j].fixed_num){
                sudoku->mat[i][j].val=rand_int_19();
            }
        }
    }
}

// Changes a random value of the sudoku
void change (Sudoku *initial_sudoku, Sudoku *final_sudoku){
    int idx, idy;
    idx=rand_int_19()-1;
    idy=rand_int_19()-1;
    copy_sudoku(initial_sudoku,final_sudoku);

    final_sudoku->mat[idx][idy].val=rand_int_19();
}

void metropolis_step (System *system, Sudoku candidate){
    int E_cand=energy(candidate);
    double C= exp(E_cand-system->energy);
    double omega = fran();
    if(omega<C){
        system->energy=E_cand;
        copy_sudoku(&candidate,&system->sudoku);
    }

}

