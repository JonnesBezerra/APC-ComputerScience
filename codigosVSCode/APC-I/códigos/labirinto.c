#include <stdio.h>

int main(int argc, char const *argv[])
{
    int horizontal, vertical, gabriel_vertical, gabriel_horizontal, possibilidade = 4;

    scanf("%d %d", &vertical, &horizontal);

    char labirinto[vertical][horizontal];

    for(int i = 0; i < vertical; i++){
        char labirinto_horizontal[horizontal];
        scanf("%s", labirinto_horizontal);
        for(int j = 0; j < horizontal; j++){
            labirinto[i][j] = labirinto_horizontal[j];
        }
    }

    for(int i = 0; i < vertical; i++){
        for(int j = 0; j < horizontal; j++){
            if (labirinto[i][j] == 'G'){
                gabriel_vertical = i;
                gabriel_horizontal = j;
            }
        }
    }
    
    while(labirinto[gabriel_vertical][gabriel_horizontal] != 'S' && possibilidade != 0){
        if (labirinto[gabriel_vertical][gabriel_horizontal+1] != 'T' && gabriel_horizontal+1 < horizontal){
            labirinto[gabriel_vertical][gabriel_horizontal] = 'T';
            gabriel_horizontal++;
        }else{
            if (labirinto[gabriel_vertical][gabriel_horizontal-1] != 'T' && gabriel_horizontal-1 >= 0){
                labirinto[gabriel_vertical][gabriel_horizontal] = 'T';
                gabriel_horizontal--;
            }else{
                if(labirinto[gabriel_vertical-1][gabriel_horizontal] != 'T' && gabriel_vertical-1 >= 0){
                    labirinto[gabriel_vertical][gabriel_horizontal] = 'T';
                    gabriel_vertical--;
                }else{
                    if(labirinto[gabriel_vertical+1][gabriel_horizontal] != 'T' && gabriel_vertical+1 < vertical){
                        labirinto[gabriel_vertical][gabriel_horizontal] = 'T';
                        gabriel_vertical++;
                    }else{
                        possibilidade = 0;
                    }
                }
            }    
        }
    }
    
    if(labirinto[gabriel_vertical][gabriel_horizontal] == 'S'){
        printf("sim\n");
    }else{
        printf("nao\n");
    }

    return 0;
}