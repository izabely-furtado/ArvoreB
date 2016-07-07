/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvvar.h
 * Author: IzabelyFurtado
 *
 * Created on 5 de Julho de 2016, 02:00
 */

#ifndef ARVVAR_H
#define ARVVAR_H

struct arvvar {
    char info;
    struct arvvar *prim; //ponteiro para eventual primeiro filho
    struct arvvar *prox; //ponteiro para eventual irmao
};


ArvVar* arvv_cria (char c);
void    arvv_insere (ArvVar* a, ArvVar* sa);
void    arvv_imprime (ArvVar* a);
void    arvv_pertence (ArvVar* a, char c);
void    arvv_libera (ArvVar* a);
void    arvv_altura (ArvVar* a);


#endif /* ARVORE3_H */

