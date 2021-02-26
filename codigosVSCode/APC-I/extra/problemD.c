#include <stdio.h>

int conventionTime(int clown, int clownTime, int biroSpeeches, int biroTime ){
    return ((clown * clownTime) + (biroSpeeches * biroTime));
}

int main(int argc, char const *argv[]){

    int tests, clown, clownTime, biroSpeeches, biroTime;

    scanf("%d", &tests);
    int schedule[tests][1];

    for (int i = 0; i < tests; i++){
        scanf("%d %d %d %d", &clown, &clownTime, &biroSpeeches, &biroTime);
        schedule[i][1] = conventionTime(clown, clownTime, biroSpeeches, biroTime);
    }
    
    for(int i = 0; i < tests; i++){
        printf("%d\n", schedule[i][1]);
    }

    return 0;
}