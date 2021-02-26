#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(int argc, char const *argv[]){

    int n, aux=0, v[2500], x;

    /*while (n != 4){
        n = rand() % 4;
        printf("%d ", n);
    }*/

    srand(time(NULL));

    for (int i = 0; i <= 10; i++){
        aux++;
    }
    printf("%d\n", aux);

    for (int i = 0; i < (aux/2); i++){
        x = rand() % aux;
        printf("%d ", x);
    }
    
    
    
    return 0;
}