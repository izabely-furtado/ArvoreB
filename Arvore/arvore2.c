/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
#include <stdio.h>
#include <stdlib.h>

#define N 3

struct arv3 {
    char info;
    struct no *f[N];
};

typedef struct arv3 Arv3;

void arv3_imprime (Arv3* a){
    if (a != NULL){
        int i;
        printf("<%c", a->info);
        for (i=0; i<N; i++){
            arv3_imprime(a->f[i]);
        }
        printf(">");
    }
}
 * */