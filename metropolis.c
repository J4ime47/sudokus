#include "head.h"

// Initializes de sudoku with a completely random configuration, in such way that the subboxes add
// 0 energy
void initialize_sudoku(Sudoku *sudoku){
    int i,j,ibox,jbox,N;
    int bsr,bsc;
    int num_to_add;   //The number which we are going to fill de subbox

    

    //For each subbox
    for(ibox=0;ibox<3;ibox++){
        for(jbox=0;jbox<3;jbox++){
            show_fixed(ibox,jbox,arr,sudoku,&N); 
            bsr=3*ibox; //Box-starting-row
            bsc=3*jbox; //Same for colum
            num_to_add=1;

            for(i=bsr;i<bsr+3;i++){
                for(j=bsc;j<bsc+3;j++){
                    // If num_to_add is not a previously fixed number (not in arr) 
                    // and the component of the matrix is not fixed, then we add it to the subbox
                    if(!sudoku->mat[i][j].fixed_num){
                        
                        while(in_array(arr,N,num_to_add)){
                            num_to_add++;
                        }
                        
                        sudoku->mat[i][j].val=num_to_add;
                        num_to_add++;
                    }
                }
            }

        }
    }
}

// Swaps two random numbes in a random subbox
void change (Sudoku initial_sudoku, Sudoku *final_sudoku, int *icords, int *jcords){
    int ibox, jbox,a;
    //We copy the initial sudoku into the candidate and then we swap components

    copy_sudoku(initial_sudoku, final_sudoku);
    do{
        //Choose a subbox, and components of the matrix
        ibox=uniform_int(0,3);
        jbox=uniform_int(0,3);
        for(a=0;a<2;a++){
            icords[a]=3*ibox+uniform_int(0,3);
            jcords[a]=3*jbox+uniform_int(0,3);
        }
    }
    // Queremos que busque mientras alguna de las componentes esté fija
    while(final_sudoku->mat[icords[0]][jcords[0]].fixed_num || final_sudoku->mat[icords[1]][jcords[1]].fixed_num);
    
    final_sudoku->mat[icords[0]][jcords[0]].val=initial_sudoku.mat[icords[1]][jcords[1]].val;
    final_sudoku->mat[icords[1]][jcords[1]].val=initial_sudoku.mat[icords[0]][jcords[0]].val;
    
    
    
}

void metropolis_step (System *system,Sudoku candidate , double beta, int *admitidos, int deltaE){
    double C= exp(-beta*(deltaE));
    double omega = fran();
    if(omega<C){
        system->energy+=deltaE;
        copy_sudoku(candidate,&system->sudoku);
        (*admitidos)++;
    }
}

