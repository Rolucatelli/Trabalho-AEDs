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
    struct no_ *prox;
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
    // Pegando o tamanho das strings
    int tam1 = tamString(string1);
    int tam2 = tamString(string2);

    // Definindo o tamanho da nova string
    int tam3 = tam1 + tam2;

    // Declarando a nova string
    string string3 = malloc((tam3) * sizeof(char));

    int i = 0;
    // Adicionando a primeira string à nova string
    while (i < tam1)
    {
        string3[i] = string1[i];
        i++;
    }
    
    int j = 0;
    // Adicionando a segunda string à nova string
    while (j < tam2 + 1)
    {
        string3[i] = string2[j];
        i++;
        j++;
    }
    // Retornando a nova string
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
    string2[i - 1] = '\0';
    return string2;
}

/*
    Essa função verifica se uma string está contida na outra (s2 dentro de s1)
    @param s1: string que contém
    @param s2: string contida
*/
int contido(string s1, string s2)
{
    int tam1 = tamString(s1);
    int tam2 = tamString(s2);
    for (int i = 0; i < tam1; i++)

        if (s1[i] == s2[0])
        {
            int j = 0;
            while (j < tam2)
            {

                if (s1[i + j] == s2[j])
                {
                    j++;
                    if (j == tam2)
                        return 1;
                }
                else
                    break;
            }
        }

    return 0;
}

/*
    Essa função verifica se as strings são diferentes, retornando 1 caso sejam
    @param s1: string 1
    @param s2: string 2
*/
int stringsDiferentes(string s1, string s2)
{
    int tam1 = tamString(s1);
    int tam2 = tamString(s2);
    if (tam1 != tam2)
    {
        return 1;
    }
    for (int i = 0; i < tam1; i++)
    {
        if (s1[i] != s2[i])
        {
            return 1;
        }
    }
    return 0;
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

/*
    Essa função pega uma tag da linha e a remove
    @param *linha: um ponteiro para a linha porque a linha será alterada
*/
string pegarTag(string *linha)
{
    int tamLinha = tamString(*linha);
    int i = 0;
    int tamTag = 0;
    while ((*linha)[i] != '<')
    {
        i++;
    }
    i++;
    while ((*linha)[i] != '>')
    {
        i++;
        tamTag++;
    }
    string tag = malloc((tamTag + 1) * sizeof(char));
    int k = 0;
    for (int j = i - tamTag; j < i; j++)
    {
        tag[k] = (*linha)[j];
        k++;
    }
    i++;
    int j;
    for (j = 0; j < tamLinha - i; j++)
    {
        (*linha)[j] = (*linha)[j + i];
    }
    (*linha)[j] = '\0';
    tag[k] = '\0';

    return tag;
}

// Essa função lê um arquivo
FILE *lerArquivo()
{
    string nomeArquivo = malloc(100 * sizeof(char));
    printf("Informe o nome do arquivo: ");
    scanf("%s", nomeArquivo);
    nomeArquivo = concatena("../", nomeArquivo); // Caso vá debugar o código, colocar "./" no lugar de "../"
    return fopen(nomeArquivo, "r");
}

int main()
{
    no *topo = NULL;
    FILE *arquivo;
    arquivo = lerArquivo();
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        printf("Verifique se o nome do arquivo está correto e se ele está na mesma pasta do programa.\n");
        printf("Lembrete: o nome do arquivo deve conter a extensão\n");
        return 1;
    }

    string linha = malloc(100 * sizeof(char));
    int linhaAtual = 0;
    

    // Enquanto o arquivo não termina
    while (!feof(arquivo))
    {
        // Leio uma linha
        fgets(linha, 100, arquivo);
        // Aumento a contagem de linhas
        linhaAtual++;

        while (contido(linha, ">"))
        {
            string tag = pegarTag(&linha);
            if (tag[0] != '/')
            {
                inserir(&topo, criarNo(tag));
            }
            else
            {
                no *noRemovido = remover(&topo);
                if (noRemovido == NULL)
                {
                    printf("\n Erro na linha %d: tag de fechamento sem tag de abertura correspondente!", linhaAtual);
                    return 1;
                }

                string tagRemovida = noRemovido->info;
                tag = removePrimeiroChar(tag);

                if (stringsDiferentes(tag, tagRemovida))
                {
                    printf("\n Erro na linha %d: tag de fechamento sem tag de abertura correspondente!", linhaAtual);
                    return 1;
                }

                free(noRemovido);
            }
        }
    }
    no *temp = remover(&topo);
    if (temp != NULL)
    {
        printf("\n Erro na linha %d: a tag <%s> não foi fechada!", linhaAtual, temp->info);
        return 1;
    }

    printf("\n O arquivo está correto!");
    fclose(arquivo);

    return 0;
}
