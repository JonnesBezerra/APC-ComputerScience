#include<stdio.h>

int main(int argc, char const *argv[]){

    int numero;

    scanf("%d", &numero);

    if (numero%2 == 0){
        numero=(numero+2)*5;
        printf("%d\n", numero);
    } else {
        numero=(numero*6)+3;
        printf("%d\n", numero);
    }
    
    return 0;
}