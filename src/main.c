#include <stdio.h>
#include <stdlib.h>

#include "determinants.h"
#include "mat_io.h"


int main(int argc, char **argv){
    int i;
    matrix *matr;
    double_arr *arr;
    FILE *f;

    for(i=1; i<argc; i++){
        f = fopen(argv[i], "r");
        if(f!=NULL){
            matr = make_matrix(f);
            fclose(f);
            if(matr!=NULL){
                show_matr(matr);
                arr = get_determ(matr);
                if(arr!=NULL)
                    solve_determ(arr);
            }
            free_matr(matr);
        } else
            printf("%s: %s nie istnieje\n\n", argv[0], argv[i]);
    }
    return 0;
}
