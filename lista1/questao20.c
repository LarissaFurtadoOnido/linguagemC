/*Maria quer saber quantos litros de gasolina precisa colocar em seu carro e quanto vai gastar para
fazer uma viagem até a casa de sua irmã. Faça um programa que leia:
• A distância da casa de Maria até sua irmã;
• O consumo do carro de Maria (KM rodados / litro);
• O preço da gasolina (litro).
E mostre as informações que Maria necessita.*/

#include <stdio.h>

int main(){
    float dist, consumo, preco, valor_gasto, litros;

    printf("Forneça a ditância do lugar de origem ao lugar de destino: ");
    scanf("%f", &dist);
    printf("forneça o consumo do carro (Km/L): ");
    scanf("%f", &consumo);
    printf("Forneça o preço da gasolina: R$");
    scanf("%f", &preco);

    litros = dist / consumo;
    valor_gasto = litros * preco;

    printf("Valor R$%.2f", valor_gasto);
    printf("Litros %.2f", litros);
    return 0;
}