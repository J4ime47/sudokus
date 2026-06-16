#include "head.h"
#include <stdbool.h>

/*
Returns an uniform int in [1,9] or,actually [1,10)
*/
int rand_int_19 (){
    //Recordamos a+(b-a)*rand/((double)RAND_MAX+1);
    return uniform_int(1,10);
}

/*
Returns an uniform real in interval [0,1)
*/
double fran(){
    return rand()/((double)RAND_MAX+1);
}

/*
Returns an uniform int in [a,b)
*/
int uniform_int(int a, int b){
    return (int)(a + (b-a)*rand()/((double)RAND_MAX+1));
}

   