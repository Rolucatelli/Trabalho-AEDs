#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"

void sjf()
{
    int iTotal = 0, processosCriados = 0;
    no *ptlista = malloc(sizeof(no));
    ptlista->prox = NULL;
    int numeroProcessos = criarProcessoManual();
    for (int i = 0; i < numeroProcessos; i++)
    {
        no *temp = alocarNo(&processosCriados);
        inserirLista(ptlista, temp);
    }
    while (ptlista != NULL)
    {
        no *processo = removerLista(ptlista, ptlista->prox->id);
        while (processo->tamanho > 0)
        {
            iTotal++;
            processo->tamanho--;
        }
        printf("Processo %d terminado!\n", processo->id);
        printf("Iterações executadas: %d\n\n", iTotal);
        if (tentarCriarProcesso())
        {
            no *novoProcesso = alocarNo(&processosCriados);
            ptlista = inserirLista(ptlista, novoProcesso);
            printf("\n\n=====================================\n");
            printf("Processo %d de tamanho %d criado!\n", novoProcesso->id, novoProcesso->tamanho);
            printf("=====================================\n\n\n");
        }
        imprimirLista(ptlista);
    }
}