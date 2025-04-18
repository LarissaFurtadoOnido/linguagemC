/*
Uma empresa decide dar um aumento aos seus funcionários de acordo com uma tabela que
considera o salário atual e o tempo de serviço de cada funcionário. Os funcionáarios com menor
salario terão um aumento proporcionalmente maior do que os funcionários com um salário maior, e
conforme o tempo de serviço na empresa, cada funcionário irá receber um bônus adicional de
salário. Faça um programa que leia:

• o valor do salario atual do funcionário;
• o tempo de serviço desse funcionáario na empresa (número de anos de trabalho na
empresa).

Use as tabelas abaixo para calcular o salário reajustado deste funcionário e imprima o valor do
salario final reajustado, ou uma mensagem caso o funcionário não tenha direito a nenhum aumento.

Salário Atual       Reajuste(%)           Tempo de Serviço     Bônus
Até 500,00              25%               Abaixo de 1 ano      Sem bônus
Até 1000,00             20%               De 1 a 3 anos        100,00
Até 1500,00             15%               De 4 a 6 anos        200,00
Até 2000,00             10%               De 7 a 10 anos       300,00
Acima de 2000,00    Sem reajuste          Mais de 10 anos      500,00 
*/

#include <stdio.h>

int main(){
    int tempo_servico;
    float salarioAtual, salarioNovo;
    
    printf("Forneça o tempo de serviço do funcionário: ");
    scanf("%d", &tempo_servico);
    printf("\nForneça o salário atual do funcionário: ");
    scanf("%f", &salarioAtual);
    
    if((tempo_servico<1) && (salarioAtual<=500.00)){
        salarioNovo = salarioAtual * 1.25;
        printf("\nSem bônus!\nSalário com reajuste: R$%.2f", salarioNovo);
        
    }else if((tempo_servico<=3) && (salarioAtual<=1000.00)){
        salarioNovo = salarioAtual * 1.20 + 100.00;
        printf("\nSalário com reajuste: R$%.2f", salarioNovo);
        
    }else if((tempo_servico<=6) && (salarioAtual<=1500.00)){
        salarioNovo = salarioAtual * 1.15 + 200.00;
        printf("\nSalário com reajuste: R$%.2f", salarioNovo);
    
    }else if((tempo_servico<=10) && (salarioAtual<=2000.00)){
        salarioNovo = salarioAtual * 1.10 + 300.00;
        printf("\nSalário com reajuste: R$%.2f", salarioNovo);
    
    }else{
        salarioNovo = salarioAtual + 500.00;
        printf("\nSem reajuste!\nSalário com bônus: R$%.2f", salarioNovo);
    }    
        
    return 0;
}