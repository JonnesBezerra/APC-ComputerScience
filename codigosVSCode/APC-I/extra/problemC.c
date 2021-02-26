#include<stdio.h>

int main(int argc, char const *argv[]){

    int manyTexts, textSize, manyVowels;

    scanf("%d", &manyTexts);
    char text[manyTexts][1000];
    int output[manyTexts];

    for (int i = 0; i < manyTexts; i++){
        scanf("%s", text[i]);

        textSize = 0;
        while (text[i][textSize] != '\0'){
            textSize++;
        }

        manyVowels = 0;
        for (int j = 0; j < textSize; j++){
            if (text[i][j] == 'a' || text[i][j] == 'e' || text[i][j] == 'i' || text[i][j] == 'o' || text[i][j] == 'u' || text[i][j] == 'A' || text[i][j] == 'E' || text[i][j] == 'I' || text[i][j] == 'O' || text[i][j] == 'U'){
                manyVowels++;
            }
        }

        if (manyVowels != 0){
            if (textSize % 2 == 0){
                if (textSize % manyVowels == 0){
                    output[i] = 1;
                } else {
                    output[i] = 0;
                }
            } else {
                output[i] = 0;
            }
        } else {
            output[i] = 0;
        }
    }

    for (int i = 0; i < manyTexts; i++){
        if (output[i] == 1){
            printf("hahaha\n");
        } else {
            printf("assim nao po\n");
        }
    }

    return 0;
}