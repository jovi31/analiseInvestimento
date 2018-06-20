float calculaVF(float vp, float i, float t)
{
    float vf, auxiliar;
    auxiliar = pow ((1 + i ), t);

    vf = vp * auxiliar;

    return vf;
}


float calculaVP(float vf, float i, float t)
{
    float vp, auxiliar;
    auxiliar = pow ((1 + i ), t);

    vp = vf / auxiliar;

    return vp;
}

float calculaVPL(float fluxoCaixa[], float i, int tamVetor)
{

    float vpl = 0;
    int cont;

    for(cont=0; cont<=tamVetor; cont++)
    {
        vpl += fluxoCaixa[cont] / pow((1 + i), cont);
    }

    return vpl;
}

float calculaTIR(float fluxoCaixa[], int n)
{
    float vpl, aux, i = 0;

    aux = calculaVPL(fluxoCaixa, i, n);
    i += 0.000001;

    do
    {
        vpl = calculaVPL(fluxoCaixa, i, n);

        if(vpl < 0) vpl *= -1;

        if(aux < 0) aux *= -1;

        if(vpl < aux)
        {
            aux = vpl;
            i += 0.000001;
        }
    }
    while(aux == vpl);

    i -= 0.000001;

    return i;
}

float calculaPayback(float fluxoCaixa[], float taxa, int n)
{
	int i = 0;
	float saldo = 0, aux = 0, vp, payback;

	do
	{
		saldo = calculaVPL(fluxoCaixa, taxa, i);
		aux = calculaVPL(fluxoCaixa, taxa, i+1);
		i++;
	}
	while(aux < 0 && i < n);

	if(aux == 0) return (float) i;

	if(aux < 0)
	{
		return (float) -i;
	}

	vp = calculaVP(fluxoCaixa[i], taxa, i);

	payback = (float) (i-1) + (abs(saldo)/vp);

	return payback;
}
