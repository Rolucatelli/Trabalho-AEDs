#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/fila.h"

void fcfs()
{
    int iteracoesTotal = 0, processosCriados = 0;
    no *f = NULL, *r = NULL;

    while (1)
    {
        if (tentarCriarProcesso()) // Se criar um processo
        {
            r = alocarNo(&processosCriados);
            processosCriados++;

            printf("Processo %d criado com tamanho %d\n", r->id, r->tamanho);

            printf("O processo %d está em execução\n", r->id);
            while (iteracoesTotal < r->tamanho)
            {
                iteracoesTotal++;
            }
            printf("Processo %d finalizado\n", r->id);
            printf("Iterações totais: %d\n", iteracoesTotal);

            // Avança para o próximo nó na fila, se existir
            if (r->prox != NULL)
            {
                // Avança para o próximo nó na fila
                r = r->prox;
            }
            else
            {
                // Remove o processo da fila e libera a memória
                removerFila(&f, &r);
                free(r);
            }
        }
        else
        {
            printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
            sleep(5);
        }
    }
    printf("Foram criados %d processos\n", processosCriados);
}
