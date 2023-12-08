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
|             Leonardo Bonardi Marques Silva                  |
| Data......: 15/09/2023                                      |
+-------------------------------------------------------------+
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../hdr/fcfs.h"
#include "../hdr/fila.h"
#include "../hdr/lista.h"
#include "../hdr/roundRobin.h"
#include "../hdr/sjf.h"
#include "../hdr/geral.h"


int main()
{
    int opcao = 1;
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
        fcfs();
    }
    else if (opcao == 2)
    {
        // Shortest Job First
        sjf();
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
