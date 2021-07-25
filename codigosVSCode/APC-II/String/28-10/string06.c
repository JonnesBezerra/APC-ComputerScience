#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char cars[5][100];
    float fuel[5], kml;
    int aux;

    for (int i = 0; i < 5; i++){
        printf("Digite o nome do carro: ");
        fgets(cars[i], 100, stdin);
        int j=0;
        while (cars[i][j] != '\n'){
            j++;
        }
        cars[i][j] = '\0';
    }
    
    for (int i = 0; i < 5; i++){
        printf("Km/L do %s: ", cars[i]);
        scanf("%f", &fuel[i]);
    }

    kml = fuel[0];
    for (int i = 0; i < 4; i++){
        if (fuel[i] > kml){
            kml = fuel[i];
            aux = i;
        }
    }
    
    printf("a) Modelo mais economico: %s Fazendo %.2fKm/L\n", cars[aux], kml);

    for (int i = 0; i < 5; i++){
        printf("b) O carro %s consome %.2f Litros por 1000Km\n", cars[i], (1000/fuel[i]));
    }
    
    return 0;
}