#ifndef _H_PASSEIO
#define _H_PASSEIO

// Implementar qualquer struct que for necessária aqui

bool **ler_instancia(int instancia_num, int *n, int *m);
void computa_passeios(bool **tabuleiro, int n, int m);
bool movPossivel(int *x, int *y, int n, int m, bool **tabuleiro);
bool tabuleiroNaoCheio(bool **tabuleiro, int n, int m);

#endif // _H_PASSEIO