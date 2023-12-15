#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"

void sjf(int delay)
{

    int processosCriados = 0;
    limparArquivo("exe/logs/sjfLog");
    no *ptLista = malloc(sizeof(no)); // Criando uma ptlista para alocar os processos.
    ptLista->prox = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        FILE *arquivo = fopen("exe/logs/sjfLog", "a");
        no *primeiroNo = ptLista->prox;
        if (tentarCriarProcesso()) // Se criar um processo
        {
            no *processoAtual = alocarNo(&processosCriados); // Aloca um novo nó
            inserirListaFim(ptLista, processoAtual);         // Insere o nó na fila por meio da função inserirFila

            printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
            fprintf(arquivo, "\n\tProcesso %d de tamanho %d criado!\n\n", processoAtual->id, processoAtual->tamanho);
        }

        if (primeiroNo != NULL) // Se o processo ainda não tiver acabado, f (primeiro da fila) não será NULL
        {
            printf("Processo %d executando...\n", primeiroNo->id);
            fprintf(arquivo, "Processo %d executando...\n", primeiroNo->id);

            printf("Tamanho restante: %d\n", primeiroNo->tamanho);
            fprintf(arquivo, "Tamanho restante: %d\n", primeiroNo->tamanho);

            sleep(delay);
            primeiroNo->tamanho--;        // Diminui o tamanho do processo em uma iteração, já que cada loop do while é uma iteração
            if (primeiroNo->tamanho == 0) // Se o processo acabou (ou quando o processo acabar)
            {
                printf("\033[0;32mProcesso %d finalizado!\033[0m\n", primeiroNo->id);
                fprintf(arquivo, "\n==================== Processo %d finalizado! ====================\n\n", primeiroNo->id);
                sleep(delay);
                removerLista(ptLista, primeiroNo->id); // Remove o processo da fila por meio da função removerFila
                ordenaListaTam(&ptLista);
            }
        }
        else
        {
            printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
            fputs("Nenhum processo criado, aguarde até que outro processo seja criado\n", arquivo);

            sleep(delay);
        }

        fclose(arquivo);
    }
}
