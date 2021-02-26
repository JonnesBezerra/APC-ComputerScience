#include <stdio.h>
#include <stdlib.h>

/**int funcao(int x);
void funcao2(int * x);**/

void funcao2(int *x){
    *x = 20;
}

int funcao1(int x){
    int y;

    y = x + 3;
    funcao2(&x);
    printf("%d \n", x);
    
    return y;
}


int main(){

    int x = 2, resposta;

    resposta = funcao1(x);

    printf("%d \n", resposta);
    
    return 0;
}