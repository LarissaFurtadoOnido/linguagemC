/*Implemente a função a qual recebe duas strings, str1 e str2, e concatena a string apontada por str2
à string apontada por str1.*/

#include <stdio.h>
#include <string.h>

void limpaEnter(char *s){
    int t=strlen(s);
    if(s[t-1]=='\n')
        s[t-1]='\0';
}

void ConcatenaStrings(char *str1, char *str2){
    int tam1=strlen(str1), tam2=strlen(str2), i;
    char s[tam1+tam2+1];

    limpaEnter(str1);
    limpaEnter(str2);

    for(i=0;str1[i]!='\0';i++){
        s[i]=str1[i];
    }

    for(i=0;str2[i]!='\0';i++){
        s[tam1+i]=str2[i];
    }

    s[tam1+tam2] = '\0';
    printf("%s\n", s);
}

int main(){
    char s1[]={"Lari"}, s2[]={"ssa"};

    ConcatenaStrings(s1, s2);

    return 0;
}