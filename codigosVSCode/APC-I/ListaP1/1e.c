#include<stdio.h>

int main(int argc, char const *argv[]){

    int idade1, idade2, idade3;

    scanf("%d %d %d", &idade1, &idade2, &idade3);

    if((idade1 > idade2) && (idade1 > idade3)){
        printf("A maior idade eh: %d\n", idade1);
    } else if ((idade2 > idade1) && (idade2 > idade3)){
        printf("A maior idade eh: %d\n", idade2);
    } else {
        printf("A maior idade eh: %d\n", idade3);
    }
    

    return 0;
}