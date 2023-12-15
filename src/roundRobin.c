#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"
#define QUANTUM 6

void roundRobin(int delay)
{
    int processosCriados = 0;

    // Se existir algo no arquivo, a função vai apagar
    limparArquivo("exe/logs/roundRobinLog");

    // Criando a estrutura de lista
    no *ptLista = malloc(sizeof(no));
    ptLista->prox = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        // Abrindo o arquivo de log
        FILE *arquivo = fopen("exe/logs/roundRobinLog", "a");
        no *primeiroNo = ptLista->prox;

        // Contando o tempo de um Quantum
        for (int i = 0; i < QUANTUM; i++)
        {
            // Atualizando o primeiroNo
            primeiroNo = ptLista->prox;

            // Se criar um processo
            if (tentarCriarProcesso())
            {
                // Se for o primeiro processo, reseta o Quantum
                if (ptLista->prox == NULL)
                    i = 0;
                // Aloca um novo nó
                no *processoAtual = alocarNo(&processosCriados); 
                // Insere o nó no fim da lista
                inserirListaFim(ptLista, processoAtual);         

                printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
                fprintf(arquivo, "\n\tProcesso %d de tamanho %d criado!\n\n", processoAtual->id, processoAtual->tamanho);

                // Atualizando o primeiroNo
                primeiroNo = ptLista->prox;
            }

            // Se houver algum processo na lista
            if (primeiroNo != NULL)
            {
                printf("Processo %d executando...\n", primeiroNo->id);
                fprintf(arquivo, "Processo %d executando...\n", primeiroNo->id);

                printf("Tamanho restante: %d\n", primeiroNo->tamanho);
                fprintf(arquivo, "Tamanho restante: %d\n", primeiroNo->tamanho);

                // Esperando o tempo
                sleep(delay);
                primeiroNo->tamanho--;

                if (primeiroNo->tamanho == 0)
                {
                    printf("\033[0;32mProcesso %d finalizado!\033[0m\n", primeiroNo->id);
                    fprintf(arquivo, "\n==================== Processo %d finalizado! ====================\n\n", primeiroNo->id);
                    // Esperando o tempo
                    sleep(delay);
                    // Break
                    i = QUANTUM;
                }
            }
            else
            {
                printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
                fprintf(arquivo, "Nenhum processo criado, aguarde até que outro processo seja criado\n");

                sleep(delay);
            }
        }

        // Se houver algum processo na lista
        if (primeiroNo != NULL)
        {

            primeiroNo = removerLista(ptLista, primeiroNo->id);
            // Se o processo ainda não foi terminado
            if (primeiroNo->tamanho != 0)
            {
                inserirListaFim(ptLista, primeiroNo);
            }
        }

        // Fecha o arquivo para salvar o que foi escrito
        fclose(arquivo);
    }
}