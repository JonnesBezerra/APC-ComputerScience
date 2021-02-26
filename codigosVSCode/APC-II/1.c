#include<stdio.h>
#include<stdlib.h>

typedef struct coordenada{
    int x, y;
}coordenada;

void preenche_coordenada(coordenada *x);
void mostra_quadrante(coordenada x);

int main(){

    int i;
    coordenada coordenadas[10];

    for (i = 0; i < 10; i++){
        preenche_coordenada(&coordenadas[i]);
        mostra_quadrante(coordenadas[i]);
    }


    return 0;
}

void preenche_coordenada(coordenada *x ){
    printf("Ponto X: ");
    scanf("%d", &(*x).x);
    printf("Ponto Y: ");
    scanf("%d", &x->y);
}

void mostra_quadrante(coordenada x){
    if ((x.x > 0) && (x.y > 0)){
        printf("Coordenada no primeiro quadrante.\n");
    } else if ((x.x < 0) && (x.y > 0)){
        printf("Coordenada no segundo quadrante.\n");
    } else if ((x.x < 0) && (x.y < 0)){
        printf("Coordenada no terceiro quadrante.\n");
    } else if ((x.x > 0) && (x.y < 0)){
        printf("Coordenada no quarto quadrante.\n");
    } else if ((x.x == 0) && (x.y != 0)){
        printf("Coordenada sobre o eixo X\n");
    } else if ((x.y == 0) && (x.x != 0)){
        printf("Coordenada sobre o eixo Y\n");
    } else if ((x.x == 0) && (x.y == 0)){
        printf("Coordenada no ponto neutro\n");
    }
}