#include<stdio.h>

int main(int argc, char const *argv[]){

    int numero, conta;

    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++){
        if (i%3 != 0){
            conta = i * i;
            printf("Quadrado de %d : %d\n", i, conta);
        } else {
            conta = i * i * i;
            printf("Cubo de ....%d : %d\n", i, conta);
        }  
    }
    
    return 0;
}