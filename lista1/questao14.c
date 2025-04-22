/*Certo dia o professor de Johann Friederich Carl Gauss (aos 10 anos de idade) mandou que os alunos
somassem os números de 1 a 100. Imediatamente Gauss achou a resposta – 5050 – aparentemente
sem cálculos. Supõe-se que já aí, Gauss, houvesse descoberto a fórmula de uma soma de uma
progressão aritmética. S = (a1+an)*n/2. Construa um programa para realizar a soma de uma P.A. de N termos, 
com o primeiro a e o último da P.A. */

#include <stdio.h>

int main(){
    int a1, an, n, soma;

    printf("Forneça o primeiro termo da PA: ");
    scanf("%d", &a1);
    printf("Forneça o último termo da PA: ");
    scanf("%d", &an);
    printf("Forneça o tamanho da PA: ");
    scanf("%d", &a1);

    soma = ((a1+an)*n)/2;

    printf("A soma da PA = %d", soma);

    return 0;
}