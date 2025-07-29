/*Crie uma função que compara duas strings e que retorna se elas são iguais ou diferentes.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void limpaEnter(char *s){
    int t=strlen(s);
    if(s[t-1]=='\n')
        s[t-1]='\0';
}

int VerificaStringsIguais(char *str1, char *str2, int tamanho1, int tamanho2){
    int i;
    limpaEnter(str1);
    limpaEnter(str2);
    
    if (tamanho1 != tamanho2) {
        return -1;
    }

    for (i = 0; i < tamanho1; i++) {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return -1;
        }
    }

    return 0; 
}

int main(){
    char s1[]={"Furtado"}, s2[]={"Larissa"};
    int result;
    
    result=VerificaStringsIguais(s1, s2, (sizeof(s1)-1), (sizeof(s2)-1));
    if(result==0)
        printf("As strings são iguais!\n");
    else
        printf("As strings não são iguais!\n");
    return 0;
}