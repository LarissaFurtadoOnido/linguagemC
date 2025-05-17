#include <stdio.h>
#include <math.h>

#define PI 3.14

#define PESOACO 7.8
#define PESOALUMINIO 2.6
#define PESOBRONZE 8.8

#define CONSUMOTINTAACO 0.02
#define CONSUMOTINTAALUMINIO 0.01
#define CONSUMOTINTABRONZE 0.015

/*Calcular área e volume da cada material*/
void calcularAreaVolume(int opcaoPeca, float altura, float largura, float profundidade, float raio, float *area, float *volume)
{
    float areaEsfera, areaParalelepipedo, areaCilindro, volumeEsfera, volumeParalelepipedo, volumeCilindro;
    if (opcaoPeca == 1)
    {
        *area = 4 * PI * (pow(raio, 2));
        *volume = 4.0 / 3 * PI * (pow(raio, 3));
    }
    else if (opcaoPeca == 2)
    {
        *area = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
        *volume = altura * largura * profundidade;
    }
    else
    {
        *area = (2 * PI * (pow(raio, 2))) + (2 * PI * raio * altura);
        *volume = PI * (pow(raio, 2)) * altura;
    }
}

/*calcular de acordo com o tipo de material o peso e o peso Total*/
float calcularPeso(int opcaoMaterial, float volume, float *pesoTotal, float *maiorPesoAluminio, float *maiorPesoAco, float *maiorPesoBronze)
{
    float pesoAtual;

    if (opcaoMaterial == 1)
    {
        pesoAtual = (PESOACO * volume) / 1000;

        if (pesoAtual > *maiorPesoAco)
            *maiorPesoAco = pesoAtual;
    }
    else if (opcaoMaterial == 2)
    {
        pesoAtual = (PESOALUMINIO * volume) / 1000;

        if (pesoAtual > *maiorPesoAluminio)
            *maiorPesoAluminio = pesoAtual;
    }
    else if (opcaoMaterial == 3)
    {
        pesoAtual = (PESOBRONZE * volume) / 1000;

        if (pesoAtual > *maiorPesoBronze)
            *maiorPesoBronze = pesoAtual;
    }
    else
        printf("Valor inválido!!");

    *pesoTotal += pesoAtual;

    return pesoAtual;
}

/*calcula o valor de cada peça*/
float calculaValorPeca(int opcaoMaterial, int quantMaterial[], float resultPeso, TLoja loja)
{
    float valorAtual;

    if (opcaoMaterial == 1)
    {
        quantMaterial[opcaoMaterial - 1]++;
        valorAtual = resultPeso * loja.preco[opcaoMaterial - 1];
    }
    else if (opcaoMaterial == 2)
    {
        quantMaterial[opcaoMaterial - 1]++;
        valorAtual = resultPeso * loja.preco[opcaoMaterial - 1];
    }
    else if (opcaoMaterial == 3)
    {
        quantMaterial[opcaoMaterial - 1]++;
        valorAtual = resultPeso * loja.preco[opcaoMaterial - 1];
    }
    else
        printf("Valor inválido!!");

    return valorAtual;
}

