#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "estrutura.h"
#include "valor.c"
#include "exibir.c"
#include "menu.c"

int main()
{
    int op;

    do
    {
        limpaTela();
        op = menuInicial();
        limpaTela();

        switch(op)
        {
        case 1:
            menuCalculoValor(1);
            break;

        case 2:
            menuCalculoValor(2);
            break;

        case 3:
            menuVPL();
            break;

        case 4:
        	menuPayback();
            break;

        case 5:
        	menuTIR();
            break;

        case 6:
            linha();
            printf("\n -> Saindo do sistema ...\n");
            pausar();
            break;

        default:
            linha();
            printf("\n -> Opcao invalida\n");
            pausar();
            break;

        }
    }
    while(op != 6);

    return 0;
}
