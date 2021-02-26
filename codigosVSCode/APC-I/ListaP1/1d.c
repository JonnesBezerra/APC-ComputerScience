#include<stdio.h>

int main(int argc, char const *argv[]){

    int troco,n50,n20,n10,n5,n2,n1;

    scanf("%d", &troco);

    n50=troco/50;
    troco=troco%50;

    n20=troco/20;
    troco=troco%20;

    n10=troco/10;
    troco=troco%10;

    n5=troco/5;
    troco=troco%5;

    n2=troco/2;
    troco=troco%2;

    n1=troco/1;
    troco=troco%1;

    printf("50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\n", n50,n20,n10,n5,n2,n1);

    return 0;
}