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

// Definindo string como um vetor de char
typedef char *string;

// Definindo um nó
typedef struct no_
{
    string info;
    struct no *prox;
} no;

/*
    Essa função insere um nó na pilha
    @param **topo: é o ponteiro do topo da pilha
    @param *novoNo: é o novo nó a ser inserido na pilha
*/
void inserir(no **topo, no *novoNo)
{
    novoNo->prox = *topo;
    *topo = novoNo;
}

/*
    Essa função remove o último nó da pilha
    @param **topo: é o topo da pilha
*/
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

/*
    Essa função verifica e retorna o tamanho de uma string
    @param texto: é a string a qual será verificada o tamanho
*/
int tamString(string texto)
{
    int i = 0;
    while (texto[i] != '\0')
    {
        i++;
    }
    return i;
}

/*
    Essa função junta duas strings em uma
    @param string1: é a primeira string, ou seja, o comeco da nova string
    @param string2: é a segunda string, ou seja, o fim da nova string
*/
string concatena(string string1, string string2)
{
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

/*
    Essa função remove o primeiro caractere de uma string
    @param string1: string que terá o primeiro caractere removido
*/
string removePrimeiroChar(string string1)
{
    int tam1 = tamString(string1);
    string string2 = malloc((tam1 - 1) * sizeof(char));
    int i = 1;
    while (i < tam1)
    {
        string2[i - 1] = string1[i];
        i++;
    }
    return string2;
}

/*
    Essa função cria um nó
    @param info: o conteúdo do nó
*/
no *criarNo(string info)
{
    no *novoNo = malloc(sizeof(no));
    novoNo->info = info;
    novoNo->prox = NULL;
    return novoNo;
}

// Essa função lê um arquivo
FILE *lerArquivo()
{
    string nomeArquivo = malloc(100 * sizeof(char));
    printf("Informe o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    nomeArquivo = concatena("../", nomeArquivo);
    return fopen(nomeArquivo, "r");
}

int main()
{
    no *topo = NULL;
    FILE *arquivo = lerArquivo();
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        printf("Verifique se o nome do arquivo está correto e se ele está na mesma pasta do programa.\n");
        printf("O nome do arquivo deve conter a extensão\n");
        return 1;
    }

    string linha = malloc(100 * sizeof(char));
    int linhaAtual = 0;

    //Enquanto o arquivo não termina
    while (!feof(arquivo))
    {
        //Leio uma linha
        fgets(linha, 100, arquivo);
        //Aumento a contagem de linhas
        linhaAtual++;
        
        
    }

    fclose(arquivo);

    return 0;
}
