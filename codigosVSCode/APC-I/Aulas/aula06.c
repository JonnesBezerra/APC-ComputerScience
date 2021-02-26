#include <stdio.h>

int main(int argc, char const *argv[]){

    int manyPeople, nameSize, surnameSize, back, front;
    char name[1000], inverseName[1000], surname[1000];

    scanf("%d", &manyPeople);

    for (int i = 0; i < manyPeople; i++){

        scanf("%s", name);
        scanf("%s", surname);

        nameSize = 0;
        while (name[nameSize] != '\0'){
            nameSize++;
        }

        surnameSize = 0;
        while (surname[surnameSize] != '\0'){
            surnameSize++;
        }

        back = nameSize-1;
        front = 0;
        while ( back > -1 ){
            // Fiz 2 IFs de filtro de vogais pq achei que fica mais elegante do que maiúsculas e minusculas na mesma linha grandão
            if(name[back] != 'A' && name[back] != 'E' && name[back] != 'I' && name[back] != 'O' && name[back] != 'U'){
                if (name[back] != 'a' && name[back] != 'e' && name[back] != 'i' && name[back] != 'o' && name[back] != 'u' ){
                    inverseName[front] = name[back];
                    back--;
                } else {
                    back--;
                    front--;
                }
            } else {
                back--;
                front--;
            }
            front++;
        }

        inverseName[front] = '\0';
        printf("%s%d\n", inverseName, surnameSize);
    }

    return 0;
}