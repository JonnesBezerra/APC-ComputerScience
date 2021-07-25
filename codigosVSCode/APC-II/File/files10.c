#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void copy_file(FILE *f);

int main(){

    FILE *f;
    char input[50];

    for (int i = 0; i < 2; i++){
        printf("File number %d: ", i+1);
        fgets(input, 50, stdin);
        input[strlen(input)-1] = '\0';
        strcat(input, ".txt");
        f = fopen(input, "r");
        if (f == NULL){
            printf("Error in file %d!", i+1);
            return 0;
        }
        copy_file(f);
        fclose(f);
    }

    return 0;
}

void copy_file(FILE *f){
    char line[10000];
    FILE *out;
    out = fopen("out.txt", "a+");
    if (out == NULL){
        printf("Error opening the file!");
    }
    while (fgets(line, 10000, f) != NULL){
        fprintf(out, "%s", line);
    }
    fprintf(out, "\n");
    fclose(out);
}