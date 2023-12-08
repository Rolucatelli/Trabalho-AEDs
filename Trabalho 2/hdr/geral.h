#ifndef _H_GERAL
#define _H_GERAL

// Colocar o cabecalho das funções aqui
typedef struct no_
{
    int id;
    int tamanho;
    struct no_ *prox;
} no;

int gerarNumeroAleatorio();
int tentarCriarProcesso();
no *alocarNo(int *processosCriados);
void lerMenu(int *opcao);
int criarProcessoManual();

#endif