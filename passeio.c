#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "passeio.h"

bool historicoZerado(int historico[], int n, int m)
{
    for (int i = 0; i < (n * m) + 1; i++)
        if (historico[i] != 0)
            return false;
    return true;
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

bool tabuleiroCheio(bool **tabuleiro, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!tabuleiro[i][j])
                return false;
    return true;
}

void voltarMov(bool **tabuleiro, int historico[], int *ultimoMov, int *x, int *y)
{
    int newX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int newY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    historico[*ultimoMov] = 0;
    tabuleiro[*x][*y] = false;
    (*ultimoMov)--;
    *x -= newX[historico[*ultimoMov]];
    *y -= newY[historico[*ultimoMov]];
    historico[*ultimoMov]++;
}

void executaMov(int *x, int *y, bool **tabuleiro, int *historico, int *ultimoMov)
{

    int newX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int newY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    *x += newX[historico[*ultimoMov]];
    *y += newY[historico[*ultimoMov]];
    tabuleiro[*x][*y] = true;
    *ultimoMov += 1;
}

bool movPossivel(int *x, int *y, int n, int m, bool **tabuleiro, int *historico, int *ultimoMov)
{

    int newX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int newY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = historico[*ultimoMov]; i < 8; i++)
    {
        // Essas variáveis representam um possível pŕoximo movimento
        int u = *x + newX[i];
        int v = *y + newY[i];

        // Isso armazena qual movimento será testado
        historico[*ultimoMov] = i;

        // Isso verifica se esse próximo movimento está dentro do tabuleiro ou se o cavalo ja não passou por lá
        if (0 <= u && u < n && 0 <= v && v < m && !tabuleiro[u][v])
        {
            return true;
        }  
    }

    return false;
}

// Implementar o trabalho aqui
void computa_passeios(bool **tabuleiro, int n, int m)
{
    // Definindo variáveis para contar os passeios
    int fechados = 0, abertos = 0;

    // A posição do cavalo, que começam zeradas, pois ele está no canto do tabuleiro
    int x = 0, y = 0;
    tabuleiro[0][0] = true;

    // Esse vetor registra todos os movimentos feitos pelo passeio
    int historico[n * m];

    // Isso será o índice do vetor acima, que indicará qual foi o ultimo movimento feito pelo cavalo
    int ultimoMov = 0;

    // Preenchendo o vetor com 0 para, futuramente, testar todos os movimentos
    for (int i = 0; i < n*m; i++)
    {
        historico[i] = 0;
    }

    while (!historicoZerado(historico, n, m) || tabuleiro[0][0]) // Enquanto todos os caminhos possíveis ainda não foram executados
    {
        while (movPossivel(&x, &y, n, m, tabuleiro, historico, &ultimoMov) || tabuleiroNaoCheio(tabuleiro, n, m))
        {
            if (movPossivel(&x, &y, n, m, tabuleiro, historico, &ultimoMov))
            {
                executaMov(&x, &y, tabuleiro, historico, &ultimoMov);
            }
            else
            {
                voltarMov(tabuleiro, historico, &ultimoMov, &x, &y);
            }
        }

        if (tabuleiroCheio(tabuleiro, n, m))
        {
            if (x == 0 && y == 0)
            {
                fechados++;
            }
            else
            {
                abertos++;
            }
        }
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