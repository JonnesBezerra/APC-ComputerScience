#include <stdio.h>

int main(int argc, char const *argv[]){

    int d,m,a,ds;

    scanf("%d", &ds);
    
    a=ds/360;
    m=(ds % 360)/30;
    d=(ds % 360)%30;

    printf("Anos: %d \nMeses: %d \nDias: %d\n", a,m,d);

    return 0;

}