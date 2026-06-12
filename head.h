#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Definimos constantes
#define dim 9
#define N_ITER 100000



//Definimos structs

typedef struct{
    int val;
    bool fixed_num;
} Matcomp;

typedef struct {
    Matcomp mat[dim][dim];
} Sudoku;

typedef struct {
    float energy;
    Sudoku sudoku;
    float beta_initial;
    float beta_final;
    int termalization_steps;    
} System;


// Sublagoritmos de random.c
extern int rand_int_19 ();

// Sublagoritmos de energy.c
extern int rep_num_filcol(Sudoku sudoku, int filcol);
extern int energy(System config);