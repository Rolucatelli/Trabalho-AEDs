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

            printf("Processo %d criado com tamanho %d\n", processoAtual->id, processoAtual->tamanho);

            if (f != NULL) // Se o processo ainda não tiver acabado, f (primeiro da fila) não será NULL
            {
                printf("O processo %d está em execução com tamanho %d\n", f->id, f->tamanho);
                sleep(5);
                f->tamanho--; // Diminui o tamanho do processo em uma iteração, já que cada loop do while é uma iteração

                if (f->tamanho == 0) // Se o processo acabou (ou quando o processo acabar)
                {
                    printf("O processo %d foi finalizado\n", f->id);
                    removerFila(&f, &r); // Remove o processo da fila por meio da função removerFila
                }
            }
            else
            {
                printf("Nenhum processo criado, aguarde até que outro processo seja criado\n");
                sleep(5);
            }
        }
    }
}