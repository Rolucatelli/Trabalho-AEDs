#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "passeio.h"

bool allTheMovs(int historico[], int n, int m)
{
    for (int i = 0; i < n * m; i++)
        if (historico[i] != 0)
            return true;
    return false;
}

void voltarMov(bool **tabuleiro, int historico[], int *ultimoMov, int *x, int *y)
{
    int newX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int newY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    historico[*ultimoMov] = 0;
    tabuleiro[*x][*y] = false;
    (*ultimoMov)--;
    if (*ultimoMov < 0)
    {
        return;
    }

    *x -= newX[historico[*ultimoMov]];
    *y -= newY[historico[*ultimoMov]];
    historico[*ultimoMov]++;
}

bool tabuleiroNaoCheio(bool **tabuleiro, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!tabuleiro[i][j])
                return true;
    return false;
}

bool tabuleiroVazio(bool **tabuleiro, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (tabuleiro[i][j])
                return false;
    return true;
}

bool movPossivel(int *x, int *y, int n, int m, bool **tabuleiro, int historico[], int *ultimoMov)
{
    // pilha no;
    int newX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int newY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // ultimoMov != -1
    for (int i = historico[*ultimoMov]; i < 8; i++)
    {
        int u = *x + newX[i], v = *y + newY[i];
        historico[*ultimoMov] = i;
        if (0 <= u && u < n && 0 <= v && v < m && !tabuleiro[u][v])
        {
            tabuleiro[u][v] = true;
            *ultimoMov += 1;

            // Alterando a posição do cavalo
            *x = u;
            *y = v;

            // Indicando que o movimento é possível
            return true;
        }
    }

    if (historico[29] == 7)
    {
        historico[29] = 7;
    }
    return false;
}

// Implementar o trabalho aqui
void computa_passeios(bool **tabuleiro, int n, int m)
{
    // pilha historico[n * m];
    // historico[0].i = 0;
    // int topo = 0;

    int historico[(n * m)];
    int ultimoMov = 0;
    for (int i = 0; i < m * n; i++)
        historico[i] = 0;

    int x = 0, y = 0;
    int fechados = 0, abertos = 0;

    // Considerando que o Cavalo começe o jogo na casa a1 ou no [0][0]

    bool movPos = movPossivel(&x, &y, n, m, tabuleiro, historico, &ultimoMov);

    while (!tabuleiroVazio(tabuleiro, n, m))
    {
        while ((movPos || tabuleiroNaoCheio(tabuleiro, n, m)) && !tabuleiroVazio(tabuleiro, n, m))
        {
            // Implementar uma pilha com o histórico de movimentos do cavalo
            if (movPos)
            {
                movPos = movPossivel(&x, &y, n, m, tabuleiro, historico, &ultimoMov);
            }
            else
            {
                voltarMov(tabuleiro, historico, &ultimoMov, &x, &y);
                movPos = movPossivel(&x, &y, n, m, tabuleiro, historico, &ultimoMov);
            }
        }

        if (x == 0 && y == 0)
        {
            fechados++;
        }
        else
        {
            abertos++;
        }
        voltarMov(tabuleiro, historico, &ultimoMov, &x, &y);
        movPos = movPossivel(&x, &y, n, m, tabuleiro, historico, &ultimoMov);
    }

    printf("%d\n%d\n", fechados, abertos);
    return;
}

int main(int argc, char *argv[])
{
    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = 1;
    // instancia_num = atoi(argv[1]);
    // if (instancia_num <= 0 || instancia_num > 20)
    // {
    //     printf("Para executar o código, digite ./passeio x\nonde x é um número entre 1 e 20 que simboliza a instância utilizada\n");
    //     exit(0);
    // }

    // Criando variáveis que representam as dimensoes do tabuleiro
    int n, m;

    // Tabuleiro do jogo
    bool **tabuleiro = ler_instancia(instancia_num, &n, &m);

    // printf("\n%d\n%d", n, m);

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