/*verificar qual o maior e o menor volume de cada peça e maior volume entre todas as peças */
void maiorMenorVolume(int opcaoPeca, int quantEsfera[], int quantParalelepipedo[], int quantCilindro[], float volume,
                      float *maiorVolumeEsfera, float *maiorVolumeParalelepipedo, float *maiorVolumeCilindro,
                      float *menorVolumeEsfera, float *menorVolumeParalelepipedo, float *menorVolumeCilindro, float *maiorVolume)
{

    if (opcaoPeca == 1)
    {
        if (quantEsfera[opcaoPeca - 1] == 0)
        {
            *maiorVolumeEsfera = volume;
            *menorVolumeEsfera = volume;
        }
        else if (volume > *maiorVolumeEsfera)
            *maiorVolumeEsfera = volume;

        else if (volume < *menorVolumeEsfera)
            *menorVolumeEsfera = volume;
    }
    else if (opcaoPeca == 2)
    {
        if (quantParalelepipedo[opcaoPeca - 1] == 0)
        {
            *maiorVolumeParalelepipedo = volume;
            *menorVolumeParalelepipedo = volume;
        }
        else if (volume > *maiorVolumeParalelepipedo)
            *maiorVolumeParalelepipedo = volume;

        else if (volume < *menorVolumeParalelepipedo)
            *menorVolumeParalelepipedo = volume;
    }
    else if (opcaoPeca == 3)
    {
        if (quantCilindro[opcaoPeca - 1] == 0)
        {
            *maiorVolumeCilindro = volume;
            *menorVolumeCilindro = volume;
        }
        else if (volume > *maiorVolumeCilindro)
            *maiorVolumeCilindro = volume;

        else if (volume < *menorVolumeCilindro)
            *menorVolumeCilindro = volume;
    }
    if (*maiorVolumeEsfera > *maiorVolumeParalelepipedo && *maiorVolumeEsfera > *maiorVolumeCilindro)
        *maiorVolume = *maiorVolumeEsfera;
    else if (*maiorVolumeParalelepipedo > *maiorVolumeCilindro)
        *maiorVolume = *maiorVolumeParalelepipedo;
    else
        *maiorVolume = *maiorVolumeCilindro;
}

/*armazenar o preço dos materiais de cada loja*/
typedef struct loja{
    int cod;
    float preco[3];
} TLoja;

