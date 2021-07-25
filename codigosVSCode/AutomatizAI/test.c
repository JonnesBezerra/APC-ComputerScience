#include <stdio.h>
#include <stdlib.h> //necessário para usar as funções malloc() e free()
#include <conio.h>

typedef struct Tipo{
    char *c;
} Tipo;


int main(void){
    
    float in[2][2] = {2.0,  1.5,
                      1.25, 1.0};
    float fl[2] = {2.5};
    float conta, soma = 0.0;
    
    /* for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%.2f ", in[i][j]);
        }
        printf("\n");
    } */

    /* for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%.2f ", conta);
            conta += (in[i] * fl[j]);
            soma += conta;
            printf("%.2f\n", conta);
            printf("%.2f\n", soma);
        }
    } */
    
    //printf("%.2f\n", conta);
    /* for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("%d", conta);
        }
        
    } */
    
    /* int a = 2;
    float b = 2.5, c;
    c = (20.0 / 200);
    printf("%.2f %.2f\n", (b/a), c); */

    int total = 0.0, dev, intern;
    int manager, vector[4];

    scanf("%d", &dev);
    vector[0] = dev;
    vector[1] = intern;
    vector[2] = manager;
 
    /* for (int i = 0; i < 2; i++){
        printf("%d\n", (vector[i]));
    } */
    vector[2] = (vector[0] % 12);
    vector[4] = (vector[0] / 12);

    printf("%d %d", vector[4], vector[2]);

	return 0;
}