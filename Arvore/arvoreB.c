/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvoreB.c
 * Author: IzabelyFurtado
 *
 * Created on 5 de Julho de 2016, 20:12
 */

#include <stdio.h>
#include <stdlib.h>
//#include <util.h>
#include <arvoreB.h>

/*
 * 
 */

#define ORDEM 5 //árvore de ordem 5
#define ORDEM_MIN 1

// Criando a enumeração de booleano:

struct arvoreb {
    short int totalChaves; //armazena numero de chaves na pagina
    int chaves[ORDEM - 1]; //vetor de chaves
    struct arvoreb filhas[ORDEM]; //Ponteiros das páginas filas, -1 aponta para NULL
};

typedef struct arvoreb ArvoreB;

//----------------------------------CRIA----------------------------------------

//Criação vazia

ArvoreB* arvb_cria() {
    ArvoreB nova = (ArvoreB*) malloc(sizeof (ArvoreB));
    nova->totalChaves = 0;
    //inicializa filhos com NULL
    for (int i = 0; i ORDEM; i++) {
        nova->filhas[i] = NULL;
    }
    return nova;
}

//BUSCA

ArvoreB* arvb_busca(int elemento, ArvoreB* ponteiroRaiz) {
    if (ponteiroRaiz == -1) {
        return NULL;
    } else {
        //carrega em memória primaria pagina apontando por ponteiroRaiz
        //procura k na pagina carregada
        //se (k foi encontrada)
        if (existe(ponteiroRaiz->filhas, elemento)) {
            //return chave encontrada
            return ponteiroRaiz->chaves;
        } else {
            //ponteiro = ponteiro para a próxima página da possível ocorrência de k
            ponteiroRaiz = ponteiroRaiz->filhas;
            return (arvb_busca(elemento, ponteiroRaiz));
        }
    }
}

//--------------------------------INSEÇÃO---------------------------------------

//Insere uma chave e o ponteiro para o filho da direita em um nó

void insere_chave(ArvoreB *raiz, int chave, ArvoreB *filhodir) {
    int chave, posicao;
    ArvoreB* arvore; //caso exista elemento

    //se a chave nao existir na arvore
    arvore = busca_binaria_arvore(raiz, chave);
    if (arvore != NULL) {
        //chave ja esta na arvore
        printf("Houve um erro, chave %d já existente na arvore", chave);
    }        //se a chave ainda nao existir
    else {
        //busca para obter a posição ideal para inserir a nova chave
        posicao = busca_binaria_local(raiz->chaves, raiz->totalChaves, chave);

        chave = raiz->totalChaves;

        //realiza o remanejamento para manter as chaves ordenadas
        while (chave > posicao && chave < raiz->chaves[chave - 1]) {
            raiz->chaves[chave] = raiz->chaves[chave - 1];
            raiz->filhas[chave + 1] = raiz->filhas[chave];
            chave--;
        }

        //insere a chave na posição ideal
        raiz->chaves[posicao] = chave;
        raiz->filhas[posicao + 1] = filhodir;
        raiz->totalChaves++;
    }
}

//Realiza a busca do nó para inserir a chave e faz as subdivisões quando necessárias

