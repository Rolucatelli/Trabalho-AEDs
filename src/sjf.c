#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"

void sjf(){ 

    int Processos = 0, tamanho = 0;                                         //Variável que será responsável em contar quantos processos foram criados.
    no *primeiro = NULL;                                                    //Variável para o primeiro processo e para o último processo, respectivamente.

    while(1){                                                               //While para 'contabilizar' a quantidade de interações que foram processadas.
        if(ProcessoFoiCriado()){                                            //Condição para verificar se um processo foi criado na interação.
            no * processoGerado = alocarNo(&Processos);                     //Alocando esse processo em processos criados.
            inserirLista(&Processos, &processoGerado);                      //Inserindo esse processo na fila na última posição.
            printf("\033[0;34m Processo gerado: %d.\033[0m\n", processoGerado->id);
            printf("\033[0;34m Tamanho do processo: %d.\033[0m\n",processoGerado->tamanho);
        }
                                                                        
        if(primeiro != NULL){                                               //Verificação se o processo ainda não terminou.
            printf("Processo ainda em execução, interações restasntes: %d.\n", primeiro->tamanho);
            tamanho++;
            primeiro->tamanho--;                                            //Redução no tamanho da quantidade de interações do processo.
            if(primeiro->tamanho == 0){                                     //Verificação se o processo foi finalizado. Quando for, o tamanho do processo será igual a 0.
                printf("\033[0;32m Processo: %d foi finalizado com sucesso!\033[0m\n", primeiro->id);
                removerLista(&Processos, primeiro->id);                     //Remoção do primeiro processo após ter sido realizado.
                if(tamanho < primeiro->prox->tamanho || primeiro == NULL){  //if para comparar os tamanhos dos processos.
                    
                }
            }
        }else{
            printf("Nenhum processo foi criado nessa interação.\n");
        }
    }
}