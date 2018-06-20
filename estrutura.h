#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED

// menu.c

int menuInicial();
void menuCalculoValor(int flag);

// valor.c

float calculaVF(float vp, float i, float t);   // i -> valor decimal
float calculaVP(float vf, float i, float t);   // i -> valor decimal
float calculaVPL(float fluxoCaixa[], float i, int tamVetor);
float calculaTIR(float fluxoCaixa[], int n);
float calculaPayback(float fluxoCaixa[], float taxa, int n);

// exibir.c

void linha();
void limpaTela();
void pausar();

#endif // ESTRUTURA_H_INCLUDED
