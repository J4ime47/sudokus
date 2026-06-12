#include "head.h"

void copy_sudoku(Sudoku inicial,Sudoku final){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            final.mat[i][j].fixed_num=inicial.mat[i][j].fixed_num;
            final.mat[i][j].val=inicial.mat[i][j].val;
        }
    }
}