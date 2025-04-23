/*Faça um programa que efetue o cálculo da quantidade de litros de combustível gastos em uma
viagem, sabendo-se que o carro faz 12 km com um litro. Deverão ser fornecidos o tempo gasto na
viagem e a velocidade média. 
Distância = Tempo x Velocidade. 
Litros = Distancia / 12. 
O programa deverá apresentar os valores da Distância percorrida e a quantidade de Litros utilizados
na viagem.*/

#include <stdio.h>

#define CONSUMO 12

int main(){
    float dist, tempo, velocidade, litros;

    printf("Forneça o tempo gasto na viagem: ");
    scanf("%d", &tempo);
    printf("Forneça a velocidade média: ");
    scanf("%d", &velocidade);
    
    dist = tempo * velocidade;
    litros = dist / CONSUMO;
    
    printf("\nDistância percorrida: %.2f\nQuantidade de litros utilizados: %.2f", dist, litros);

    return 0;
}