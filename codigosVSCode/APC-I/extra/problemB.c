#include<stdio.h>

int main(int argc, char const *argv[]){

    int elements, number, perfect = 0;

    scanf("%d", &elements);
    int vector[elements], yesNo[elements];

    for (int i = 0; i < elements; i++){
        scanf("%d", &number);
        vector[i] = number;
    }

    for (int i = 0; i < elements; i++){
        int root = 1;
        while ((vector[i] != root*root) && (root <= vector[i])){
            root += 1;
        }
        if (vector[i] == (root*root)){
            yesNo[i] = 1;
        } else {
            yesNo[i] = 0;
        }
    }

    if (yesNo[0] == 0){
        for (int i = 1; i < elements;){
            if (yesNo[i] != 1){
                perfect = 1;
            }
            i += 2;
        }
        for (int i = 0; i < elements;){
            if (yesNo[i] != 0 ){
                perfect = 1;
            }
            i += 2;
        }        
    }
    if (yesNo[0] == 1){
        for (int i = 0; i < elements;){
            if (yesNo[i] != 1){
                perfect = 1;
            }
            i += 2;
        }
        for (int i = 1; i < elements;){
            if (yesNo[i] != 0){
                perfect = 1;
            }
            i += 2;
        }
    }

    if (perfect == 0 ){
        printf("O MINISTRO FICA\n");
    } else {
        printf("TROQUE DE MINISTRO\n");
    }
    
    return 0;
}