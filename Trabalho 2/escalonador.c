#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarNumeroAleatorio() {
    srand(time(0)); // use current time as seed for random generator
    int numero = rand() % 20 + 1; // generate a number between 1 and 20
    return numero;
}

int tentarCriarProcesso() {
    int numero = gerarNumeroAleatorio();
    if (numero <= 6) {
        return 1;
    }
    return 0;
}




typedef struct no_
{
    int chave;
    int valor;
    struct no_ *prox;
} no;

void inserirFila(no **f, no **r, no *novoNo)
{
    if (*r == NULL)
    {
        *f = *r = novoNo;
    }
    else
    {
        (*r)->prox = novoNo;
        *r = novoNo;
    }
}

no *removerFila(no **f, no **r)
{
    no *retorno = NULL;
    if (*f != NULL)
    {
        retorno = *f;
        *f = retorno->prox;
        if (*f == NULL)
        {
            *r = *f;
        }
    }
    return retorno;
}

no *inserirLista(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscar(ptlista, novo_no->chave, &ant, &pont);
    if (pont == NULL)
    {
        novo_no->prox = ant->prox;
        ant->prox = novo_no;
        return NULL;
    }
    return pont;
}

no *removerLista(no *ptlista, int x)
{
    no *ant, *pont;
    buscar(ptlista, x, &ant, &pont);
    if (pont != NULL)
    {
        ant->prox = pont->prox;
        return pont;
    }
    else
    {
        return NULL;
    }
}

no *alocarNo()
{
    no *retorno = malloc(sizeof(no));
    printf("Informe a chave: ");
    scanf("%d", &retorno->chave);
    printf("Informe o valor: ");
    scanf("%d", &(*retorno).valor);
    retorno->prox = NULL;
    return retorno;
}

void lerMenu(int *opcao)
{
    printf("=====================================\n");
    printf("escolha um método de escalonamento:\n");
    printf("1 - First Come, First Served\n");
    printf("2 - Shortest Job First\n");
    printf("3 - Round Robin\n");
    scanf("%d", &opcao);
    printf("=====================================\n");
}

int main()
{
    int opcao = 1;
    while (opcao != 0)
    {
        lerMenu(&opcao);
        if (opcao == 0)
        {
            // Sair do programa
        }
        else if (opcao == 1)
        {
            // First Come, First Served
        }
        else if (opcao == 2)
        {
            // Shortest Job First
        }
        else if (opcao == 3)
        {
            // Round Robin
        }
    }

    return 0;
}
