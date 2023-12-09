#ifndef _H_FILA
#define _H_FILA

// Colocar o cabecalho das funções aqui

#include "../hdr/geral.h"

void inserirFila(no **f, no **r, no *novoNo);

no *removerFila(no **f, no **r);

void imprimirFila(no *inicio);

#endif