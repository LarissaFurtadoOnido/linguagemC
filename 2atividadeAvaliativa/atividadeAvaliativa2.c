#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(){
    int opcaoLoja, opcaoMaterial, opcaoPeca, opcao, quantAco, quantAluminio, quantBronze,quantEsfera, quantParalelepipedo, quantCilindro;
    float areaEsfera, areaParalelepipedo, areaCilindro, volumeEsfera, volumeParalelepipedo, volumeCilindro, raioEsfera, 
          altura, largura, profundidade, alturaCilindro, raioCilindro,pesoTotal, pesoAco, pesoAluminio, pesoBronze, pesoMedioAco, pesoMedioAluminio, pesoMedioBronze, 
          maiorVolumeAco, maiorVolumeAluminio, maiorVolumeBronze,menorVolumeAco, menorVolumeAluminio, menorVolumeBronze, maiorVolume, maiorVolumeCilindro, maiorNumVendas, minLata,   
          valorTotalLojaCZ,valorTotalLojaCJ,valorTotalLojaCP, valorTotalLojaCC, valorTotalLojaCM, valorTotalLojaCA, valorTotalLojaCB, ValorTotal;

    do{
        printf("1-Casa Zé\n2-Casa João\n3-Casa Paulo\n4-Casa Chico\n5-Casa Mané\n6-Casa Alfa\n7-Casa Beta\n");
        printf("Forneça a loja: ");
        scanf("%d", &opcaoLoja);

        switch (opcaoLoja){
            case 1:
                printf("\n_____________________________ Casa Zé _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("\nForneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4*PI*(pow(raioEsfera, 3));

                        quantEsfera++;

                        printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                        printf("\nForneça o tipo de material: ");
                        scanf("%d", &opcaoMaterial);

                        if(opcaoMaterial == 1)
                            quantAco++;
                        else if (opcaoMaterial == 2)
                            quantAluminio++;
                        else if(opcaoMaterial == 3)
                            quantBronze++;
                        else
                            printf("Valor inválido!!");                       

                        break;
                    
                    case 2:
                        printf("Forneça a altura do paralelepípedo: ");
                        scanf("%f", &altura);
                        printf("Forneça a largura do paralelepípedo: ");
                        scanf("%f", &largura);
                        printf("Forneça a profundidade do paralelepípedo: ");
                        scanf("%f", &profundidade);

                        areaParalelepipedo = (2*altura*largura)+(2*altura*profundidade)+(2*largura*profundidade);
                        volumeParalelepipedo = altura*largura*profundidade;

                        quantParalelepipedo++;

                        printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                        printf("\nForneça o tipo de material: ");
                        scanf("%d", &opcaoMaterial);

                        if(opcaoMaterial == 1)
                            quantAco++;
                        else if (opcaoMaterial == 2)
                            quantAluminio++;
                        else if(opcaoMaterial == 3)
                            quantBronze++;
                        else
                            printf("Valor inválido!!"); 

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro++;

                        printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                        printf("\nForneça o tipo de material: ");
                        scanf("%d", &opcaoMaterial);

                        if(opcaoMaterial == 1)
                            quantAco++;
                        else if (opcaoMaterial == 2)
                            quantAluminio++;
                        else if(opcaoMaterial == 3)
                            quantBronze++;
                        else
                            printf("Valor inválido!!"); 

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                
                break;
            
            case 2:
                printf("\n_____________________________ Casa João _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("Forneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4*PI*(pow(raioEsfera, 3));

                        quantEsfera++;

                        break;
                    
                    case 2:
                        printf("Forneça a altura do paralelepípedo: ");
                        scanf("%f", &altura);
                        printf("Forneça a largura do paralelepípedo: ");
                        scanf("%f", &largura);
                        printf("Forneça a profundidade do paralelepípedo: ");
                        scanf("%f", &profundidade);

                        areaParalelepipedo = (2*altura*largura)+(2*altura*profundidade)+(2*largura*profundidade);
                        volumeParalelepipedo = altura*largura*profundidade;

                        quantParalelepipedo++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro++;

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                break;
            
            default:
                break;
        }


        printf("\nDeseja sair?\n");
        printf("\n1-Sim\n2-Não");
        scanf("%d", &opcao);

    }while(opcao!=1);
    
    return 0;
}