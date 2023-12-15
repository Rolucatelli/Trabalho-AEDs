#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"

void buscarLista(no *ptlista, int x, no **ant, no **pont)
{
    *pont = NULL;
    *ant = ptlista;
    no *ptr = ptlista->prox;

    while (ptr != NULL)
    {
        if (ptr->id < x)
        {
            *ant = ptr;
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->id == x)
            {
                *pont = ptr;
            }
            ptr = NULL; // break;
        }
    }
}

void buscarListaTamanho(no *ptlista, int x, no **ant, no **pont)
{
    *pont = NULL;
    *ant = ptlista;
    no *ptr = ptlista->prox;

    while (ptr != NULL)
    {
        if (ptr->tamanho < x)
        {
            *ant = ptr;
            ptr = ptr->prox;
        }
        else
        {
            if (ptr->tamanho == x)
            {
                *pont = ptr;
            }
            ptr = NULL; // break;
        }
    }
}

void inserirListaTamanho(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscarListaTamanho(ptlista, novo_no->tamanho, &ant, &pont);
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
}

void inserirListaId(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscarLista(ptlista, novo_no->id, &ant, &pont);
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
}

void inserirListaFim(no *ptlista, no *novo_no)
{
    no *ant = ptlista;
    while (ant->prox != NULL)
    {
        ant = ant->prox;
    }
    ant->prox = novo_no;
    novo_no->prox = NULL;
}

no *removerLista(no *ptlista, int x)
{
    no *ant, *pont;
    buscarLista(ptlista, x, &ant, &pont);
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

void imprimirLista(no *ptlista)
{
    if (ptlista->prox == NULL)
    {
        printf("<lista vazia!>");
        return;
    }

    ptlista = ptlista->prox;

    printf("Processos restantes: ");
    while (ptlista != NULL)
    {

        printf("%d:%d", ptlista->id, ptlista->tamanho);
        ptlista = ptlista->prox;
        printf(" -> ");
        if (ptlista == NULL)
            printf("NULL");
    }
}

// void trocarNos(no *ptLista, no *no1, no *no2)
// {
//     no *ant1, *ant2;
//     buscarLista(ptLista, no1->id, &ant1, &no1);
//     buscarLista(ptLista, no2->id, &ant2, &no2);

//     no *temp = no1->prox;
//     no1->prox = no2->prox;
//     no2->prox = temp;
//     ant2->prox = no1;
//     ant1->prox = no2;   


// }
// void ordenaLista(no *ptLista)
// {

// }