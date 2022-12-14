#include "mat_io.h"

#include <stdio.h>
#include <stdlib.h>

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
