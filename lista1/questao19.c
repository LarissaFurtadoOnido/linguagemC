/*Uma empresa possui, para um determinado funcionário, uma ficha contendo: a matrícula número de
horas trabalhadas e o nº de dependentes de um funcionário. Considerando que: 
a) A empresa paga 12 reais por hora e 40 reais por dependentes. 
b) Sobre o salário são feito descontos de 8,5% para o INSS e 5% para IR. 
Faça um algoritmo para ler a matrícula, número de horas trabalhadas e número
de dependentes de um funcionário. Após a leitura e os devidos cálculos escreva qual a matrícula,
salário bruto, os valores descontados para cada tipo de imposto e finalmente qual o salário líquido
do funcionário.*/

#include <stdio.h>

#define INSS 0.085
#define IR 0.05
#define VALOR_H 12.00
#define VALOR_DEP 40.00

int main(){
    int mat, num_dep, horas_trab;
    float salario_bruto, valor_INSS, valor_IR, salario_liquido;

    printf("Forneça o número da matrícula: ");
    scanf("%d", &mat);
    printf("Forneça o número de dependentes: ");
    scanf("%d", &num_dep);
    printf("Forneça a quantidade de horas trabalhadas: ");
    scanf("%d", &horas_trab);

    salario_bruto = (horas_trab * VALOR_H) + (num_dep * VALOR_DEP);
    valor_INSS = salario_bruto * INSS;
    valor_IR = salario_bruto * IR;
    salario_liquido = salario_bruto - valor_INSS - valor_IR;

    printf("\nMatrícula: %d\nSalário Bruto: R$%.2f\nINSS: R$%.2f\nIR: R$%.2f\nSalário Líquido: R$%.2f", mat, salario_bruto, valor_INSS, valor_IR, salario_liquido);

    return 0;
}
    
