#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char c[3][3] = {'c', 'c', 'c',
                    'l', 'm', 'm',
                    'l', 'm', 'm',};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c ", c[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}