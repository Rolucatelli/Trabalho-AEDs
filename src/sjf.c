#include <stdio.h>
#include <stdlib.h>
#include "../hdr/geral.h"
#include "../hdr/lista.h"

void sjf(int delay){ 

    // Objetivos: criar uma função que simule o escalonamento de processos pelo método Round Robin
    // Essa função deve ficar em loop infinito, sendo interrompida somente se o usuário der CTRL+C no terminal

    int processosCriados = 0, tamanho = 0;                                  //Variável que será responsável em contar quantos processos foram criados e outra variável para contar o tamanho.
    limparArquivo("exe/logs/sjfLog");
    no *ptlista = malloc(sizeof(no));                                       //Criando uma ptlista para alocar os processos.
    ptlista->prox = NULL;

    while(1){                                                               //While para 'contabilizar' a quantidade de interações que foram processadas.
        FILE *arquivo = fopen("exe/logs/sjfLog", "a");
        no *noatual = ptlista->prox;                                        //Variável para o nó atual;
        for(int i = 0; i < noatual->tamanho; i++){
            if(tentarCriarProcesso()){                                      //Condição para verificar se um processo foi criado na interação.
                no *processoGerado = alocarNo(&processosCriados);           //Alocando esse processo em processos criados.
                inserirListaFim(ptlista, processoGerado);                   //Inserindo esse processo na fila na última posição.
                printf("\033[0;34m Processo gerado: %d.\033[0m\n", processoGerado->id);
                printf("\033[0;34m Tamanho do processo: %d.\033[0m\n",processoGerado->tamanho);
            }
                                                                        
            if(noatual != NULL){                                            //Verificação se o processo ainda não terminou.
                printf("Processo ainda em execução, interações restasntes: %d.\n", noatual->tamanho);
                noatual->tamanho--;                                         //Redução no tamanho da quantidade de interações restantes do processo.
                tamanho++;                                                  //Variável para saber o tamanho do processo.
                sleep(delay);
                if(noatual->tamanho == 0){                                  //Verificando se o processo chegou ao fim.
                    printf("\033[0;32m Processo: %d foi finalizado com sucesso!\033[0m\n", noatual->id);
                    removerLista(ptlista, noatual->id);                     //Se terminou, retira da listas de processos.
                    break;
                }
            }else{                                                          //Else para caso não ocorra nenhuma criação de um novo processo na interação. 
                printf("Nenhum processo foi criado nessa interação.\n");
                sleep(delay);
            }
        }

        if(noatual != NULL){                                                //Verificão se ocorreu interação.
            no *aux = ptlista->prox;                                        //Variável auxiliar ao processo de ordenação.
            no *ant = ptlista;                                              //Variável responsável por saber o nó anterior à incrementação.
            while(tamanho > aux->tamanho || aux != NULL){                   //Enquanto o tamanho do no atual for maior do que o nó na fila, acontecerá incrementação.
                ant = aux;                                                  //Incrementação.
                aux = aux->prox;                                            //Incrementação.
            }
            ant->prox = noatual;                                            //Ordenando o processo na fila.
            noatual->prox = aux;                                            //Ordenando o processo na fila.
        }

        fclose(arquivo);
    }
}
