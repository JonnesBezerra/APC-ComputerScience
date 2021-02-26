#include<stdio.h>
//Dizer se o número digitado é PRIMO OU NÃO
int prime(int number){
    int aux = 0;
    for (int i = 1; i <= number; i++){
        if ((number%i) == 0){
            aux += 1;
        }
    }
    return aux;
}

int main(int argc, char const *argv[]){

    int number=1, aux;

    while (number > 0){
        scanf("%d", &number);
        if(number != 0){
            aux = prime(number);
            if (aux == 2){
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }
    return 0;
}