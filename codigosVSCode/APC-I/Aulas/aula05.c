#include <stdio.h>

int main(int argc, char const *argv[]){

    int number, i, imperfect;
    
    do{
        imperfect = 0;
        scanf("%d", &number);

        /*Fiz number/2 pq se até a metade de number não for quadrado perfeito 
        então não vai ser mesmo e evita de continuar tantas repetições*/
        i = 1;
        while (i <= (number/2)){
            if ((i*i) == number){
                printf("sim\n");
                imperfect=1;
            }
            i++;
        }
        if(imperfect == 0){
            printf("nao\n");
        }
    } while (number != -1);
    
    return 0;
}