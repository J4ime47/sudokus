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

    for(j=0;j<dim;j++){ // Pensarlo con j=0, y que el el frec[0] es el numero de veces que sale el 1
        frecfil[j]+=sudoku.mat[filcol][j].val==j+1;
        freccol[j]+=sudoku.mat[j][filcol].val==j+1;
    }

    //Pensar que si la frecuencia es 2, tenemos solamente un numero repetido.
    //Notar que ahora tendremos algunos valores negativos, los cuales no hay que contar
    for(j=0;j<dim;j++){
        freccol[j]--;
        frecfil[j]--;
        if(freccol[j]>0){
            sum+=freccol[j];
        }
        if(frecfil[j]>0){
            sum+=frecfil[j];
        }
    }

    return sum;
}

// Calculamos la energía de una configuración, la cual definimos por el número de números repetidos en fila y columna
int energy(System config){
    int i, energy;
    energy=0;

    for(i=0;i<dim;i++){
        energy+= rep_num_filcol(config.sudoku,i);
    }

    return energy;
}