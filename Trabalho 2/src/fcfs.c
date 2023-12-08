#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"

void fcfs()
{
    int iTotal = 0, processosCriados = 0;
    no *f = NULL, *r = NULL;
    int numeroProcessos = criarProcessoManual();
    for (int i = 0; i < numeroProcessos; i++)
    {
        inserirFila(&f, &r, alocarNo(processosCriados));
    }
    while (f != NULL)
    {
        no *processo = removerFila(&f, &r);
        while (processo->tamanho > 0)
        {
            iTotal++;
            processo->tamanho--;
        }
        printf("Processo %d terminado!\n", processo->id);
        printf("Iterações executadas: %d\n\n", iTotal);
        if (tentarCriarProcesso())
        {
            no *novoProcesso = alocarNo(processosCriados);
            inserirFila(&f, &r, novoProcesso);
            printf("\n\n=====================================\n");
            printf("\tProcesso %d de tamanho %d criado!\n", novoProcesso->id, novoProcesso->tamanho);
            printf("=====================================\n\n\n");
        }
        imprimirFila(f);
        free(processo);
    }
}