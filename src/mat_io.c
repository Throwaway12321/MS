#include "mat_io.h"

#include <stdio.h>
#include <stdlib.h>

matrix *make_matrix(FILE *in){

    int i;
    matrix *exit = malloc(sizeof(*exit));

    if(fscanf(in, "%d %d", &(exit->m), &(exit->n))!=2){
        free(exit);
        return NULL;
    }

    if((exit->list=malloc(exit->m * exit->n * sizeof(double)))==NULL){
        free(exit);
        free(exit->list);
        return NULL;
    }

    if((exit->solutions=malloc(exit->n * sizeof(double)))==NULL){
        free(exit);
        free(exit->solutions);
        free(exit->list);
        return NULL;
    }

    for(i=0; i<exit->m * exit->n; i++)
        if(fscanf(in, "%lf", &exit->list[i])!=1){
            free(exit);
            free(exit->solutions);
            free(exit->list);
            return NULL;
        }

    for(i=0; i<exit->n; i++)
        if(fscanf(in, "%lf", &exit->solutions[i])!=1){
            free(exit);
            free(exit->list);
            free(exit->solutions);
            return NULL;
        }

    return exit;
}

void free_matr(matrix *in){
    free(in->list);
    free(in->solutions);
    free(in);
}

void show_matr(matrix *in){
    int i, j;
    for(i=0; i<in->m; i++){
        for(j=0; j<in->n; j++)
            printf("%f ", in->list[i*in->m+j]);
        printf("| %f\n", in->solutions[i]);
    }
    printf("\n");
}
