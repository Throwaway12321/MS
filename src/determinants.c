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

    if(in->m!=in->n){
        printf("Macierz nie jest kwadratowa\n\n");
        free(exit->list);
        free(exit);
        free(d_pos);
        free(d_neg);
        return NULL;
    }

    if(in->m==1){
        exit->list[1]=in->list[0];
        exit->list[0]=in->solutions[0];
        free(d_pos);
        free(d_neg);
        return exit;
    } else if(in->m==2){
        exit->list[2]=in->list[0]*in->list[3]-in->list[1]*in->list[2];
        exit->list[0]=in->solutions[0]*in->list[3]-in->list[1]*in->solutions[1];
        exit->list[1]=in->solutions[1]*in->list[0]-in->list[2]*in->solutions[0];
        free(d_pos);
        free(d_neg);
        return exit;
    } else if(in->m==0){
        printf("Blad: macierz zerowa\n\n");
        free(exit->list);
        free(exit);
        free(d_pos);
        free(d_neg);
        return NULL;
    }

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

void free_d_arr(double_arr *in){
    free(in->list);
    free(in);
}

int solve_determ(double_arr *in){
    int i;
    if(!in->list[in->size-1]){
        printf("Wyznacznik macierzy jest rowny 0\n\n");
        return 1;
    }

    for(i=0; i<in->size-1; i++)
        printf("x%d=%f\n", i+1, in->list[i]/in->list[in->size-1]);
    printf("\n");
    free_d_arr(in);
    return 0;
}
