#include "head.h"

//Recordar que los números de la matriz van del 1 al 9, y que las matrices empiezan desde el 0


int rep_num_filcol(Sudoku sudoku, int filcol){
    int frecfil[dim],freccol[dim];
    int i,j,sum;

    sum=0;
    
    for(j=0;j<dim;j++){
        frecfil[j]=0;
        freccol[j]=0;
    }

    // Contar cuántas veces aparece cada número 1-9 en la fila y columna
    for(i=1;i<=dim;i++){
        for(j=0;j<dim;j++){
            if(sudoku.mat[filcol][j].val==i){
                frecfil[i-1]++;
            }
            if(sudoku.mat[j][filcol].val==i){
                freccol[i-1]++;
            }
        }
    }

    //Pensar que si la frecuencia es 2, tenemos solamente un numero repetido.
    //Notar que ahora tendremos algunos valores negativos, los cuales no hay que contar
    for(j=0;j<dim;j++){
        if(freccol[j]>1){
            sum+=freccol[j]-1;
        }
        if(frecfil[j]>1){
            sum+=frecfil[j]-1;
        }
    }

    return sum;
}

// Calculamos duplicados en cada subcaja 3x3
int rep_num_box(Sudoku sudoku, int box_row, int box_col){
    int frec[dim];
    int i, j, sum, box_start_row, box_start_col;

    sum = 0;
    for(i=0; i<dim; i++) frec[i] = 0;

    box_start_row = box_row * 3;
    box_start_col = box_col * 3;

    // Contar cuántas veces aparece cada número 1-9 en la subcaja
    for(i = box_start_row; i < box_start_row + 3; i++){
        for(j = box_start_col; j < box_start_col + 3; j++){
            if(sudoku.mat[i][j].val >= 1 && sudoku.mat[i][j].val <= dim){
                frec[sudoku.mat[i][j].val - 1]++;
            }
        }
    }

    // Contar duplicados (frecuencia > 1)
    for(i = 0; i < dim; i++){
        if(frec[i] > 1){
            sum += frec[i] - 1;
        }
    }

    return sum;
}

// Calculamos la energía de una configuración, la cual definimos por el número de números repetidos en fila, 
// columna y subcaja
int energy(Sudoku sudoku){
    int i, j, total_energy;
    total_energy = 0;

    // Contar duplicados en filas y columnas
    for(i=0; i<dim; i++){
        total_energy += rep_num_filcol(sudoku, i);
    }

    // Contar duplicados en las subcajas 3x3
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            total_energy += rep_num_box(sudoku, i, j);
        }
    }

    return total_energy;
}