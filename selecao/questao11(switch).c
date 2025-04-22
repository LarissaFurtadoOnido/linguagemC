/*
Uma empresa concederá um aumento de salário aos seus funcionários, variável de acordo com o
cargo, conforme a tabela abaixo. Faça um programa que leia o salário e o cargo de um funcionário
e calcule o novo salário. Se o cargo do funcionário não estiver na tabela, ele deverá, então,
receber 40% de aumento. Mostre o salário antigo, o novo salário e a diferença.
Código  Cargo       Percentual
101     Gerente     10%
102     Engenheiro  20%
103     Técnico     30%
*/

#include <stdio.h>

#define GERENTE 1.1
#define ENGENHEIRO 1.2
#define TECNICO 1.3
#define OUTROS 1.4

int main(){
    int codCargo;
    float salario_atual, novo_salario;
    
    printf("101 - Gerente\n102 - Engenheiro\n103 - Técnico\nForneça o código do cargo: ");
    scanf("%d", &codCargo);
    
    printf("\nForneça o salário atual: R$");
    scanf("%f", &salario_atual);
    
    switch (codCargo){
        case 101:
            novo_salario = salario_atual * GERENTE;
            break;
        case 102:
            novo_salario = salario_atual * ENGENHEIRO;
            break;
        case 103:
            novo_salario = salario_atual * TECNICO;
            break;
    
        default:
            novo_salario = salario_atual * OUTROS;
    }
    
    printf("\nSalário atual: R$%.2f\nNovo salário: R$%.2f\nValor do reajuste: R$%.2f", salario_atual, novo_salario, novo_salario-salario_atual);
    
    return 0;
}