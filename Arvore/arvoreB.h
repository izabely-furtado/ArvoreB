/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arvoreB.h
 * Author: IzabelyFurtado
 *
 * Created on 6 de Julho de 2016, 16:12
 */

#ifndef ARVOREB_H
#define ARVOREB_H
#include <util.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
Flag arvb_insere(ArvoreB* ponteiroRaiz, int chave, int chavePromovida) {
    int posicao, espaco;
    Flag retorno = chaveNPromovida;

    if (ponteiroRaiz == -1) { //se ponteiroRaiz nao aponta para nenhuma pagina
        chavePromovida = chave;
        printf("Houve promoção da chave %d", chavePromovida); //return(flag que indica que houve promoção de chave)
        retorno = chavePromovida;
    } else {
        //carregue a página P apontada por ponteiroRaiz em memoria primária
        //procura por key na pagina P
        //posicao = página no qual key poderia estar 
        posicao = ponteiroRaiz->filhas;
    }
    //se a chave foi encontrada
    if (existe(ponteiroRaiz, chave)) {
        //chave ja esta na arvore
        printf("Houve um erro, chave %d já existente na arvore", chave);
        retorno = chaveJaExiste;
    }

    retorno = arvb_insere(posicao, chave, chavePromovida); //procedimento recursivo

    if (retorno == chaveNPromovida || retorno == chaveJaExiste) {
        return retorno;
    }        //se há espaço na página P para chavePromovida
    else if (espaco > chavePromovida) {
        //insere chavePromovida na página P
        //escreve página P em arquivo
        return chavePromovida;
    }        //se nao há espaço para a chave
    else {
        //realize operação de split em P
        //escreva em arquivo  a nova página e a página P
        return chavePromovida;
    }

}
*/
    /*
//BUSCA
Busca(k, ponteiroRaiz) 
{
	se(ponteiroRaiz == -1)
	{
		return (chave nao encontrada)
	}
	senao
	{
		carrega em memoria primaria pagina apontado por ponteiroRaiz
		procura k na pagina carregada
		se(k foi encontrada)
		{
			return (chave encontrada)
		}
		senao
		{
			ponteiro = ponteiro para a próxima página da possível ocorrência de k
			return (Busca (k, ponteiro))
		}
	}
}
*/

    
    
/*
//INSERÇÃO
Inserçao(ponteiroRaiz, key, chavePromovida)
{
	se(ponteiroRaiz == -1)//se ponteiroRaiz nao aponta para nenhuma pagina
	{
		chavePromovida = key
		return(flag que indica que houve promoção de chave)
	}
	senao
	{
		carregue a página P apontada por ponteiroRaiz em memoria primária
		busque por key nessa página P
		posicao = página no qual key poderia estar 
	}
	
	se(key foi encontrada)
	{
		//chave ja esta na arvore, retorne uma flag de erro
		return(flag de erro)
	}
	
	flagRetorno = Inserçao(posicao, key, chavePromovida)//procedimento recursivo
	
	se(flagRetorno indica que nao houve promoçao de chave ou que ocorreu um erro)
	{
		return(conteudo de flagRetorno)
	}
	senao se(há espaço na página P para chavePromovida)
	{
		insere chavePromovida na página P
		escreve página P em arquivo
		return(flag que indica que nao houve promocao de chave)
	}
	senao //nao ha espaço em P para key
	{
		realize operação de split em P
		escreva em arquivo  a nova página e a página P
		return(flag que indica que houve promoçao de chave)
	}	
}
*/

    
    /*

//REMOÇÃO
Busque a chave k
 Busque a menor chave M na página folha da sub-árvore à direita de k
 Se a chave k não está numa folha
 {	
  Substitua k por M
 }
 Apague a chave k ou M da página folha
 Se a página folha não sofrer underflow
 {
 	 fim do algoritmo
 }
 Se a página folha sofrer underflow, verifique as páginas irmãs da página folha
 {
    Se uma das páginas tiver um número maior do que o mínimo redistribua as chaves
    Senão concatene as páginas com uma de suas irmãs e a chave pai separadora
 }
 Se ocorrer concatenação de páginas aplique o trecho das linhas 8 até 17 para a página pai da folha



#ifdef __cplusplus
}
#endif

#endif /* ARVOREB_H */

