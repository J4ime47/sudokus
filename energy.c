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


// Calculamos la energía de una configuración, la cual definimos 
// por el número de números repetidos en fila columna
int energy(Sudoku sudoku){
    int i, total_energy;
    total_energy = 0;

    // Contar duplicados en filas y columnas (No hay que contar en las subcajas ya que siempre cumplen)
    for(i=0; i<dim; i++){
        total_energy += rep_num_filcol(sudoku, i);
    }



    return total_energy;
}