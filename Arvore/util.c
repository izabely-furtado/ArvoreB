/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <util.h>

enum boolean {
    true = 1, false = 0
};
// Permitindo a sua declaração como um tipo qualquer:
typedef enum boolean bool;

//criando enumeração de flags

enum flag {
    chavePromovida = 3, chaveNPromovida = 4, chaveJaExiste = 5
};

typedef enum flag Flag;

enum direcao {
    esquerda = -3, meio = -2, direita = -1
};

typedef enum direcao Direcao;

struct encontrado {
    ArvoreB* local;
    int indice;
    bool encontrou;
};

typedef encontrado Encontrado;

//retorna indice onde foi encontrado o elemento no vetor

int busca_binaria(int vet[], int tamVet, int elemento) {
    /* Loop que ira realizar a pesquisa binaria */
    int meio, indice;
    int inicio = 0;
    int fim = tamVet - 1;
    while (inicio <= fim) {
        //Obtem o meio do vetor 
        meio = (inicio + fim) / 2;
        //se elemento > meio
        if (elemento > vet[meio]) {
            inicio = meio + 1;
        }            //se elemento < meio
        else if (elemento < vet[meio]) {
            fim = meio - 1;
        }            //se o elemento foi encontrado
        else {
            return indice;
        }
    }
    //caso nao tenha sido encontrado
    return -1;
}

//retorna indice onde foi encontrado o elemento no vetor

int busca_binaria_local(int vet[], int tamVet, int elemento) {
    /* Loop que ira realizar a pesquisa binaria */
    int meio;
    int inicio = 0;
    int fim = tamVet - 1;
    while (inicio <= fim) {
        //Obtem o meio do vetor 
        meio = (inicio + fim) / 2;
        //se elemento > meio
        if (elemento > vet[meio]) {
            if (elemento < vet[meio + 1]) {
                return meio;
            }
            inicio = meio + 1;
        }            //se elemento < meio
        else if (elemento < vet[meio]) {
            if (elemento > vet[meio + 1]) {
                return meio;
            }
            fim = meio - 1;
        }            //se o elemento foi encontrado
        else {
            return meio;
        }
    }
    //caso nao tenha sido encontrado dentro = deve ser inserido no final
    return -1;
}

//retorna indice onde foi encontrado o elemento no vetor
//retorna arvore onde a chave esta que deve ser avaliado

Encontrado* busca_binaria_arvore(ArvoreB* arvore, int chave) {
    bool encontrado = false;
    int indice = busca_binaria_local(arvore->chaves, arvore->totalChaves, chave);
    Encontrado retorno = (Encontrado*) malloc sizeof ((Encontrado*));

    //até que o elemento seja encontrado ou não se tenha mais filhos
    while (arvore->chaves[indice] != chave) {
        if (arvore->chaves[indice] < chave) {
            arvore = arvore->filhas[indice - 1]; //pegando filha a esquerda;
            if (arvore != NULL) {
                indice = busca_binaria_local(arvore->chaves, arvore->totalChaves, chave);
            } else {
                printf("Elemento %d não existe \n", chave);
                retorno->encontrou = false;
                retorno->indice = indice;
                retorno->local = arvore;
                return retorno;
            }
        } else {
            arvore = arvore->filhas[indice + 1]; //pegando filha a direita;
            if (arvore != NULL) {
                indice = busca_binaria_local(arvore->chaves, arvore->totalChaves, chave);
            } else {
                printf("Elemento %d não existe \n", chave);
                retorno->encontrou = false;
                retorno->indice = indice;
                retorno->local = arvore;
                return retorno;
            }
        }
    }
    //se elemento existe naquele nivel da arvore
    retorno->encontrou = encontrado;
    retorno->local = arvore;
    retorno->indice = indice;
    encontrado = true;
    return arvore[indice];
}




//EXISTE?

bool existe(ArvoreB* arv, int k) {

    return true;
}



