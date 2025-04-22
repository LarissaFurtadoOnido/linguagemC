/*Uma P.G. (progressão geométrica) fica determinada pela sua razão (q) e pelo primeiro termo (a1).
Escreva um algoritmo que seja capaz de determinar qualquer termo de uma P.G., dado a razão e o
primeiro termo.
an = a1 × q( n −1)*/

#include <stdio.h>
#include <math.h>

int main(){
    int a1, q, an, n;

    printf("Forneça o primeiro termo da PG: ");
    scanf("%d", &a1);
    printf("Forneça a razão da PG: ");
    scanf("%d", &q);
    printf("Forneça a posição do termo que deseja encontrar na PG: ");
    scanf("%d", &n);

    an = a1 * pow(q,(n - 1));

    printf("O termo an = %d", an);

    return 0;
}