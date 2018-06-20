int menuInicial()
{
    int op;

    linha();
    printf("\t# SISTEMA DE ADMF");
    linha();
    printf("\n (1) Valor Futuro");
    printf("\n (2) Valor Presente");
    printf("\n (3) Valor Presente Liquido");
    printf("\n (4) Calcular Payback");
    printf("\n (5) Taxa interna de retorno");
    printf("\n (6) Sair\n");
    linha();
    printf("\n -> Escolha uma opcao: ");
    scanf("%d", &op);
    getchar();

    return op;
}

void menuCalculoValor(int flag)
{
    float valor, taxa, periodo, resultado;
    char palavra[20];

    linha();
    printf("\t# INSIRA OS VALORES");
    linha();

    printf("\n -> Digite o valor: R$ ");
    scanf("%f", &valor);
    getchar();
    printf("\n -> Digite a taxa (em porcentagem): ");
    scanf("%f", &taxa);
    getchar();
    printf("\n -> Digite o periodo: ");
    scanf("%f", &periodo);
    getchar();

    taxa = taxa/100;

    if(flag == 1)
    {
        resultado = calculaVF(valor, taxa, periodo);
        strcpy(palavra, "Valor Futuro");
    }
    else
    {
        resultado = calculaVP(valor, taxa, periodo);
        strcpy(palavra, "Valor Presente");
    }

    linha();
    printf("\n -> %s = R$ %.2f\n", palavra, resultado);
    pausar();
}

float *preencherFluxo(float vInicial, int nPeriodos){
	int i;
	float *valor;

	valor = (float*) malloc((nPeriodos+1) * sizeof(float));

    valor[0] = vInicial * (-1);

    for(i=1; i<=nPeriodos; i++)
    {
        printf("\n -> Digite o valor do fluxo de caixa [%d]: R$ ", i);
        scanf("%f", &valor[i]);
        getchar();
    }

    return valor;
}

void menuVPL()
{
    float vpl, taxa, vInicial, *valor;
    int nPeriodos;
    char palavra[12];

    linha();
    printf("\t# CALCULO DO VPL");
    linha();

    printf("\n -> Digite o valor do investimento inicial: R$ ");
    scanf("%f", &vInicial);
    getchar();
    printf("\n -> Digite a taxa aplicada (em %%): ");
    scanf("%f", &taxa);
    getchar();
    printf("\n -> Digite o numero de periodos [nao contar investimento inicial]: ");
    scanf("%d", &nPeriodos);
    getchar();
    linha();

    taxa = taxa/100;

    valor = preencherFluxo(vInicial, nPeriodos);

    vpl = calculaVPL(&valor[0], taxa, nPeriodos);

    free(valor);

    linha();
    printf("\n -> VPL = R$ %.2f\n", vpl);

    if(vpl > 0)
    {
        strcpy(palavra, "Viavel");
    }
    else
    {
        if(vpl == 0)
        {
            strcpy(palavra, "Indiferente");
        }
        else
        {
            strcpy(palavra, "Inviavel");
        }
    }

    printf("\n -> Analise do VPL = %s \n", palavra);

    pausar();
}

void menuTIR(){
	float vInicial, *valor, tir, taxaEsperada;
    int nPeriodos;

    linha();
    printf("\t# CALCULO DA TIR");
    linha();

    printf("\n -> Digite o valor do investimento inicial: R$ ");
    scanf("%f", &vInicial);
    getchar();
    printf("\n -> Digite o numero de periodos [nao contar investimento inicial]: ");
    scanf("%d", &nPeriodos);
    getchar();
    printf("\n -> Digite a taxa minima necessaria [em %%]: ");
    scanf("%f", &taxaEsperada);
    getchar();
    linha();

    valor = preencherFluxo(vInicial, nPeriodos);

    tir = calculaTIR(&valor[0], nPeriodos);

    free(valor);

    linha();

    tir = tir * 100;

    printf("\n -> TIR = %.2f%%\n", tir);

    printf("\n -> Analise da TIR =");
    if(tir > taxaEsperada)
    {
        printf(" Viavel\n");
    }
    else
    {
        if(tir == taxaEsperada)
        {
            printf(" Indiferente\n");
        }
        else
        {
            printf(" Inviavel\n");
        }
    }

    pausar();
}

void menuPayback(){
	float vInicial, *valor, taxa, payback, tempoEsperado;
    int nPeriodos;

    linha();
    printf("\t# CALCULO DO PAYBACK");
    linha();

    printf("\n -> Digite o valor do investimento inicial: R$ ");
    scanf("%f", &vInicial);
    getchar();
    printf("\n -> Digite a taxa aplicada (em %%): ");
    scanf("%f", &taxa);
    getchar();
    printf("\n -> Digite o numero de periodos [nao contar investimento inicial]: ");
    scanf("%d", &nPeriodos);
    getchar();
    printf("\n -> Digite o tempo esperado para retorno do investimento: ");
    scanf("%f", &tempoEsperado);
    getchar();
    linha();

    taxa =  taxa/100;

    valor = preencherFluxo(vInicial, nPeriodos);

    payback = calculaPayback(&valor[0], taxa, nPeriodos);

    free(valor);

    linha();

    if(payback < 0)
    {
    	printf("\n -> Tempo de payback = %.2f+\n", -payback);
    }
    else
    {
    	printf("\n -> Tempo de payback = %.2f\n", payback);
    }

    printf("\n -> Analise de payback =");
    if(payback > tempoEsperado)
    {
        printf(" Inviavel\n");
    }
    else
    {
        if(payback == tempoEsperado)
        {
            printf(" Indiferente\n");
        }
        else
        {
            printf(" Viavel\n");
        }
    }

    pausar();
}
