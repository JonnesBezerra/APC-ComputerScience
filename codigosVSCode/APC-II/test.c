#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    float n1,n2;
}aluno;

int main(){
    char name;
    printf("Nome: ");
    scanf("%c", name);
    printf("Nome: %s", name);
    
    return 0;
}