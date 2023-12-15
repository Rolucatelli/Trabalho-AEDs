#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"
#define QUANTUM 6

void roundRobin(int delay)
{
    // Objetivos: criar uma função que simule o escalonamento de processos pelo método Round Robin
    // Essa função deve ficar em loop infinito, sendo interrompida somente se o usuário der CTRL+C no terminal
    int processosCriados = 0;
    limparArquivo("roundRobinLog");
    no *ptLista = malloc(sizeof(no));
    ptLista->prox = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        FILE *arquivo = fopen("roundRobinLog", "a");
        no *primeiroNo = ptLista->prox;

        for (int i = 0; i < QUANTUM; i++)
        {
            primeiroNo = ptLista->prox;

            if (tentarCriarProcesso()) // Se criar um processo
            {
                if (ptLista->prox == NULL)
                    i = 0;
                no *processoAtual = alocarNo(&processosCriados); // Aloca um novo nó
                inserirListaFim(ptLista, processoAtual);         // Insere o nó na fila por meio da função inserirFila

                printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
                fprintf(arquivo, "\tProcesso %d de tamanho %d criado!\n", processoAtual->id, processoAtual->tamanho);
                primeiroNo = ptLista->prox;
            }

            if (primeiroNo != NULL) // Se o processo ainda não tiver acabado, f (primeiro da fila) não será NULL
            {
                printf("Processo %d executando...\n", primeiroNo->id);
                fprintf(arquivo, "Processo %d executando...\n", primeiroNo->id);

                printf("Tamanho restante: %d\n", primeiroNo->tamanho);
                fprintf(arquivo, "Tamanho restante: %d\n", primeiroNo->tamanho);

                sleep(delay);
                primeiroNo->tamanho--; // Diminui o tamanho do processo em uma iteração, já que cada loop do while é uma iteração

                if (primeiroNo->tamanho == 0) // Se o processo acabou (ou quando o processo acabar)
                {
                    printf("\033[0;32mProcesso %d finalizado!\033[0m\n", primeiroNo->id);
                    fprintf(arquivo, "Processo %d finalizado!\n", primeiroNo->id);
                    sleep(delay);
                    break;
                }
            }
            else
            {
                printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
                fprintf(arquivo, "Nenhum processo criado, aguarde até que outro processo seja criado\n");

                sleep(delay);
            }
        }

        if (primeiroNo != NULL)
        {
            primeiroNo = removerLista(ptLista, primeiroNo->id);
            if (primeiroNo->tamanho != 0)
            {
                inserirListaFim(ptLista, primeiroNo);
            }
        }

        fclose(arquivo);
    }
}