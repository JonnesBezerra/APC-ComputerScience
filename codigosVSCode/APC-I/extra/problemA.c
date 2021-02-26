#include<stdio.h>

int main(int argc, char const *argv[]){

    int width, length, lentorians = 0, pixel;

    scanf("%d %d", &width, &length);
    int photo[width][length];

    //receive Lentorians
    for (int i = 0; i < width; i++){
        for(int j = 0; j < length; j++){
            scanf("%d", &pixel);
            photo[i][j] = pixel;
        }
    }
    //count lentorians
    for (int i = 0; i < width; i++){
        for (int j = 0; j < length; j++){
            if (photo[i][j] == 1){
                lentorians += 1;
            }
        }
    }

    printf("%d\n", lentorians);
    



    return 0;

}