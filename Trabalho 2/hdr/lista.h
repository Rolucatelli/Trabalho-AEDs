#ifndef _H_LISTA
#define _H_LISTA

// Colocar o cabecalho das funções aqui
void buscarLista(no *ptlista, int x, no **ant, no **pont);
no *inserirLista(no *ptlista, no *novo_no);
no *removerLista(no *ptlista, int x);
void imprimirLista(no *ptlista);

#endif