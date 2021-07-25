#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[30], gender[20];
    int age, compare;

    printf("Digite seu nome: ");
    fgets(name, 30, stdin);
    printf("Digite seu genero: ");
    fgets(gender, 20, stdin);
    printf("Digite sua idade: ");
    scanf("%d", &age);

    name[strlen(name)-1] = '\0';
    gender[strlen(gender)-1] = '\0';
    compare = strcmp(gender, "feminino");

    if (compare == 0 && age < 25){
        printf("%s ACEITA\n", name);
    } else {
        printf("NAO ACEITA\n");
    }

    return 0;
}