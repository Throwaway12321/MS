#include "determinants.h"

#include <stdio.h>
#include <stdlib.h>
#include "mat_io.h"

double_arr *get_determ(matrix *in){
    double_arr *exit = malloc(sizeof(double_arr));
    double *d_pos=malloc((in->n+1)*sizeof(double)), *d_neg=malloc((in->n+1)*sizeof(double));
    int i, j, n, row, c_pos, c_neg;

    exit->list=calloc((in->n+1), sizeof(double));

    exit->size = in->n+1;


    for(i=0; i<=in->m; i++){
        d_neg[i]=1;
        d_pos[i]=1;
    }

    for(j=0; j<in->m; j++){
        for(i=0; i<in->m; i++){

            row = i*in->m;

            c_pos = (j+i)%in->m;
            c_neg = (j-i+in->m)%in->m;

            for(n=0; n<=in->m; n++){
                if(c_pos==n)
                    d_pos[n] *= in->solutions[i];
                else
                    d_pos[n] *= in->list[row+c_pos];

                if(c_neg==n)
                    d_neg[n] *= in->solutions[i];
                else
                    d_neg[n] *= in->list[row+c_neg];
            }

        }
        for(n=0; n<=in->m; n++){
            exit->list[n]+=d_pos[n]-d_neg[n];
            d_pos[n]=1;
            d_neg[n]=1;
        }
    }

    free(d_pos);
    free(d_neg);
    return exit;
}
