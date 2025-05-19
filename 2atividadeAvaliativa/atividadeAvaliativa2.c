#include <stdio.h>
#include <math.h>

#define PI 3.14

#define PESOACO 7.8
#define PESOALUMINIO 2.6
#define PESOBRONZE 8.8

/*#define CONSUMOTINTAACO 0.02
#define CONSUMOTINTAALUMINIO 0.01
#define CONSUMOTINTABRONZE 0.015*/

/*armazenar o preço dos materiais de cada loja*/
typedef struct
{
    int cod;
    float preco[3];
} TLoja;

/*Calcular área e volume da cada material*/
void calcularAreaVolume(int opcaoPeca, float altura, float largura, float profundidade, float raio, float *area, float *volume)
{
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
    /*verifica qual o maior volume entre todas as peças*/
    if (*maiorVolumeEsfera > *maiorVolumeParalelepipedo && *maiorVolumeEsfera > *maiorVolumeCilindro)
        *maiorVolume = *maiorVolumeEsfera;
    else if (*maiorVolumeParalelepipedo > *maiorVolumeCilindro)
        *maiorVolume = *maiorVolumeParalelepipedo;
    else
        *maiorVolume = *maiorVolumeCilindro;
}

/*verificar a loja que teve o maior número de vendas*/
void maiorVenda(float ValorTotalLoja[], float *maiorNumVendas)
{
    int i;
    *maiorNumVendas = ValorTotalLoja[0];
    for (i = 0; i < 7; i++)
    {
        if (ValorTotalLoja[i] > *maiorNumVendas)
            *maiorNumVendas = ValorTotalLoja[i];
    }
}

/*calcular o consumo de tinta de acordo com o tipo de material
float consumoTinta(int opcaoMaterial, float area){
    float consumo, consumoTotal;
    int minLata18=0, minLata5=0, minLata1=0;

    if(opcaoMaterial == 1)
        consumo = area * CONSUMOTINTAACO;
    else if(opcaoMaterial == 2)
        consumo = area * CONSUMOTINTAALUMINIO;
    else if(opcaoMaterial == 3)
        consumo = area * CONSUMOTINTABRONZE;

    consumoTotal += consumo;

    minLata18 = (int)consumoTotal%18;
    minLata5 = (int)consumoTotal%5;


    return consumoTotal;
}*/

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

    int opcaoLoja = 0, opcaoMaterial = 0, opcaoPeca = 0, opcao, i,
        quantEsfera[7] = {0}, quantParalelepipedo[7] = {0}, quantCilindro[7] = {0}, quantMaterial[3] = {0};

    float area = 0, volume = 0, resultPeso = 0,
          altura = 0, largura = 0, profundidade = 0, raio = 0,
          pesoTotal = 0,
          maiorPesoAco = 0, maiorPesoAluminio = 0, maiorPesoBronze = 0,
          maiorVolumeEsfera = 0, maiorVolumeParalelepipedo = 0, maiorVolumeCilindro = 0,
          menorVolumeEsfera = 0, menorVolumeParalelepipedo = 0, menorVolumeCilindro = 0,
          maiorVolume = 0, maiorNumVendas = 0,
          ValorTotalLoja[7] = {0}, ValorTotal = 0, valor = 0;

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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        case 102:
            printf("\n_____________________________ Casa João _____________________________\n");
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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        case 103:
            printf("\n_____________________________ Casa Paulo _____________________________\n");
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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        case 104:
            printf("\n_____________________________ Casa Chico _____________________________\n");
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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        case 105:
            printf("\n_____________________________ Casa Mané _____________________________\n");
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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        case 106:
            printf("\n_____________________________ Casa Alfa _____________________________\n");
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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        case 107:
            printf("\n_____________________________ Casa Beta _____________________________\n");
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

                break;

            case 3:
                printf("Forneça a altura do cilindro: ");
                scanf("%f", &altura);
                printf("Forneça o raio do cilindro: ");
                scanf("%f", &raio);

                printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                printf("\nForneça o tipo de material: ");
                scanf("%d", &opcaoMaterial);

                break;

            default:
                printf("Valor inválido!!");
                break;
            }

            break;

        default:
            printf("Valor inválido!");
            break;
        }

        /*chamada das funções*/
        calcularAreaVolume(opcaoPeca, altura, largura, profundidade, raio, &area, &volume);
        maiorMenorVolume(opcaoPeca, quantEsfera, quantParalelepipedo, quantCilindro, volume, &maiorVolumeEsfera, &maiorVolumeParalelepipedo, &maiorVolumeCilindro, &menorVolumeEsfera, &menorVolumeParalelepipedo, &menorVolumeCilindro, &maiorVolume);
        resultPeso = calcularPeso(opcaoMaterial, volume, &pesoTotal, &maiorPesoAluminio, &maiorPesoAco, &maiorPesoBronze);
        valor = calculaValorPeca(opcaoMaterial, quantMaterial, resultPeso, loja[opcaoLoja - 101]);
        maiorVenda(ValorTotalLoja, &maiorNumVendas);

        /*calcula o valor da loja*/
        ValorTotalLoja[opcaoLoja - 101] += valor;

        /*calcula o valor total, todas as lojas*/
        ValorTotal += ValorTotalLoja[opcaoLoja - 101];

        quantEsfera[opcaoPeca - 1]++;
        quantParalelepipedo[opcaoPeca - 1]++;
        quantCilindro[opcaoPeca - 1]++;

        printf("\nDeseja imprimir relatóio?\n");
        printf("\n1-Sim\n2-Não");
        scanf("%d", &opcao);

    } while (opcao != 1);


    /*Relatório*/
    printf("\n_____________________________ Relatório _____________________________\n");
    printf("\nPeso total da estátua: %.2f", pesoTotal);
    printf("\nValor Total: R$%.2f", ValorTotal);
    printf("\nPeça mais pesada de Aço: %.2f", maiorPesoAco);
    printf("\nPeça mais pesada de Alumínio: %.2f", maiorPesoAluminio);
    printf("\nPeça mais pesada de Bronze: %.2f", maiorPesoBronze);
    printf("\nMaior volume encontrado entre as peças: %.2f", maiorVolume);
    printf("\nMaior volume encontrado entre os cilindros: %.2f", maiorVolumeCilindro);
    printf("\nMaior valor encontrado entre as lojas: %.2f", maiorNumVendas);

    for (i = 0; i < 7; i++)
    {
        if (i == 0)
        {
            printf("\n\nValor total (%d): R$%.2f", loja->cod, ValorTotalLoja[i]);
            printf("\nQuantidade de Esferas (%d): %d", loja->cod, quantEsfera[i]);
            printf("\nQuantidade de Paralelepípedos (%d): %d", loja->cod, quantParalelepipedo[i]);
            printf("\nQuantidade de Cilindros (%d): %d\n\n", loja->cod, quantCilindro[i]);
        }
        else
        {
            printf("\nValor total (%d): R$%.2f", (loja->cod) + i, ValorTotalLoja[i]);
            printf("\nQuantidade de Esferas (%d): %d", (loja->cod) + i, quantEsfera[i]);
            printf("\nQuantidade de Paralelepípedos (%d): %d", (loja->cod) + i, quantParalelepipedo[i]);
            printf("\nQuantidade de Cilindros (%d): %d\n\n", (loja->cod) + i, quantCilindro[i]);
        }
    }

    return 0;
}
