#include <stdio.h>
#include <stdlib.h>


typedef struct coordenada{
    int x, y;
} coordenada;


int main(){
    coordenada lista1_coordenadas[3], lista2_coordenadas[3];
    
    for (int i = 0; i < 3; i++){
        scanf("%d", lista1_coordenadas[i].x);
        scanf("%d", lista1_coordenadas[i].y);
    }
    
    for (int i = 0; i < 3; i++){
        scanf("%d", lista2_coordenadas[i].x);
        scanf("%d", lista2_coordenadas[i].y);
    }

    return 0;
}

void recebe_listas(coordenada lista1[], coordenada lista2[]){
    int primeiro = 0, segundo = 0, terceiro = 0, quarto = 0, eixox1 = 0, eixoy1 = 0, eixox2 = 0, eixoy2 = 0;
    int lista1qdt1 = 0, lista1qdt2 = 0, lista1qdt3 = 0, lista1qdt4 = 0;
    int lista2qdt1 = 0, lista2qdt2 = 0, lista2qdt3 = 0, lista2qdt4 = 0;
    for (int i = 0; i < 3; i++){
        if((lista1[i].x > 0) && (lista1[i].y > 0)){
            primeiro++;
            lista1qdt1++;
        } else if ((lista1[i].x < 0) && (lista1[i].y > 0)){
            segundo++;
            lista1qdt2++;
        } else if ((lista1[i].x < 0) && (lista1[i].y < 0)){
            terceiro++;
            lista1qdt3++;
        } else if ((lista1[i].x > 0) && (lista1[i].y < 0)){
            quarto++;
            lista1qdt4++;
        } else if (lista1[i].x = 0){
            eixox1++;
        } else if (lista1[i].y = 0){
            eixoy1++;
        }
        

        if((lista2[i].x > 0) && (lista2[i].y > 0)){
            primeiro++;
            lista2qdt1++;
        } else if ((lista2[i].x < 0) && (lista2[i].y > 0)){
            segundo++;
            lista2qdt2++;
        } else if ((lista2[i].x < 0) && (lista2[i].y < 0)){
            terceiro++;
            lista2qdt3++;
        } else if ((lista2[i].x > 0) && (lista2[i].y < 0)){
            quarto++;
            lista2qdt4++;
        } else if (lista1[i].x = 0){
            eixox2++;
        } else if (lista1[i].y = 0){
            eixoy2++;
        }
    }

    if ((primeiro > segundo) && (primeiro > terceiro) && (primeiro > quarto)){
        printf("O 1st quadrante é o que tem mais ocorrencias, com %d ocorrencias.", primeiro);
    } else if ((segundo > primeiro) && (segundo > terceiro) && (segundo > quarto)){
        printf("O 2nd quadrante é o que tem mais ocorrencias, com %d ocorrencias.", segundo);
    } else if ((terceiro > primeiro) && (terceiro > segundo) && (terceiro > quarto)){
        printf("O 3rd quadrante é o que tem mais ocorrencias, com %d ocorrencias.", terceiro);
    } else if ((terceiro > primeiro) && (terceiro > segundo) && (terceiro > quarto)){
        printf("O 4th quadrante é o que tem mais ocorrencias, com %d ocorrencias.", quarto);
    } else {
        printf("Nenhum quadrante tem mais ocorrências que todos outros.");
    }
    
    if (eixox1 > eixox2){
        printf("Lista 1 tem mais ocorrencias no eixo X: %d", eixox1);
    } else if (eixox2 > eixox1){
        printf("Lista 2 tem mais ocorrencias no eixo X: %d", eixox2);
    } else {
        printf("As duas listas tem a mesma quantidade de ocorrencias no eixo X");
    }
    
    if (eixoy1 > eixoy2){
        printf("Lista 1 tem mais ocorrencias no eixo Y: %d", eixoy1);
    } else if (eixoy2 > eixoy1){
        printf("Lista 2 tem mais ocorrencias no eixo Y: %d", eixoy2);
    } else {
        printf("As duas listas tem a mesma quantidade de ocorrencias no eixo Y");
    }
    
    if (lista1qdt1 > lista2qdt1){
        printf("Lista 1 possui mais ocorrencias no 1st quadrante.");
    } else if (lista2qdt1 > lista1qdt1){
        printf("Lista 2 possui mais ocorrencias no 1st quadrante.");
    }
    
    
    
        
}

void mostrar_quadrante(coordenada x){

}