#include <stdio.h>

int main(int argc, char const *argv[]){

    int lado1, lado2, perimetro, area;

    scanf("%d\n %d", &lado1, &lado2);

    perimetro = 2 * (lado1+lado2);
    area = lado1 * lado2;

    printf("%d\n%d\n", area, perimetro);

    return 0;
}