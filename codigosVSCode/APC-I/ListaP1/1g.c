#include<stdio.h>

int main(int argc, char const *argv[]){

    int numero, soma=0;

    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++){
        if (i%2 != 0){
            soma += i;
        }
    }
    
    printf("%d\n", soma);

    return 0;
}