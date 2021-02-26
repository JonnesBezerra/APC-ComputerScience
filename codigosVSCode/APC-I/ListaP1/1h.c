#include<stdio.h>

int main(int argc, char const *argv[]){

    float serieharmonica=1.0, numero;

    scanf("%f", &numero);

    for (float i = 2.0; i <= numero; i++){
        serieharmonica += (1.0 / i);
    }
    
    printf("%f\n", serieharmonica);

    return 0;
}