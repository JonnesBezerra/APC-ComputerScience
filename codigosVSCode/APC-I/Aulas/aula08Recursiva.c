#include<stdio.h>

int powfunction(int base, int exponent){
    if (exponent == 0){
        return 1;
    }
    return base * powfunction(base, exponent - 1);
}

int main(int argc, char const *argv[]){

    int base, exponent, power;

    printf("Base: ");
    scanf("%d", &base);
    printf("Expoente: ");
    scanf("%d", &exponent);

    power = powfunction(base, exponent);

    printf("Potencia: %d\n", power);

    return 0;
}