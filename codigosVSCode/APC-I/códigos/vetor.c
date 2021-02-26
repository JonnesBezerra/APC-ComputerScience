#include <stdio.h>

int main(int argc, char const *argv[]) {
    int tamanho, certo = 1;

    scanf("%d", &tamanho);

    int vetor [tamanho];
    
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < tamanho; i++){
        for(int j = 1; j < vetor[i]; j++){
            if (vetor[i] == j*j){
                vetor[i] = 1;
            }
        }

        if(vetor[i] != 1){
            vetor[i] = 0;
        }
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    if (vetor[0] == 1){
        for(int i = 0; i < tamanho;){
            if (vetor[i] != 1){
                certo = 0;
            }
            i += 2;
        }
        for(int i = 1; i < tamanho;){
            if(vetor[i] != 0){
                certo = 0;
            }
            i += 2;
        }
    }

    if(vetor[0] == 0){
        for(int i = 0; i< tamanho;){
            if (vetor[i] != 0){
                certo=0;
            }
            i += 2;
        }
        for(int i = 1; i < tamanho;){
            if(vetor[i] != 1){
                certo = 0;
            }
            i += 2;
        }        
    }

    if(certo==1){
        printf("O MINISTRO FICA\n");
    }else{
        printf("TROQUE DE MINISTRO\n");
    }
    return 0;
}
