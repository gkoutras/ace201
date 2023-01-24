#include <stdio.h>
#include <stdlib.h>

int a; 

int main() {
    
    int b; 
    int * c = (int *) malloc(sizeof(10)); 
    
    /* Data memory (low addresses) */
    printf("Main function is stored in address: %#010x\n", main); 
    /* Data memory (low addresses) */
    printf("Global integer a is stored in address: %#010x\n", &a);
    /* Stack memory (high addresses) */
    printf("Local integer b is stored in address: %#010x\n", &b);
    /* Heap memory */
    printf("Dynamically allocated pointer c is stored in address: %#010x\n", c);

    free(c);

    return 0;
    
}

