#include<stdio.h>

int main(int argc, char const *argv[]){

    int a1,a2,a3, r, resto, res;

    scanf("%d", &a1);

    for (int i = 1; i <= 10; i++){
        resto=a1%3;
        a1=a1/3;       
        printf("  %d\t", resto);
        
    }
    printf("\n|  1  |   3  |   9  |   27  |   81  |   243  |   729  |  2187  |  6561  | 19683  |");
    
    
    return 0;
}