#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[]){

    char space[4][4];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            space[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }

    int people = 2;
    srand(time(NULL));
    while (people > 0){
        int i = rand() % 4;
        int j = rand() % 4;
        if (space[i][j] == 0){
            space[i][j] = 1;
            people--;
        }
    }
    printf("%d\n", people);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }
    
    int infected = 2;
    while (infected > 0){
        int i = rand() % 4;
        int j = rand() % 4;
        if (space[i][j] == 1){
            space[i][j] = 2;
            infected--;
        }
    }
    printf("%d\n", infected);

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (space[i][j] == 1){
                if ((space[i][j+1] == 0) && (j != 3)){
                    space[i][j] = 0;
                    space[i][j+1] = 1;
					j++;
                } else if ((space[i][j-1] == 0) && (j != 0)){
                    space[i][j] = 0;
                    space[i][j-1] = 1;
                } else if ((space[i+1][j] == 0) && (i != 3)){
                    space[i][j] = 0;
                    space[i+1][j] = 1;
                } else if ((space[i-1][j] == 0) && (i != 0)){
                    space[i][j] = 0;
                    space[i-1][j] = 1;
                }
            } else if (space[i][j] == 2){
                if ((space[i][j+1] == 0) && (j != 3)){
                    space[i][j] = 0;
                    space[i][j+1] = 2;
					j++;
                } else if ((space[i][j-1] == 0) && (j != 0)){
                    space[i][j] = 0;
                    space[i][j-1] = 2;
                } else if ((space[i+1][j] == 0) && (i != 3)){
                    space[i][j] = 0;
                    space[i+1][j] = 2;
                } else if ((space[i-1][j] == 0) && (i != 0)){
                    space[i][j] = 0;
                    space[i-1][j] = 2;
                }
            }
        }
    }
    printf("\n");
    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", space[i][j]);
        }
        printf("\n");
    }
    
    
    
    return 0;
}