/*Crie uma função que calcule o comprimento de uma string e que possui a seguinte assinatura:
void tamanho(char *str, int *strsize). */

#include <stdio.h>
#include <string.h>

void limpaEnter(char *s){
    int t=strlen(s);
    if(s[t-1]=='\n')
        s[t-1]='\0';
}

//usando função da biblioteca string.h
/*void limpaEnter(char *s){
    //strcspn(string, valor que vai ser troca)
    s[strcspn(s, "\n")]='\0';
}*/

void tamanho(char *str, int *strsize){
    int i=0;
    limpaEnter(str);
    while(str[i]!='\0'){
        (*strsize)++;
        i++;
    }
}

int main(){
    char str[] = {"Larissa"};
    int tam=0;
    tamanho(str, &tam);
    printf("Tamanho da string '%s' = %d\n", str, tam);
    return 0;
}