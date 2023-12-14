#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"

int gerarNumeroAleatorio()
{
    int numero = (rand() % 20) + 1; // Gera um número aleatório entre 1 e 20
    return numero;
}

int tentarCriarProcesso()
{
    int numero = gerarNumeroAleatorio();
    if (numero <= 6)
    {
        return 1;
    }
    return 0;
}

no *alocarNo(int *processosCriados)
{
    no *retorno = malloc(sizeof(no));
    (*processosCriados)++;
    retorno->id = *processosCriados;
    retorno->tamanho = gerarNumeroAleatorio();
    retorno->prox = NULL;
    return retorno;
}

void lerMenu(int *opcao, int *delay)
{

    printf("=====================================\n");
    printf("Escolha o tempo, em segundos, entre mensagens:\n");
    printf("(Caso não queira um tempo de espera, digite 0)\n");
    scanf("%d", delay);
    printf("=====================================\n");
    printf("Escolha um método de escalonamento:\n");
    printf("0 - Sair\n");
    printf("1 - First Come, First Served\n");
    printf("2 - Shortest Job First\n");
    printf("3 - Round Robin\n");
    scanf("%d", opcao);
    printf("=====================================\n");
}

void limparArquivo(char *arquivo)
{
    FILE *temp = fopen(arquivo, "w+");
    fprintf(temp, "");
    fclose(temp);
}