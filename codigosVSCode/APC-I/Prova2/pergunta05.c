#include<stdio.h>

int main(int argc, char const *argv[]){

    int products, digits[1000], size;
    char price_tag[1000][8];

    scanf("%d", &products);

    for (int i = 0; i < products; i++){
        char price[7];
        scanf("%s", price);
        int j = 0;
        while ( price[j] != '\0'){
            price_tag[i][j] = price[j];
            j++;
        }
        size = 0;
        while (price_tag[i][size] != '.'){
            size++;
        }
        digits[i] = size;
    }

    /*for (int i = 0; i < products; i++){
        for (int j = 0; j < 7; j++){
            printf("%c", price_tag[i][j]);
        }
        printf("\n");
    }*/
    
    for (int i = 0; i < products; i++){
        for (int j = (digits[i] + 1); j < (digits[i] + 3); j++){
            printf("%c", price_tag[i][j]);
        }
        printf(".");
        int h = 0;
        while (price_tag[i][h] != '.'){
            printf("%c", price_tag[i][h]);
            h++;
        }
        printf("\n");
    }
    
    return 0;
}