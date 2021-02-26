#include<stdio.h>

int main(int argc, char const *argv[]){

    int decimal=0, valorBit, potencia;

    for (int bit = 0; bit != 7; bit++){

        scanf("%d", &valorBit);

        potencia=1;
        
        for (int i = 0; i < bit; i++){
            potencia = potencia *2;
        }

        decimal = decimal + valorBit * potencia;
    }
    
    printf("%d\n", decimal);

    return 0;
}