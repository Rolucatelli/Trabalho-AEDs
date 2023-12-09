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

void inserirLista(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscarLista(ptlista, novo_no->id, &ant, &pont);
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
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