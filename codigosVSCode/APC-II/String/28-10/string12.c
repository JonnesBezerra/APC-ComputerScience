#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[1000], word2[1000];
    int i;

    printf("String: ");
    fgets(string, sizeof(string), stdin);
    
    for (i = 0; i < strlen(string); i++){
        if ((string[i] >= 'a') && (string[i] <= 'z')){
            string[i] -= 29;
        }
    }
    
    printf("%s", string);

    return 0;
}