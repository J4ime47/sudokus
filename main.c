#include "head.h"

int main(){
    System system;
    Sudoku candidate;
    int i;

    //Inicializamos el sistema
    system.beta_initial=0.0001;
    system.beta_final=1.0;
    system.termalization_steps=1000;
    system.beta_step=0.00001;

    //Inicializamos el sudoku (Uso uno de ejemplo de internet)
    int pregunta[9][9] = {
        {0,3,7,2,0,0,0,0,0},
        {0,0,0,0,7,0,4,0,0},
        {0,2,0,8,0,6,9,7,0},
        {0,0,0,0,0,1,6,5,0},
        {0,0,6,0,0,0,2,0,0},
        {0,4,0,9,0,0,8,0,0},
        {2,5,0,0,0,4,0,9,6},
        {6,0,0,0,0,2,0,0,0},
        {4,7,3,0,0,8,0,2,5}
    };

    
    


    

    return 0;
}