#include <stdio.h>

int main(int argc, char const *argv[]){

    int pa, pb, dist;

    scanf("%d %d", &pa, &pb);

    dist = pb - pa;

    printf("%d\n", dist);

    return 0;
}