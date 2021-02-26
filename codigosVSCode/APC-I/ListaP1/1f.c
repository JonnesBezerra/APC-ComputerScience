#include<stdio.h>

int main(int argc, char const *argv[]){

    int mes1, mes2, previsao;

    scanf("%d %d", &mes1, &mes2);

    previsao = (mes2 - mes1) + mes2;

    printf("A previsao eh de: %d\n", previsao);

    return 0;
}