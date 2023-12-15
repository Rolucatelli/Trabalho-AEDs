#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/fila.h"

void fcfs(int delay)
{
    int processosCriados = 0;
    limparArquivo("fcfsLog"); 
    no *f = NULL, *r = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        FILE *arquivo = fopen("fcfsLog", "a");
        if (tentarCriarProcesso()) // Se criar um processo
        {
            no *processoAtual = alocarNo(&processosCriados); // Aloca um novo nó
            inserirFila(&f, &r, processoAtual);              // Insere o nó na fila por meio da função inserirFila

            printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
            fprintf(arquivo, "\tProcesso %d de tamanho %d criado!\n", processoAtual->id, processoAtual->tamanho);
            
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
                fprintf(arquivo, "Processo %d finalizado!\n", f->id);
                sleep(delay);

                removerFila(&f, &r); // Remove o processo da fila por meio da função removerFila
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