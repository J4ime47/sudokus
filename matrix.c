#include "head.h"

int arr[dim];

void copy_sudoku(Sudoku inicial,Sudoku *final){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            final->mat[i][j].fixed_num=inicial.mat[i][j].fixed_num;
            final->mat[i][j].val=inicial.mat[i][j].val;
        }
    }
}

void print_sudoku(Sudoku sudoku){
    int i,j;
    for(i=0;i<dim;i++){
        if(i%3==0){
            printf("------------------------\n");
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

//Marca que componentes de la matriz son fijos, poniendo que los huecos siempre seran 0 
//inicialmente. 
void set_fixed(Sudoku *sudoku){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            if(sudoku->mat[i][j].val!=0){
                sudoku->mat[i][j].fixed_num=true;
            }
            else{
                sudoku->mat[i][j].fixed_num=false;
            }
        }
    }
}

// Dada una subcaja 3x3 del sudoku, encuentra que numeros están fijos y el número de estos
// Notese que arr es un array de dimesion #dim 9.
// Esto lo hacemos solo una vez al principio
void show_fixed(int ibox, int jbox, int *arr, Sudoku *sudoku,int *nums){
    int i,j;
    int bsc, bsr;

    *nums=0;

    //box_start_col···bsc
    bsc=3*jbox;
    bsr=3*ibox;

    for(i=0;i<dim;i++) arr[i]=0;
    

    //Guardamos el valor de cada uno de los numeros fijos, junto con el numero de estos
    for(i=bsr;i<bsr+3;i++){
        for(j=bsc;j<bsc+3;j++){
            if(sudoku->mat[i][j].fixed_num){
                arr[*nums]=sudoku->mat[i][j].val;
                (*nums)++; //Ojo a la sutileza que diría Tarancón
            }
        }
    }
}


//Dado un array y su tamaño, devuelve si un valor está en ese array
bool in_array (int *v,int N, int num){
    int i;
    for(i=0;i<N;i++){
        if(v[i]==num){
            return true;
        }
    }
    return false;
}

