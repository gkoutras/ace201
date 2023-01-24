#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int A[10];  /* Array A of 10 integers */   
    
    printf("Element A[0] is stored in (hex) address : %x\n", A);
    printf("Element A[1] is stored in (hex) address : %x\n", A + 1);
    printf("Element A[1] is stored in (hex) address : %x\n", (int)A + 1);
    printf("Element A[1] is stored in (hex) address : %x\n", &A[1]);
    
    printf("\nSize of the 10-integer array A is : %d\n", sizeof(A));
    printf("Size of element A[0] is : %d\n", sizeof(A[0]));
    
    return 0;
   
}

