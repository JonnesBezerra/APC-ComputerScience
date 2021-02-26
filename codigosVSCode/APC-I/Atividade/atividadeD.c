#include<stdio.h>

int main(int argc, char const *argv[]){

    int numero, tabuada;

    scanf("%d", &numero);

    if(numero>=1 && numero<=10){
        for (int i = 1; i <= 10; i++){
            tabuada=i*numero;
            printf("%d x %d = %d\n", i, numero, tabuada);
        }
    } else {
        printf("Numero invalido.\n");
    }
    
    return 0;
}