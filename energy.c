#include "head.h"

//Recordar que los números de la matriz van del 1 al 9, y que las matrices empiezan desde el 0

// Devuelve el numero de repetidos en una fila
int rep_num_fil(Sudoku sudoku, int fil){
    int frecfil[dim];
    int j,sum;

    sum=0;
    
    for(j=0;j<dim;j++){
        frecfil[j]=0;
        
    }

    // Contar cuántas veces aparece cada número 1-9 en la fila y columna
    for(j=0;j<dim;j++){
        frecfil[sudoku.mat[fil][j].val-1]++;
    }
    //Pensar que si la frecuencia es 2, tenemos solamente un numero repetido.
    //Notar que ahora tendremos algunos valores negativos, los cuales no hay que contar
    for(j=0;j<dim;j++){
        if(frecfil[j]>1){
            sum+=frecfil[j]-1;
        }
    }

    return sum;
}

// Devuelve el numero de repetidos en una columna
int rep_num_col(Sudoku sudoku, int col){
    int freccol[dim];
    int j,sum;

    sum=0;
    
    for(j=0;j<dim;j++){
        freccol[j]=0;
        
    }

    // Contar cuántas veces aparece cada número 1-9 en la fila y columna
    for(j=0;j<dim;j++){
        freccol[sudoku.mat[j][col].val-1]++;
    }
    //Pensar que si la frecuencia es 2, tenemos solamente un numero repetido.
    //Notar que ahora tendremos algunos valores negativos, los cuales no hay que contar
    for(j=0;j<dim;j++){
        if(freccol[j]>1){
            sum+=freccol[j]-1;
        }
    }

    return sum;
}



// Calculamos la energía de una configuración, la cual definimos 
// por el número de números repetidos en fila columna. Solo sirve para la configuración inicial.
int energy(Sudoku sudoku){
    int i, total_energy;
    total_energy = 0;

    // Contar duplicados en filas y columnas (No hay que contar en las subcajas ya que siempre cumplen)
    for(i=0; i<dim; i++){
        total_energy += rep_num_fil(sudoku, i)+rep_num_col(sudoku,i);
    }

    return total_energy;
}

//Tras hacer un intercambio entre dos componentes del sudoku, 
int delta_E(Sudoku sudoku,Sudoku candidate, int *icords, int *jcords){
    int eold, ecand;
    eold=rep_num_fil(sudoku,icords[0]) +rep_num_fil(sudoku,icords[1]) +rep_num_col(sudoku,jcords[0]) + rep_num_col(sudoku,jcords[1]);
    ecand=rep_num_fil(candidate,icords[0]) +rep_num_fil(candidate,icords[1]) +rep_num_col(candidate,jcords[0]) + rep_num_col(candidate,jcords[1]);
    return ecand-eold;
}