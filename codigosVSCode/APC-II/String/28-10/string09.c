#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[1000];
    int i, j;

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    i = -1, j = -1;
    while ((i < 0) || (j < 0)){
        printf("Digite um valor pra I e J separados por espaco: ");
        scanf("%d %d", &i, &j);
        if ((i < 0) || (j < 0)){
            printf("Favor nao digitar valores negativos!\n");
        }
    }

    if (i < j){
        for (i = i; i <= j; i++){
            printf("%c", string[i]);
        }
    } else if (i > j){
        for (i = i; i >= j; i--){
            printf("%c", string[i]);
        }
    } else { //senão significa que i = j, etão é só imprimir o caracter que estiver em i ou j
        printf("%c", string[j]); // escolhi j
    }
    printf("\n");

    return 0;
}