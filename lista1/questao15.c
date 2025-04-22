/*O produto de uma série de termos de uma Progressão Geométrica (P.G.) pode ser calculado pela
fórmula abaixo: P = a1^n*q^((n(n-1))/2)*/


#include <stdio.h>
#include <math.h>

int main(){
    int p, a1, n, q;
    
    printf("Forneça o primeiro termo da PG: ");
    scanf("%d", &a1);
    printf("Forneça a razão da PG: ");
    scanf("%d", &q);
    printf("Forneça o tamanho da PG: ");
    scanf("%d", &n);
    
    p = pow(a1, n) * pow(q, (n*(n-1)/2));

    printf("O produto da PG = %d", p);

    return 0;
}