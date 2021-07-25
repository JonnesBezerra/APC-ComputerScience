#include<stdio.h>
#include<stdlib.h>

int menu();

int main(){
    
    int opcao;

    opcao = menu();

    printf("A opcao escolhida foi a %d - Opcao %d", opcao, opcao);

    return 0;
}

int menu(){
    int opcao;
    printf("1 - Opcao 1\n");
    printf("2 - Opcao 2\n");
    printf("3 - Opcao 3\n");
    printf("4 - Opcao 4\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

