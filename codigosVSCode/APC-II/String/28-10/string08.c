#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[1000];
    float value, desc, finalPrice;

    printf("Digite o nome da mercadoria: ");
    fgets(name, sizeof(name), stdin);

    printf("Digite o valor da mercadoria: ");
    scanf("%f", &value);

    desc = (value * 0.1);
    finalPrice = (value - desc);

    printf("Nome da mercadoria: %sValor Total: %.2f\nValor do desconto: %.2f\nValor a vista: %.2f\n", name, value, desc, finalPrice);

    return 0;
}