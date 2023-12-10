#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/fila.h"

void fcfs()
{
    // Objetivos: criar uma função que simule o escalonamento de processos pelo método First Come, First Served
    // Essa função deve ficar em loop infinito, sendo interrompida somente se o usuário der CTRL+C no terminal

    int iteracoesTotal = 0, processosCriados = 0;
    no *f = NULL, *r = NULL;
    int numeroProcessos = tentarCriarProcesso(processosCriados);
    if (numeroProcessos == 0) // Se não foi possível criar nenhum processo, encerra a função
    {
        printf("Não foi possível criar nenhum processo.\n");
        return;
    }
    // Se chegou aqui, é porque foi possível criar pelo menos um processo
    for (int i = 0; i < numeroProcessos; i++) // Cria os processos e os insere na fila
    {
        inserirFila(&f, &r, alocarNo(&processosCriados));
    }
    while (1) // Loop Infinito
    {
        no *processoAtual = removerFila(&f, &r);
        if (processoAtual == NULL) // Se não há mais processos na fila, encerra a função
        {
            printf("Não há mais processos na fila.\n");
            return;
        }
        while (processoAtual->tamanho > 0) // Executa o processo (um por vez) até que ele seja concluído
        {
            iteracoesTotal++;
            processoAtual->tamanho--;
        }
        printf("O processo %d foi concluído.\n", processoAtual->id); //Já saiu do while, então o processo foi concluído
        printf("Iterações totais executadas: %d\n", iteracoesTotal); // Exibe o total de iterações executadas
        printf("==============================================\n");
        
        // Agora, ao final da iteração haverá chance de 30% de criar um novo processo
        if (tentarCriarProcesso()) // Se conseguiu criar
        {
            no *novoProcesso = alocarNo(&processosCriados); // Aloca o novo processo
            inserirFila(&f, &r, novoProcesso); // Insere o novo processo na fila
            printf("O processo %d, com tamanho %d foi criado.\n", novoProcesso->id, novoProcesso->tamanho);
        }
    }
}