int main()
{
    TLoja loja[7] = {
        {101, {100, 80, 130}},
        {102, {110, 75, 120}},
        {103, {150, 90, 115}},
        {104, {110, 100, 160}},
        {105, {110, 50, 160}},
        {106, {90, 50, 110}},
        {107, {140, 100, 180}}};

    int opcaoLoja, opcaoMaterial, opcaoPeca, opcao,
        quantEsfera[7] = {0}, quantParalelepipedo[7] = {0}, quantCilindro[7] = {0}, quantLoja[7] = {0}, quantMaterial[3] = {0};

    float area, volume, resultPeso, result,
        altura, largura, profundidade, raio,
        pesoTotal,
        pesoMedioEsfera, maiorPesoAco = 0, maiorPesoAluminio = 0, maiorPesoBronze = 0,
                         maiorVolumeEsfera, maiorVolumeParalelepipedo, maiorVolumeCilindro,
                         menorVolumeEsfera, menorVolumeParalelepipedo, menorVolumeCilindro,
                         maiorVolume, maiorNumVendas = 0, minLata,
                         ValorTotalLoja[7] = {0}, ValorTotal = 0, valor;

    do
    {
        printf("101-Casa Zé\n102-Casa João\n103-Casa Paulo\n104-Casa Chico\n105-Casa Mané\n106-Casa Alfa\n107-Casa Beta\n");
        printf("Forneça a loja: ");
        scanf("%d", &opcaoLoja);

        switch (opcaoLoja)
        {
        case 101:
            printf("\n_____________________________ Casa Zé _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("\nForneça o raio da esfera: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                /*chamada das funções*/
                calcularAreaVolume(opcaoPeca, 0, 0, 0, raio, &area, &volume);
                maiorMenorVolume(opcaoPeca, quantEsfera, quantParalelepipedo, quantCilindro, volume, &maiorVolumeEsfera, &maiorVolumeParalelepipedo, &maiorVolumeCilindro, &menorVolumeEsfera, &menorVolumeParalelepipedo, &menorVolumeCilindro, &maiorVolume);
                resultPeso = calcularPeso(opcaoMaterial, volume, &pesoTotal, &maiorPesoAluminio, &maiorPesoAco, &maiorPesoBronze);
                valor = calculaValorPeca(opcaoMaterial, quantMaterial, resultPeso, loja[opcaoLoja - 101]);

                /*calcular valor total da loja*/
                ValorTotalLoja[opcaoPeca - 1] += valor;

                quantEsfera[opcaoPeca - 1]++;
                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                if (opcaoMaterial == 1)
                {
                    quantAco++;
                    pesoAtualAco = PESOACO * volumeParalelepipedo;
                    pesoAco += pesoAtualAco;

                    if (pesoAtualAco > maiorPesoAco)
                        maiorPesoAco = pesoAtualAco;
                }
                else if (opcaoMaterial == 2)
                {
                    quantAluminio++;
                    pesoAtualAluminio = PESOALUMINIO * volumeParalelepipedo;
                    pesoAluminio += pesoAtualAluminio;

                    if (pesoAtualAluminio > maiorPesoAluminio)
                        maiorPesoAluminio = pesoAtualAluminio;
                }
                else if (opcaoMaterial == 3)
                {
                    quantBronze++;
                    pesoAtualBronze = PESOBRONZE * volumeParalelepipedo;
                    pesoBronze += pesoAtualBronze;

                    if (pesoAtualBronze > maiorPesoBronze)
                        maiorPesoBronze = pesoAtualBronze;
                }
                else
                    printf("Valor inválido!!");

                if (quantParalelepipedo1 == 0)
                {
                    maiorVolumeParalelepipedo = volumeParalelepipedo;
                    menorVolumeParalelepipedo = volumeParalelepipedo;
                }
                else if (volumeParalelepipedo > maiorVolumeParalelepipedo)
                    maiorVolumeParalelepipedo = volumeParalelepipedo;
                else if (volumeParalelepipedo < menorVolumeParalelepipedo)
                    menorVolumeParalelepipedo = volumeParalelepipedo;

                quantParalelepipedo1++;
                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                if (opcaoMaterial == 1)
                {
                    quantAco++;
                    pesoAtualAco = PESOACO * volumeCilindro;
                    pesoAco += pesoAtualAco;

                    if (pesoAtualAco > maiorPesoAco)
                        maiorPesoAco = pesoAtualAco;
                }
                else if (opcaoMaterial == 2)
                {
                    quantAluminio++;
                    pesoAtualAluminio = PESOALUMINIO * volumeCilindro;
                    pesoAluminio += pesoAtualAluminio;

                    if (pesoAtualAluminio > maiorPesoAluminio)
                        maiorPesoAluminio = pesoAtualAluminio;
                }
                else if (opcaoMaterial == 3)
                {
                    quantBronze++;
                    pesoAtualBronze = PESOBRONZE * volumeCilindro;
                    pesoBronze += pesoAtualBronze;

                    if (pesoAtualBronze > maiorPesoBronze)
                        maiorPesoBronze = pesoAtualBronze;
                }
                else
                    printf("Valor inválido!!");

                if (quantCilindro1 == 0)
                {
                    maiorVolumeCilindro = volumeCilindro;
                    menorVolumeCilindro = volumeCilindro;
                }
                else if (volumeCilindro > maiorVolumeCilindro)
                    maiorVolumeCilindro = volumeCilindro;
                else if (volumeCilindro < menorVolumeCilindro)
                    menorVolumeCilindro = volumeCilindro;

                quantCilindro1++;
                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        case 102:
            printf("\n_____________________________ Casa João _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("Forneça o raio da esfera: ");
                scanf("%f", &raioEsfera);

                areaEsfera = 4 * PI * (pow(raioEsfera, 2));
                volumeEsfera = 4.0 / 3 * PI * (pow(raioEsfera, 3));

                quantEsfera2++;

                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                areaParalelepipedo = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
                volumeParalelepipedo = altura * largura * profundidade;

                quantParalelepipedo2++;

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                areaCilindro = (2 * PI * (pow(raioCilindro, 2))) + (2 * PI * raioCilindro * alturaCilindro);
                volumeCilindro = PI * (pow(raioCilindro, 2)) * alturaCilindro;

                quantCilindro2++;

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        case 103:
            printf("\n_____________________________ Casa Paulo _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("Forneça o raio da esfera: ");
                scanf("%f", &raioEsfera);

                areaEsfera = 4 * PI * (pow(raioEsfera, 2));
                volumeEsfera = 4.0 / 3 * PI * (pow(raioEsfera, 3));

                quantEsfera3++;

                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                areaParalelepipedo = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
                volumeParalelepipedo = altura * largura * profundidade;

                quantParalelepipedo3++;

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                areaCilindro = (2 * PI * (pow(raioCilindro, 2))) + (2 * PI * raioCilindro * alturaCilindro);
                volumeCilindro = PI * (pow(raioCilindro, 2)) * alturaCilindro;

                quantCilindro3++;

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        case 104:
            printf("\n_____________________________ Casa Chico _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("Forneça o raio da esfera: ");
                scanf("%f", &raioEsfera);

                areaEsfera = 4 * PI * (pow(raioEsfera, 2));
                volumeEsfera = 4.0 / 3 * PI * (pow(raioEsfera, 3));

                quantEsfera4++;

                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                areaParalelepipedo = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
                volumeParalelepipedo = altura * largura * profundidade;

                quantParalelepipedo4++;

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                areaCilindro = (2 * PI * (pow(raioCilindro, 2))) + (2 * PI * raioCilindro * alturaCilindro);
                volumeCilindro = PI * (pow(raioCilindro, 2)) * alturaCilindro;

                quantCilindro4++;

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        case 105:
            printf("\n_____________________________ Casa Mané _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("Forneça o raio da esfera: ");
                scanf("%f", &raioEsfera);

                areaEsfera = 4 * PI * (pow(raioEsfera, 2));
                volumeEsfera = 4.0 / 3 * PI * (pow(raioEsfera, 3));

                quantEsfera5++;

                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                areaParalelepipedo = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
                volumeParalelepipedo = altura * largura * profundidade;

                quantParalelepipedo5++;

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                areaCilindro = (2 * PI * (pow(raioCilindro, 2))) + (2 * PI * raioCilindro * alturaCilindro);
                volumeCilindro = PI * (pow(raioCilindro, 2)) * alturaCilindro;

                quantCilindro5++;

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        case 106:
            printf("\n_____________________________ Casa Alfa _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("Forneça o raio da esfera: ");
                scanf("%f", &raioEsfera);

                areaEsfera = 4 * PI * (pow(raioEsfera, 2));
                volumeEsfera = 4.0 / 3 * PI * (pow(raioEsfera, 3));

                quantEsfera6++;

                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                areaParalelepipedo = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
                volumeParalelepipedo = altura * largura * profundidade;

                quantParalelepipedo6++;

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                areaCilindro = (2 * PI * (pow(raioCilindro, 2))) + (2 * PI * raioCilindro * alturaCilindro);
                volumeCilindro = PI * (pow(raioCilindro, 2)) * alturaCilindro;

                quantCilindro6++;

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        case 107:
            printf("\n_____________________________ Casa Beta _____________________________\n");
            printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
            printf("Forneça a peça: ");
            scanf("%d", &opcaoPeca);

            switch (opcaoPeca)
            {
            case 1:
                printf("Forneça o raio da esfera: ");
                scanf("%f", &raioEsfera);

                areaEsfera = 4 * PI * (pow(raioEsfera, 2));
                volumeEsfera = 4.0 / 3 * PI * (pow(raioEsfera, 3));

                quantEsfera7++;

                break;

            case 2:
                printf("Forneça a altura do paralelepípedo: ");
                scanf("%f", &altura);
                printf("Forneça a largura do paralelepípedo: ");
                scanf("%f", &largura);
                printf("Forneça a profundidade do paralelepípedo: ");
                scanf("%f", &profundidade);

                areaParalelepipedo = (2 * altura * largura) + (2 * altura * profundidade) + (2 * largura * profundidade);
                volumeParalelepipedo = altura * largura * profundidade;

                quantParalelepipedo7++;

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &alturaCilindro);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raioCilindro);

                areaCilindro = (2 * PI * (pow(raioCilindro, 2))) + (2 * PI * raioCilindro * alturaCilindro);
                volumeCilindro = PI * (pow(raioCilindro, 2)) * alturaCilindro;

                quantCilindro7++;

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            quantLoja[opcaoLoja - 101]++;
            break;

        default:
            printf("Valor inválido!");
            break;
        }

        printf("\nDeseja sair?\n");
        printf("\n1-Sim\n2-Não");
        scanf("%d", &opcao);

    } while (opcao != 1);

    return 0;
}
