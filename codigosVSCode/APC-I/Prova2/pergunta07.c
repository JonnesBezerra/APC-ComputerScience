#include<stdio.h>

int product(int number){
    int multiply = 1;

    if (number >= 0){
        for (int i = 1; i < number; i++){
            multiply = multiply * i;
        }
    } else {
        for (int i = 1; i < number; i++){
            multiply = multiply * i;
        }
     
        multiply = multiply * (-1);
    }
    
    return multiply;
}

int main(int argc, char const *argv[]){

    int number, multiply, produtory;

    scanf("%d", &number);
    
    multiply = product(number);

    produtory = (-1) * (((multiply * multiply) - 4) / (multiply - 3));

    printf("%d", produtory);
    
    return 0;
}