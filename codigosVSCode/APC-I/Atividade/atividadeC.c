#include<stdio.h>

int main(int argc, char const *argv[]){

    int numero, seq;
    int contaDivisoes=0;

    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++){
        if (numero % i == 0){
            contaDivisoes++;
        }
    }
    
    if (contaDivisoes == 2){
        printf("%d eh primo.\n", numero);
        printf("3 Posteriores: ");
        for (int i = 1; i <= 3; i++){
            numero++;
            printf(" %d", numero);
        }   
    } else {
        printf("%d nao eh primo.\n", numero);
        printf("3 Anteriores: ");
        for (int i = 3; i >= 1; i--){
            seq=numero-i;
            printf(" %d", seq);
        }
    }
    return 0;
}