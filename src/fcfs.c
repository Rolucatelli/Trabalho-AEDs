#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/fila.h"

void fcfs()
{
    int processosCriados = 0;
    no *f = NULL, *r = NULL;

    // Considera-se cada loop do while como uma iteração
    while (1)
    {
        if (tentarCriarProcesso()) // Se criar um processo
        {
            no *processoAtual = alocarNo(&processosCriados); // Aloca um novo nó
            inserirFila(&f, &r, processoAtual);              // Insere o nó na fila por meio da função inserirFila

            printf("\033[0;34mProcesso %d de tamanho %d criado!\033[0m\n", processoAtual->id, processoAtual->tamanho);
        }
    
        if (f != NULL) // Se o processo ainda não tiver acabado, f (primeiro da fila) não será NULL
        {
            printf("Processo %d executando...\n", f->id);
            printf("Tamanho restante: %d\n", f->tamanho);
            sleep(1);
            f->tamanho--;        // Diminui o tamanho do processo em uma iteração, já que cada loop do while é uma iteração
            if (f->tamanho == 0) // Se o processo acabou (ou quando o processo acabar)
            {
                printf("\033[0;32mProcesso %d finalizado!\033[0m\n", f->id);
                removerFila(&f, &r); // Remove o processo da fila por meio da função removerFila
            }
        }
        else
        {
            printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
            sleep(1);
        }
    }
}