#include<stdio.h>

int powFunction(int base, int exponent){
    int power = 1;

    for(int i=0; i < exponent; i++){
        power = power * base;
    }
    return power;
}

int main(int argc, char const *argv[]){

    int exponent, base, power;

    printf("Base: ");
    scanf("%d", &base);
    printf("Expoente: ");
    scanf("%d", &exponent);

    power = powFunction(base, exponent);

    printf("Potencia: %d\n", power);

    return 0;
}