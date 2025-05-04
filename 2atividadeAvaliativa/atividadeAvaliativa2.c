#include <stdio.h>
#include <math.h>

#define PI 3.14
#define PESOACO 7.8
#define PESOALUMINIO 2.6
#define PESOBRONZE 8.8
#define CONSUMOTINTAACO 0.02
#define CONSUMOTINTAALUMINIO 0.01
#define CONSUMOTINTABRONZE 0.015

int main(){
    int opcaoLoja, opcaoMaterial, opcaoPeca, opcao, 
        quantAco=0, quantAluminio=0, quantBronze=0,
        quantEsfera1=0, quantParalelepipedo1=0, quantCilindro1=0,
        quantEsfera2=0, quantParalelepipedo2=0, quantCilindro2=0,
        quantEsfera3=0, quantParalelepipedo3=0, quantCilindro3=0,
        quantEsfera4=0, quantParalelepipedo4=0, quantCilindro4=0,
        quantEsfera5=0, quantParalelepipedo5=0, quantCilindro5=0,
        quantEsfera6=0, quantParalelepipedo6=0, quantCilindro6=0,
        quantEsfera7=0, quantParalelepipedo7=0, quantCilindro7=0;

    float areaEsfera, areaParalelepipedo, areaCilindro, volumeEsfera, volumeParalelepipedo, volumeCilindro, raioEsfera, 
          altura, largura, profundidade, 
          alturaCilindro, raioCilindro,
          pesoTotal, pesoAco, pesoAluminio, pesoBronze, pesoAtualAco, pesoAtualAluminio, pesoAtualBronze, 
          pesoMedioAco, pesoMedioAluminio, pesoMedioBronze, 
          maiorVolumeAco, maiorVolumeAluminio, maiorVolumeBronze,//corrigir
          menorVolumeAco, menorVolumeAluminio, menorVolumeBronze, //corrigir
          maiorVolume, maiorVolumeCilindro, maiorNumVendas, minLata,   
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
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera1++;

                        printf("\n1-Aço\n2-Alumínio\n3-Bronze\n");
                        printf("\nForneça o tipo de material: ");
                        scanf("%d", &opcaoMaterial);

                        if(opcaoMaterial == 1){
                            quantAco++;
                            pesoAtualAco = PESOACO * volumeEsfera;
                            pesoAco += pesoAtualAco;
                        }else if (opcaoMaterial == 2){
                            quantAluminio++;
                            pesoAtualAluminio = PESOALUMINIO * volumeEsfera;
                            pesoAluminio += pesoAtualAluminio;
                        }else if(opcaoMaterial == 3){
                            quantBronze++;
                            pesoAtualBronze = PESOBRONZE * volumeEsfera;
                            pesoBronze += pesoAtualBronze;
                        }else
                            printf("Valor inválido!!");                       

                        if(quantEsfera1 == 0){
                            maiorVolumeAco = volumeEsfera;//corrigir
                            menorVolumeAco = volumeEsfera;
                        }

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

                        quantParalelepipedo1++;

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

                        quantCilindro1++;

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
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera2++;

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

                        quantParalelepipedo2++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro2++;

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                break;
            
            case 3:
                printf("\n_____________________________ Casa Paulo _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("Forneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera3++;

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

                        quantParalelepipedo3++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro3++;

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                break;
            
            case 4:
                printf("\n_____________________________ Casa Chico _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("Forneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera4++;

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

                        quantParalelepipedo4++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro4++;

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                break;
            
            case 5:
                printf("\n_____________________________ Casa Mané _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("Forneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera5++;

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

                        quantParalelepipedo5++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro5++;

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                break;
            
            case 6:
                printf("\n_____________________________ Casa Alfa _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("Forneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera6++;

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

                        quantParalelepipedo6++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro6++;

                        break;
                    
                    default:
                        printf("Valor inválido!!");
                        break;
                }

                break;
            
            case 7:
                printf("\n_____________________________ Casa Beta _____________________________\n");
                printf("\n1-Esfera\n2-Paralelepípedo\n3-Cilindro\n");
                printf("Forneça a peça: ");
                scanf("%d", &opcaoPeca);

                switch (opcaoPeca){
                    case 1:
                        printf("Forneça o raio da esfera: ");
                        scanf("%f", &raioEsfera);

                        areaEsfera = 4*PI*(pow(raioEsfera, 2));
                        volumeEsfera = 4.0/3*PI*(pow(raioEsfera, 3));

                        quantEsfera7++;

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

                        quantParalelepipedo7++;

                        break;
                    
                    case 3:
                        printf("Forneça a altura do cilindro: ");
                        scanf("%f", &alturaCilindro);
                        printf("Forneça o raio do cilindro: ");
                        scanf("%f", &raioCilindro);
                        
                        areaCilindro = (2*PI*(pow(raioCilindro, 2))) + (2*PI*raioCilindro*alturaCilindro);
                        volumeCilindro = PI*(pow(raioCilindro, 2))*alturaCilindro;

                        quantCilindro7++;

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

        

        printf("\nDeseja sair?\n");
        printf("\n1-Sim\n2-Não");
        scanf("%d", &opcao);

    }while(opcao!=1);
    
    return 0;
}