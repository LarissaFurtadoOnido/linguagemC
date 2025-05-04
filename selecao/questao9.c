/*Questão 9
O cardápio de uma lanchonete é o seguinte:
Código       Especificação         Preço unitário
100            Pastel                  2,5
101          Bauru simples             3,20
102           Bauru c/ovo              3,5
103           Hamburger                4,10
104           Cheeseburger             6,0
105           Refrigerante             2,0

Escrever um programa que leia o código do item pedido, a quantidade e calcule o valor a ser pago
por aquele lanche. Considere que a cada execução somente será calculado um item.*/


#include <stdio.h>

#define 100 2.5
#define 101 3.2
#define 102 3.5
#define 103 4.1
#define 104 6.0
#define 105 2.0

int main(){
    int cod, quant;
    float valorTotal;
    
    printf("100-Pastel\n101-Bauru simples\n102-Bauru c/ ovo\n103-Hamburguer\n104-Cheeseburguer\n105-Refrigerante\n");
    printf("Forneça o código do lanche: ");
    scanf("%d", &cod);
    printf("Forneça a quantidade: ");
    scanf("%d", &quant);
    
    if(cod == 100)
        valorTotal = quant*100;
    else if(cod == 101)
        valorTotal = quant*101;
    else if(cod == 102)
        valorTotal = quant*102;
    else if(cod == 103)
        valorTotal = quant*103;
    else if(cod == 104)
        valorTotal = quant*104;
    else if(cod == 105)
        valorTotal = quant*105;
    else
        printf("Valor inválido!");
    
    printf("Valor total = R$%.2f", valorTotal);
    
    return 0;
}
