#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Definimos constantes
#define dim 9
#define N_ITER 10000000

//Definimos colores
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANS_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_RESET   "\x1b[0m"

extern int arr[dim];   //Declaramos variable global que contendrá los valores de los numeros prefijados para cada subcaja

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
    int termalization_steps;
    double beta_step;    
} System;


// Sublagoritmos de random.c
extern int rand_int_19 ();
extern double fran();
extern int uniform_int(int a, int b);

// Sublagoritmos de energy.c
extern int rep_num_fil(Sudoku sudoku, int fil);
extern int rep_num_col(Sudoku sudoku, int col);
extern int energy(Sudoku sudoku);
extern int delta_E(Sudoku sudoku,Sudoku candidate, int *icords, int *jcords);


// Subalgoritmos de matrix.c
extern void copy_sudoku(Sudoku inicial, Sudoku *final);
extern void print_sudoku(Sudoku sudoku);
extern void set_fixed(Sudoku *sudoku,int *num_unfixed);
extern void show_fixed(int ibox, int jbox, Sudoku *sudoku,int *nums);
extern bool in_array (int *v,int N, int num);
extern void print_solution(Sudoku sudoku);

//Subalgoritmos de metropolis.c
extern void change (Sudoku initial_sudoku, Sudoku *final_sudoku, int *icords, int *jcords);
extern void initialize_sudoku(Sudoku *sudoku);
extern void metropolis_step (System *system,Sudoku candidate, double beta, int *admitidos, int deltaE);

//Subalgoritmos de utils.c
extern void wait();
