#include "head.h"

void copy_sudoku(Sudoku *inicial,Sudoku *final){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            final->mat[i][j].fixed_num=inicial->mat[i][j].fixed_num;
            final->mat[i][j].val=inicial->mat[i][j].val;
        }
    }
}

void print_sudoku(Sudoku sudoku){
    int i,j;
    for(i=0;i<dim;i++){
        if(i%3==0){
            printf("---------------------\n");
        }
        for(j=0;j<dim;j++){
            if(j%3==0){
                printf("| %d ", sudoku.mat[i][j].val);
            }
            else{
                printf("%d ", sudoku.mat[i][j].val);
            }
        }
        printf("\n");
    }
}

//Marca que componentes de la matriz son fijos, poniendo que los huecos siempre seran 0 inicialmente
void set_fixed(Sudoku *sudoku){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            if(sudoku->mat[i][j].val!=0){
                sudoku->mat[i][j].fixed_num=1;
            }
            else{
                sudoku->mat[i][j].fixed_num=0;
            }
        }
    }
}