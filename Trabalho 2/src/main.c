/*
+-------------------------------------------------------------+
| UNIFAL – Universidade Federal de Alfenas.                   |
| BACHARELADO EM CIENCIA DA COMPUTACAO.                       |
| Trabalho..: Métodos de Escalonamento                        |
| Disciplina: Algoritmos e Estrutura de Dados II – Pratica    |
| Professor.: Fellipe Rey                                     |
| Aluno(s)..: Rodrigo Luís Gasparino Lucatelli                |
|             José Olavo Monteiro Travassos Pereira da Silva  |
|             João Felipe Martins Santana                     |
| Data......: 15/09/2023                                      |
+-------------------------------------------------------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    @brief Gera um número aleatório entre 1 e 20

    @return Número aleatório entre 1 e 20

*/
int gerarNumeroAleatorio()
{
    int numero = (rand() % 20) + 1; // generate a number between 1 and 20
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

typedef struct no_
{
    int id;
    int tamanho;
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

void imprimirFila(no *inicio)
{
    if (inicio == NULL)
    {
        printf("Sem processos na fila!\n");
        return;
    }

    printf("Processos restantes: ");
    while (inicio != NULL)
    {
        printf("%d:%d", inicio->id, inicio->tamanho);
        inicio = inicio->prox;
        if (inicio != NULL)
            printf(" -> ");
    }
    printf("\n");
}

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

no *inserirLista(no *ptlista, no *novo_no)
{
    no *ant, *pont;
    buscarLista(ptlista, novo_no->id, &ant, &pont);
    novo_no->prox = ant->prox;
    ant->prox = novo_no;
    return NULL;
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

no *alocarNo(int *processosCriados)
{
    no *retorno = malloc(sizeof(no));
    (*processosCriados)++;
    retorno->id = *processosCriados;
    retorno->tamanho = gerarNumeroAleatorio();
    retorno->prox = NULL;
    return retorno;
}

void lerMenu(int *opcao)
{
    printf("=====================================\n");
    printf("Escolha um método de escalonamento:\n");
    printf("0 - Sair\n");
    printf("1 - First Come, First Served\n");
    printf("2 - Shortest Job First\n");
    printf("3 - Round Robin\n");
    scanf("%d", opcao);
    printf("=====================================\n");
}

int criarProcessoManual()
{
    int qntd;
    printf("=====================================\n");
    printf("Digite quantos processos deseja criar inicialmente: ");
    scanf("%d", &qntd);
    printf("=====================================\n");
    return qntd;
}

int main()
{
    int opcao = 1, iTotal = 0, processosCriados = 0;
    srand(time(NULL));

    lerMenu(&opcao);

    if (opcao == 0)
    {
        // Sair do programa
        printf("Saindo do programa...\n");
    }
    else if (opcao == 1)
    {
        // First Come, First Served

        no *f = NULL, *r = NULL;
        int numeroProcessos = criarProcessoManual();
        for (int i = 0; i < numeroProcessos; i++)
        {
            inserirFila(&f, &r, alocarNo(&processosCriados));
        }
        while (f != NULL)
        {
            no *processo = removerFila(&f, &r);
            while (processo->tamanho > 0)
            {
                iTotal++;
                processo->tamanho--;
            }
            printf("Processo %d terminado!\n", processo->id);
            printf("Iterações executadas: %d\n\n", iTotal);
            if (tentarCriarProcesso())
            {
                no *novoProcesso = alocarNo(&processosCriados);
                inserirFila(&f, &r, novoProcesso);
                printf("\n\n=====================================\n");
                printf("\tProcesso %d de tamanho %d criado!\n", novoProcesso->id, novoProcesso->tamanho);
                printf("=====================================\n\n\n");
            }
            imprimirFila(f);
            free(processo);
        }
    }
    else if (opcao == 2)
    {
        // Shortest Job First

        no *ptlista = malloc(sizeof(no));
        ptlista->prox = NULL;
        int numeroProcessos = criarProcessoManual();
        for (int i = 0; i < numeroProcessos; i++)
        {
            no *temp = alocarNo(&processosCriados);
            inserirLista(ptlista, temp);
        }
        while (ptlista != NULL)
        {
            no *processo = removerLista(ptlista, ptlista->prox->id);
            while (processo->tamanho > 0)
            {
                iTotal++;
                processo->tamanho--;
            }
            printf("Processo %d terminado!\n", processo->id);
            printf("Iterações executadas: %d\n\n", iTotal);
            if (tentarCriarProcesso())
            {
                no *novoProcesso = alocarNo(&processosCriados);
                ptlista = inserirLista(ptlista, novoProcesso);
                printf("\n\n=====================================\n");
                printf("Processo %d de tamanho %d criado!\n", novoProcesso->id, novoProcesso->tamanho);
                printf("=====================================\n\n\n");
            }
            imprimirLista(ptlista);
        }
    }
    else if (opcao == 3)
    {
        // Round Robin
    }
    else
    {
        printf("Opção inválida!\n");
    }
    return 0;
}
