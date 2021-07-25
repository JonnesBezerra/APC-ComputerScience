#include <stdio.h>
#include <stdlib.h>

void readElements(int *vector, int n);

int main(){

    int n, *vector;

    printf("Digite um valor para a quantidade de elementos no vetor: ");
    scanf("%d", &n);

    //alocando dinamicamente o vetor
    vector = (int *) malloc(n * sizeof(int));

    readElements(vector, n);

    //impressao do vetor lido
    printf("Vetor lido: [");
    for (int i = 0; i < n; i++){
        if ((i+1) == n){
            printf("%d]\n", vector[i]);
        } else {
            printf("%d, ", vector[i]);
        }
    }

    return 0;
}

//funcao que lê os elementos do vetor
void readElements(int *vector, int n){
    for (int i = 0; i < n; i++){
        printf("Insira um valor na posicao %d do vetor: ", i);
        scanf("%d", &vector[i]);
    }
}