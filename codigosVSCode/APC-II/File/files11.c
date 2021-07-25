#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct city {
    char cityName[45];
    long int population;
} city;

void get_largest(FILE *in, city *largest);

int main(){

    FILE *in, *out;
    city largest;
    char inName[50], outName[50];

    printf("Input file name: ");
    fgets(inName, 50, stdin);
    fflush(stdin);
    inName[strlen(inName) - 1] = '\0';
    strcat(inName, ".txt");

    printf("Output file name: ");
    fgets(outName, 50, stdin);
    fflush(stdin);
    outName[strlen(outName) - 1] = '\0';
    strcat(outName, ".txt");

    in = fopen(inName, "r");
    if (in == NULL){
        printf("Error in the IN file!\n");
        return 0;
    }

    get_largest(in, &largest);
    printf("\n%s %ld\n", largest.cityName, largest.population);

    out = fopen(outName, "w");
    if (out == NULL){
        printf("Error in the OUT file!\n");
        return 0;
    } else {
        fprintf(out, "%s %ld", largest.cityName, largest.population);
    }
    fclose(in);
    fclose(out);

    return 0;
}

void get_largest(FILE *in, city *largest){
    largest->population = 0;
    char fileCity[45];
    int filePopulation;
    while (!feof(in)){
        fscanf(in,"%s %ld", fileCity, &filePopulation);
        printf("%s %ld ", fileCity, filePopulation);
        if (filePopulation > largest->population){
            largest->population = filePopulation;
            strcpy(largest->cityName, fileCity);
            printf("\n%s %ld ", largest->cityName, largest->population);
        }
    }
    
}