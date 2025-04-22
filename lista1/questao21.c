/*Questão 21
Um programa para gerenciar os saques de um caixa eletrônico deve possuir algum mecanismo para
decidir o número de notas de cada valor que deve ser disponibilizado para o cliente que realizou o
saque. Um possível critério seria o da "distribuição ótima" no sentido de que as notas de menor
valor fossem distribuídas em número mínimo possível. Por exemplo, se a quantia solicitada fosse
R$ 87,00, o algoritmo deveria indicar uma nota de R$ 50,00, uma nota de R$ 20,00, uma nota de
R$ 10,00, uma nota de uma nota de R$ 5,00 e duas notas de R$ 1,00. Escreva um programa que
receba o valor da quantia solicitada e retorne a distribuição das notas de acordo com o critério da
distribuição ótima. 
Obs.: Notas disponíveis: R$50,00 , R$20,00, R$10,00, R$5,00 e R$1,00.*/

#include <stdio.h>

#define MAX_NOTA 50.00
#define NOTA2 20.00
#define NOTA3 10.00
#define NOTA4 5.00
#define MIN_NOTA 1.00


int main(){
    float valor;

    printf("Forneça o valor do saque: R$");
    scanf("%f", &valor);
    



    return 0;
}