void linha()
{
    printf("\n +---------------------------------------------------------------------+\n");
}

void limpaTela()
{
    system("cls || clear");
}

void pausar()
{
    int aux;
    linha();
    printf("\n -> Digite [ENTER] para continuar\n");
    linha();
    aux = getchar();
}
