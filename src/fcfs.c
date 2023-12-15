#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/fila.h"

void fcfs(int delay)
{
    int processosCriados = 0;
    // Se existir algo no arquivo, a função vai apagar
    limparArquivo("exe/logs/fcfsLog");
    no *f = NULL, *r = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        // Abrindo o arquivo de log
        FILE *arquivo = fopen("exe/logs/fcfsLog", "a");
        if (tentarCriarProcesso()) // Se criar um processo
        {
            no *processoAtual = alocarNo(&processosCriados); // Aloca um novo nó
            inserirFila(&f, &r, processoAtual);              // Insere o nó na fila por meio da função inserirFila

            printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
            fprintf(arquivo, "\n\tProcesso %d de tamanho %d criado!\n\n", processoAtual->id, processoAtual->tamanho);
        }

        if (f != NULL) // Se o processo ainda não tiver acabado, f (primeiro da fila) não será NULL
        {
            printf("Processo %d executando...\n", f->id);
            fprintf(arquivo, "Processo %d executando...\n", f->id);

            printf("Tamanho restante: %d\n", f->tamanho);
            fprintf(arquivo, "Tamanho restante: %d\n", f->tamanho);

            sleep(delay);
            f->tamanho--;        // Diminui o tamanho do processo em uma iteração, já que cada loop do while é uma iteração
            if (f->tamanho == 0) // Se o processo acabou (ou quando o processo acabar)
            {
                printf("\033[0;32mProcesso %d finalizado!\033[0m\n", f->id);
                fprintf(arquivo, "\n==================== Processo %d finalizado! ====================\n\n", f->id);
                // Esperando o tempo
                sleep(delay);

                removerFila(&f, &r); // Remove o processo da fila por meio da função removerFila
            }
        }
        else
        {
            printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
            fputs("Nenhum processo criado, aguarde até que outro processo seja criado\n", arquivo);

            // Esperando o tempo
            sleep(delay);
        }

        // Fecha o arquivo para salvar o que foi escrito
        fclose(arquivo);
    }
}