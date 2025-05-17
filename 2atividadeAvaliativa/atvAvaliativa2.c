#include <stdio.h>
#include <math.h>

#define PI 3.14
#define PESOACO 7.8
#define PESOALUMINIO 2.6
#define PESOBRONZE 8.8
#define CONSUMOTINTAACO 0.02
#define CONSUMOTINTAALUMINIO 0.01
#define CONSUMOTINTABRONZE 0.015

#define LIMITEPECA 1000

enum tipoMaterial{
    aco = 1,
    aluminio,
    bronze
};

enum loja{
    casaZe = 1,
    casaJoao,
    casaPaulo,
    casaChico,
    casaMane,
    casaAlfa,
    casaBeta
};

enum forma{
    esfera = 1,
    paralelepipedo,
    ciclindro
};


typedef struct material{
    float area;
    float volume;
    float peso;
    float preco;
    enum tipoMaterial tm;
    enum forma;
    enum loja lj;
}TPeca;


int main(){
    TPeca peca[LIMITEPECA];
    float largura, altura, profundidade, raio;
    int i, opcao, quantTipo[3], quantPeca[3];

    do{
        for(i=0;i < LIMITEPECA; i++){
            printf("1-Casa Zé\n2-Casa João\n3-Casa Paulo\n4-Casa Chico\n5-Casa Mané\n6-Casa Alfa\n7-Casa Beta\n");
            printf("Forneça a loja: ");
            scanf("%d", &peca[i].lj);
            switch (peca[i].lj){
            case 1:
                
                break;
            
            default:
                break;
            }
            

        }


        printf("Deseja sair? \n1-Sim\n2-Não");
        scanf("%d", &opcao);
    } while (opcao!=1);
    


    return 0;
}