#ifndef _DETERMINANTS_H_
#define _DETERMINANTS_H_

#include <stdio.h>
#include "mat_io.h"

typedef struct{
    double *list;
    int size;
}double_arr;

void free_d_arr(double_arr *in); /*Zwalnia double_arr*/

double_arr *get_determ(matrix *in); /*tworzy wyznaczniki macierzy*/

int solve_determ(double_arr *in); /*Rozwiazuje rownanie z pomoca wyznacznikow oraz zwalnia wyznaczniki*/

#endif
