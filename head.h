#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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
    int energy;
    Sudoku sudoku;
    double beta_initial;
    double beta_final;
    int termalization_steps;
    double beta_step;    
} System;


// Sublagoritmos de random.c
extern int rand_int_19 ();
extern double fran();

// Sublagoritmos de energy.c
extern int rep_num_filcol(Sudoku sudoku, int filcol);
extern int energy(Sudoku sudoku);


// Subalgoritmos de matrix.c
extern void copy_sudoku(Sudoku *inicial, Sudoku *final);
extern void print_sudoku(Sudoku sudoku);
extern void set_fixed(Sudoku *sudoku);

//Subalgoritmos de metropolis.c
extern void change (Sudoku initial_sudoku, Sudoku *final_sudoku);
extern void initialize_sudoku(Sudoku *sudoku);
extern void metropolis_step (System *system, Sudoku candidate,double beta);
