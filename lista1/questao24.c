/*Escreva um programa de ajuda para vendedores. A partir de um valor total lido, mostre: 
• o total a pagar com desconto de 10%; 
• o valor de cada parcela, no parcelamento de 3× sem juros; 
• a comissão do vendedor, no caso da venda ser a vista (5% sobre o valor com desconto);
• a comissão do vendedor, no caso da venda ser parcelada (5% sobre o valor total).
*/

#include <stdio.h>

#define DESCONTO 0.1
#define QUANT_PARCELA 3
#define PORC_VENDEDOR 0.05

int main(){
    float valor_compra, comissao_vendedor, parcela, valor_total;
    int opcao;

    do{
        printf("Forneça o valor da compra: R$");
        scanf("%f", &valor_compra);
        printf("\n1 - À vista\n2 - Parcelado\nForneça a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                valor_total = valor_compra - (valor_compra * DESCONTO);
                comissao_vendedor = valor_total * PORC_VENDEDOR;
                printf("\nValor total a ser pago: R$%.2f\nComissão do vendedor: R$%.2f\n", valor_total, comissao_vendedor);
                break;
            case 2:
                parcela = valor_compra / QUANT_PARCELA;
                comissao_vendedor = valor_compra * PORC_VENDEDOR;
                printf("\nValor da parcela: R$%.2f\nComissão do vendedor: R$%.2f\n", parcela, comissao_vendedor);
                break;

            default:
                printf("\nValor inválido!!\n");
        }

        printf("\nDeseja sair?\n1 - Sim\n2 - Não\n");
        scanf("%d", &opcao);

    }while(opcao != 1);

    return 0;
}