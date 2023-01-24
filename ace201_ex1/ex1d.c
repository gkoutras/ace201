#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int * a, * b, * c, * d; 
    
    a = (int *) malloc(1);
    printf("Pointer a points at: %d\n", a);
    
    b = (int *) malloc(10);
    printf("Pointer b points at: %d\n", b);
    
    c = (int *) malloc(16);
    printf("Pointer c points at: %d\n", c);
    
    d = (int *) malloc(32);
    printf("Pointer d points at: %d\n", d);
    
    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
 
}

