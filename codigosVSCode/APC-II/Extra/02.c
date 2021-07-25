#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct modelo{
    char nome[33];
    char sexo;
    char corOlhos;
    float altura;
    float peso;
} modelo;

void data(char line[], modelo *m);

int main(){

    modelo mod;
    FILE *f, *bf, *bm;
    char line[1000];

    f = fopen("dados.txt", "r");
    bf = fopen("Fbinary.bin", "wb");
    bm = fopen("Mbinary.bin", "wb");
    
    if (f == NULL){
        printf("Erro no arquivo de texto!\n");
        return 0;
    }
    if (bf == NULL){
        printf("Erro no arquivo binario!");
        return 0;
    }
    
    while (fgets(line, 1000, f) != NULL){
        data(line, &mod);
        if (mod.sexo == 'F'){
            fwrite(&mod.nome, sizeof(mod.nome), 1, bf);
            fwrite(&mod.sexo, sizeof(mod.sexo), 1, bf);
            fwrite(&mod.corOlhos, sizeof(mod.corOlhos), 1, bf);
            fwrite(&mod.altura, sizeof(mod.altura), 1, bf);
            fwrite(&mod.peso, sizeof(mod.peso), 1, bf);
            printf("n: %s s: %c c: %c a: %.2f p: %.2f\n", mod.nome, mod.sexo, mod.corOlhos, mod.altura, mod.peso);
        } else if (mod.sexo == 'M'){
            fwrite(&mod.nome, sizeof(mod.nome), 1, bm);
            fwrite(&mod.sexo, sizeof(mod.sexo), 1, bm);
            fwrite(&mod.corOlhos, sizeof(mod.corOlhos), 1, bm);
            fwrite(&mod.altura, sizeof(mod.altura), 1, bm);
            fwrite(&mod.peso, sizeof(mod.peso), 1, bm);
            printf("n: %s s: %c c: %c a: %.2f p: %.2f\n", mod.nome, mod.sexo, mod.corOlhos, mod.altura, mod.peso);
        }
        
        
    }
            
    fclose(f);
    fclose(bf);
    fclose(bm);

    return 0;
}

void data(char line[], modelo *m){
    char strTall[4], strWeight[5];
    int i;
    for (i = 0; i < strlen(line); i++){
        if (((line[i] >= 'a') && (line[i] <= 'z')) || ((line[i] >= 'A') && (line[i] <= 'Z'))){
            m->nome[i] = line[i];
        }
    }
    m->nome[30] = '\0';

    m->sexo = line[30];
    m->corOlhos = line[31];

    int j = 33;
    for (i = 0; i < 4; i++){
        strTall[i] = line[j++];
    }
    m->altura = atof(strTall);

    j = 38;
    for (i = 0; i < 5; i++){
        strWeight[i] = line[j++];
    }
    m->peso = atof(strWeight);
}