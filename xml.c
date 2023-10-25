/*
+-------------------------------------------------------------+
| UNIFAL – Universidade Federal de Alfenas.                   |
| BACHARELADO EM CIENCIA DA COMPUTACAO.                       |
| Trabalho..: Validacao de arquivos XML                       |
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

typedef char *string;
typedef struct no_
{
    string info;
    struct no *prox;
} no;

void inserir(no **topo, no *novoNo)
{
    novoNo->prox = *topo;
    *topo = novoNo;
}

no *remover(no **topo)
{
    if (*topo != NULL)
    {
        no *retorno = *topo;
        *topo = retorno->prox;
        return retorno;
    }
    return NULL;
}

int tamString(string texto){
    int i = 0;
    while (texto[i] != '\0')
    {
        i++;
    }
    return i;
}

string concatena(string string1, string string2){
    int tam1 = tamString(string1);
    int tam2 = tamString(string2);
    int tam3 = tam1 + tam2;
    string string3 = malloc(tam3 * sizeof(char));
    int i = 0;
    while (i < tam1)
    {
        string3[i] = string1[i];
        i++;
    }
    int j = 0;
    while (j < tam2)
    {
        string3[i] = string2[j];
        i++;
        j++;
    }
    return string3;
}

string removePrimeiroChar(string string1){
    int tam1 = tamString(string1);
    string string2 = malloc((tam1-1) * sizeof(char));
    int i = 1;
    while (i < tam1)
    {
        string2[i-1] = string1[i];
        i++;
    }
    return string2;
}

void imprimir(no *topo)
{
    if (topo == NULL)
    {
        printf("pilha vazia");
        return;
    }

    printf("topo --> \n");
    while (topo != NULL)
    {
        printf("\t%d", topo->info);
        topo = topo->prox;
        printf("\n \t| \n");
    }
    printf("\tNULL\n");
}

no *criarNo(string info)
{
    no *novoNo = malloc(sizeof(no));
    novoNo->info = info;
    novoNo->prox = NULL;
    return novoNo;
}

int main()
{
    no *topo = NULL;
    FILE *arquivo;
    // string nomeArquivo;
    // printf("Informe o nome do arquivo: ");
    // scanf("%s", nomeArquivo);
    // concatena("./", nomeArquivo);
    arquivo = fopen("./entrada.xml", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    
    
    




    fclose(arquivo);


    return 0;
}
