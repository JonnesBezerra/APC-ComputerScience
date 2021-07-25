#include <stdio.h>
#include <stdlib.h>

int main(){

    int a=5, b=12, c=5;
    int *p;
    int *q;
    p = &a;
    q = &b;
    //(*pe)++;
    c = *p + *q;

    printf("a:%d b:%d c:%d *p:%d *q:%d p:%d &a:%d q:%d &b:%d", a, b, c, *p, *q, p, &a, q, &b);


    /* free(p);
    free(q); */

    return 0;
}