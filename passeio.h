#ifndef _H_PASSEIO
#define _H_PASSEIO

// Implementar qualquer struct que for necessária aqui

typedef struct pilha_{
    int i;
    int x;
    int y;
} pilha;

void inserePilha(pilha *historico, pilha no, int *topo);
void removePilha(pilha *historico, int *topo);



bool **ler_instancia(int instancia_num, int *n, int *m);
void computa_passeios(bool **tabuleiro, int n, int m);
bool movPossivel(int *x, int *y, int n, int m, bool **tabuleiro, pilha *historico, int * topo);
bool tabuleiroNaoCheio(bool **tabuleiro, int n, int m);

#endif // _H_PASSEIO