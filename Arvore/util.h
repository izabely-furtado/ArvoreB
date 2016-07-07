/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   util.h
 * Author: IzabelyFurtado
 *
 * Created on 6 de Julho de 2016, 16:09
 */

#ifndef UTIL_H
#define UTIL_H

//retorna indice onde foi encontrado o elemento no vetor
int busca_binaria(int vet[], int tamVet, int elemento);

int busca_binaria_arvore(int vet[], int tamVet, int elemento);

//EXISTE?
bool existe(ArvoreB* arv, int k);

#endif /* UTIL_H */

