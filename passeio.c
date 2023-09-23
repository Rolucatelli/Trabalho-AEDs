#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "passeio.h"

bool tabuleiroNaoCheio(bool **tabuleiro, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!tabuleiro[i][j])
            {
                return true;
            }
}

bool movPossivel(int *x, int *y, int n, int m, bool **tabuleiro)
{
    n = m = 8;
    bool possivel = false;
    int newX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int newY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++)
    {
        int u = *x + newX[i], v = *y + newY[i];
        if (0 <= u && u < n && 0 <= v && v < m && !tabuleiro[u][v])
        {
            tabuleiro[u][v] = true;

            // Alterando a posição do cavalo
            *x = u;
            *y = v;

            // Apenas para sair do laço for
            i = 8;

            // Indicando que o movimento é possível
            possivel = true;
        }
    }
    return possivel;
}

// Implementar o trabalho aqui
void computa_passeios(bool **tabuleiro, int n, int m)
{
    int x = 0, y = 0;
    int fechados = 0, abertos = 0;
    // bool possivel = true;
    bool movPos = movPossivel(&x, &y, n, m, tabuleiro);
    bool passeioCompleto = false;

    // Considerando que o Cavalo começe o jogo na casa a1 ou no [0][0]
    tabuleiro[0][0] = 1;

    while (movPos || tabuleiroNaoCheio(tabuleiro, n, m))
    {
        // Implementar uma pilha com o histórico de movimentos do cavalo
        if (movPos)
        {
            movPos = movPossivel(&x, &y, n, m, tabuleiro);
        }
        else
        {
            // tirar um item da pilha
            movPos = movPossivel(&x, &y, n, m, tabuleiro);
        }
    }

    printf("%d\n%d\n", fechados, abertos);
    return;
}

int main(int argc, char *argv[])
{
    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// void Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = -1;
    instancia_num = atoi(argv[1]);
    if (instancia_num <= 0 || instancia_num > 20)
    {
        printf("Para executar o código, digite ./passeio x\nonde x é um número entre 1 e 20 que simboliza a instância utilizada\n");
        exit(0);
    }

    // Criando variáveis que representam as dimensoes do tabuleiro
    int n, m;

    // Tabuleiro do jogo
    bool **tabuleiro = ler_instancia(instancia_num, &n, &m);

    computa_passeios(tabuleiro, n, m);

    return (1);
}

bool **ler_instancia(int instancia_num, int *n, int *m)
{
    int i;

    // Montando o caminho para a instancia
    char *arquivo_instancia = "./instancias/";
    asprintf(&arquivo_instancia, "%s%d", arquivo_instancia, instancia_num);

    // Ponteiro para a instância
    FILE *file;

    // Abrindo a instância em modo leitura
    file = fopen(arquivo_instancia, "r");

    if (NULL == file)
    {
        printf("Arquivo de instância não encontrado. Verifique se sua estrutura de diretórios está EXATAMENTE igual ao do Github\n");
        exit(0);
    }

    // Lendo o arquivo da instância
    fscanf(file, "%d", n);
    fscanf(file, "%d", m);

    // Alocando o tabuleiro dinamicamente
    // Usando calloc ao invés de malloc para inicializar todo o tabuleiro com zeros
    bool **tabuleiro = (bool **)calloc(*n, sizeof(bool *));
    for (i = 0; i < *n; i++)
    {
        tabuleiro[i] = (bool *)calloc(*m, sizeof(bool));
    }

    return tabuleiro;
}