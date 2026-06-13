#include "head.h"
#include <stdbool.h>

/*
Devuelve un numero plano entero en el intervalo [1,9], o entre [1,10) mejor dicho.
*/
int rand_int_19 (){
    //Recordamos a+(b-a)*rand/((double)RAND_MAX+1);
    return (int)(1 + 9*rand()/((double)RAND_MAX+1));
}

double fran(){
    return rand()/((double)RAND_MAX+1);
}

   