ArvoreB* insere(ArvoreB* raiz, int info, bool altura, int info_retorno) {
    int i, j, pos;
    int info_mediano; //auxiliar para armazenar a chave que irá subir para o pai
    ArvoreB *temp, *filho_dir; //ponteiro para o filho à direita da chave 

    if (raiz == NULL) {
        //O nó anterior é o ideal para inserir a nova chave (chegou em um nó folha)
        altura = true;
        info_retorno = info;
        return (NULL);
    } else {
        pos = busca_binaria(raiz, info);
        if (raiz->totalChaves > pos && raiz->chaves[pos] == info) {
            printf("Chave já contida na Árvore");
            altura = false;
        } else {
            //desce na árvore até encontrar o nó folha para inserir a chave.
            filho_dir = insere(raiz->filhas[pos], info, altura, info_retorno);
            if (altura) //Se true deve inserir a info_retorno no nó.
            {
                if (raiz->totalChaves < ORDEM) //Tem espaço na página
                {
                    insere_chave(raiz, info_retorno, filho_dir);
                    altura = false;
                } else { //Overflow. Precisa subdividir
                    temp = arvb_cria()

                            //elemento mediano que vai subir para o pai
                            info_mediano = raiz->chaves[ORDEM_MIN];

                    //insere metade do nó raiz no temp (efetua subdivisão)
                    temp->filhas[0] = raiz->filhas[ORDEM_MIN + 1];
                    for (i = ORDEM_MIN + 1; i < ORDEM; i++)
                        insere_chave(temp, raiz->chaves[i], raiz->filhas[i + 1]);

                    //atualiza nó raiz. 
                    for (i = ORDEM_MIN; i < ORDEM; i++) {
                        raiz->chaves[i] = 0;
                        raiz->filhas[i + 1] = NULL;
                    }
                    raiz->totalChaves = ORDEM_MIN;

                    //Verifica em qual nó será inserida a nova chave
                    if (pos <= ORDEM_MIN)
                        insere_chave(raiz, info_retorno, filho_dir);
                    else insere_chave(temp, info_retorno, filho_dir);

                    //retorna o mediano para inserí-lo no nó pai e o temp como filho direito do mediano.
                    info_retorno = info_mediano;
                    return (temp);
                }
            }
        }
    }
}

ArvoreB* insere_arvoreB(ArvoreB* raiz, int info) {
    bool altura;
    int info_retorno;
    ArvoreB *filho_dir, *nova_raiz;

    filho_dir = insere(raiz, info, altura, info_retorno);
    if (altura) { //Aumetará a altura da árvore
        nova_raiz = arvb_cria();
        nova_raiz->totalChaves = 1;
        nova_raiz->chaves[0] = info_retorno;
        nova_raiz->filhas[0] = raiz;
        nova_raiz->filhas[1] = filho_dir;
        return (nova_raiz);
    } else return (raiz);
}


//BUSCA

Encontrado* busca_binaria_arvore(ArvoreB* arvore, int chave) {
    bool encontrado = false;
    Encontrado retorno = (Encontrado*) malloc sizeof ((Encontrado*));
    if (arvore == NULL) {
        printf("Elemento não existe - Arvore Vazia");
    } 
    else {
        int indice = busca_binaria_local(arvore->chaves, arvore->totalChaves, chave);

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
}

//REMOÇÃO

void arvb_remove(ArvoreB* arvore, int chave) {
    bool encontrado = false;
    int indice = busca_binaria_arvore(arvore->chaves, arvore->totalChaves, chave);

    //até que o elemento seja encontrado ou não se tenha mais filhos
    while (encontrado == true) {
        if (arvore->chaves[indice] < chave) {
            arvore = arvore->filhaEsquerda;
            if (arvore != NULL) {
                indice = busca_binaria_arvore(arvore->chaves, arvore->totalChaves, chave);
            } else {
                printf("Elemento não existe");
                break;
            }
        } else if (arvore->chaves[indice] > chave) {
            arvore = arvore->filhaDireita;
            if (arvore != NULL) {
                indice = busca_binaria_arvore(arvore->chaves, arvore->totalChaves, chave);

            } else {
                printf("Elemento não existe");
                break;
            }
        } else {
            //REALOCAR TODOS OS FILHOS OU DELETAR?????

            free(arvore->filhas);
            encontrado = true;
        }
    }
}

/*
//IMPRIMIR EM ORDEM EM C
void emOrdem (tpaginaB raiz) {
        if(raiz==NULL)
                return;
        for(int i=0;i<raiz.n,i++)
                emOrdem(raiz->pont[i]);
                printf("%i",raiz->chv[i]);
        }
        emOrdem(raiz->pont[raiz.n]);
}

 */
int main(int argc, char** argv) {

    return (EXIT_SUCCESS);
}

