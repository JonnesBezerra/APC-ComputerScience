#include <stdio.h>
#include <stdlib.h>

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd);

int main(){
    int *x1, *x2, *x3, n1, n2, qtd = 0, i;

    printf("Digite um valor para a quantidade de elementos em X1: ");
    scanf("%d", &n1);
    printf("Digite um valor para a quantidade de elementos em X2: ");
    scanf("%d", &n2);
    
    x3 = uniao(x1, x2, n1, n2, &qtd);

    printf("Uniao de X1 com X2 = {");
    for (i = 0; i < qtd; i++){
        if ((i+1) == qtd){
            printf("%d}\n", x3[i]);
        } else {
            printf("%d, ", x3[i]);
        }
    }
    printf("Tamanho de X3: %d\n", qtd);

    return 0;
}

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd){
    int *x3;
    x1 = (int *) malloc(n1 * sizeof(int));
    x2 = (int *) malloc(n2 * sizeof(int));
    x3 = (int *) malloc((n1+n2) * sizeof(int));
    
    for (int i = 0; i < n1; i++){
        printf("Insira um valor pro Vetor 1: ");
        scanf("%d", &x1[i]);
    }
    for (int i = 0; i < n2; i++){
        printf("Insira um valor pro Vetor 2: ");
        scanf("%d", &x2[i]);
    }
    int i = 0, j = 0, k = 0;
    while ((i < n1) && (j < n2)){
        if (x1[i] < x2[j]){
            x3[k++] = x1[i];
            i++;
        } else if (x1[i] > x2[j]){
            x3[k++] = x2[j];
            j++;
        } else {
            x3[k++] = x2[j];
            i++, j++;
        }
    }
    while (i < n1)
        x3[k++] = x1[i++];
    while (j < n2)
        x3[k++] = x2[j++];

    //ponteiro qtd retornando o tamanho de x3
    *qtd = k;
        
    return x3;
}