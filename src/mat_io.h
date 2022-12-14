#ifndef _MAT_IO_H_
#define _MAT_IO_H_

#include <stdio.h>

typedef struct{
    double *list;
    int m, n;
} matrix;

matrix *make_matrix(FILE *in); /*Tworzy matryce z pliku*/

void free_matr(matrix *in);/*Zwalnia matryce*/

void show_matr(matrix *in);/*Wyswietla elementy matrycy*/


#endif
