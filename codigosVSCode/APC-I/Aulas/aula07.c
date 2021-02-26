#include<stdio.h>

int main(int argc, char const *argv[]){

    int leftRight, upDown, rows, column, assistant=0;

    scanf("%d %d", &rows, &column);
    char labyrinth[rows][column];

    //receive the labyrinth
    for (int i=0; i < rows; i++){
        char line[rows];
        scanf("%s", line);
        for(int j=0; j < column; j++){
            labyrinth[i][j] = line[j];
        }
    }
    
    //where is G
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < column; j++){
            if (labyrinth[i][j] == 'G'){
                leftRight = i;
                upDown = j;
            }
        }
    }
    
    //find the exit
    while ((assistant != 1) && (labyrinth[leftRight][upDown] != 'S')){
        if (labyrinth[leftRight][upDown+1] == 'V'){
            labyrinth[leftRight][upDown]='T';
            upDown=upDown+1;
        }else if (labyrinth[leftRight][upDown-1] == 'V'){
            labyrinth[leftRight][upDown]='T';
            upDown=upDown-1;
        }else if (labyrinth[leftRight+1][upDown] == 'V'){
            labyrinth[leftRight][upDown]='T';
            leftRight=leftRight+1;
        }else if (labyrinth[leftRight-1][upDown] == 'V'){
            labyrinth[leftRight][upDown]='T';
            leftRight=leftRight-1;
        }else if (labyrinth[leftRight][upDown+1] == 'S'){
            upDown=upDown+1;
            printf("sim\n");
        }else if (labyrinth[leftRight][upDown-1] == 'S'){
            upDown=upDown-1;
            printf("sim\n");
        }else if (labyrinth[leftRight+1][upDown] == 'S'){
            leftRight=leftRight+1;
            printf("sim\n");
        }else if (labyrinth[leftRight-1][upDown] == 'S'){
            leftRight=leftRight-1;
            printf("sim\n");
        }else{
            assistant=1;
            printf("nao\n");
        }
    }
    
    return 0;
}