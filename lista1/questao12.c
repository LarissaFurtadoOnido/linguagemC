/*Uma P.A. (progressão aritmética) fica determinada pela sua razão (r) e pelo primeiro termo(a1).
Escreva um programa que seja capaz de determinar qualquer termo de uma P.A., dado a razão e o
primeiro termo. a = a + (n − 1) × r*/

#include <stdio.h>

int main(){
    int a1, r, an, n;

    printf("Forneça o primeiro termo da PA: ");
    scanf("%d", &a1);
    printf("Forneça a razão da PA: ");
    scanf("%d", &r);
    printf("Forneça a posição do termo que deseja encontrar na PA: ");
    scanf("%d", &n);

    an = a1 + (n - 1) * r;

    printf("O termo an = %d", an);

    return 0;
}