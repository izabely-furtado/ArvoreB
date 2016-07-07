/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvvar.c
 * Author: IzabelyFurtado
 *
 * Created on 5 de Julho de 2016, 02:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <arvvar.h>
#include <util.h>

/*
 * 
 */
struct arvvar {
    char info;
    struct arvvar *prim; //ponteiro para eventual primeiro filho
    struct arvvar *prox; //ponteiro para eventual irmao
};

typedef struct arvvar ArvVar;

ArvVar* arvv_cria(char c){
    ArvVar *a = (ArvVar*) malloc(sizeof(ArvVar));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void arvv_insere (ArvVar* a, ArvVar* sa) {
    sa->prox = a->prim;
    a->prim = sa;
}

void arvv_imprime (ArvVar* a){
    ArvVar* p;
    printf("<%c\n", a->info);
    for (p=a->prim; p!=NULL; p=p->prox){
        arvv_imprime(p);
    }
    printf(">");
}

int arvv_pertence (ArvVar* a, char c){
    ArvVar* p;
    if (a->info==c){
        return 1;
    }
    else {
        for (p=a->prim; p!=NULL; p=p->prox){
            if (arvv_pertence(p,c)){
                return 1;
            }
        }
        return 0;
    }
}

void arvv_libera (ArvVar* a){
    ArvVar* p = a->prox;
    while (p!=NULL){
        ArvVar* t = p->prox;
        arvv_libera(p);
        p = t;
    }
    free(a);
}

int arvv_altura (ArvVar* a){
    int hmax = -1; //-1 para tratar caso com zero filhos
    ArvVar* p;
    for (p=a->prim; p!=NULL; p=p->prox){
        int h = arvv_altura(p);
        if (h > hmax){
            hmax = h;
        }
    }
    return hmax + 1;
}

/*
//topologia binária de nós arvores:
    //binaria e 
    //com numero variavel de filhos
static max2 (int a, int b){
    return (a>b) ? a : b;
}

int arvv_altura (ArvVar* a){
    if (a==NULL){
        return -1;
    }
    else{
        return max2(1+arv_altura(a->prim), arvv_altura(a->prox));
    }
}
*/

int main(int argc, char** argv) {
    
    //cria nós como folhas
    ArvVar* a = arvv_cria('a');
    ArvVar* b = arvv_cria('b');
    ArvVar* c = arvv_cria('c');
    ArvVar* d = arvv_cria('d');
    ArvVar* e = arvv_cria('e');
    ArvVar* f = arvv_cria('f');
    ArvVar* g = arvv_cria('g');
    ArvVar* h = arvv_cria('h');
    ArvVar* i = arvv_cria('i');
    ArvVar* j = arvv_cria('j');
    
    //monta a hierarquia
    arvv_insere(c,d);
    arvv_insere(b,e);
    arvv_insere(b,c);
    arvv_insere(i,j);
    arvv_insere(g,i);
    arvv_insere(g,h);
    arvv_insere(a,g);
    arvv_insere(a,f);
    arvv_insere(a,b);
    
    arvv_imprime(a);
    
    return (EXIT_SUCCESS);
}

