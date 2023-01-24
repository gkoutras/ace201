#include <stdio.h> 
#include <stdlib.h> 

struct str1 {
    char x;
    int c;
    char y;
};

struct str2 {
    char x;
    char y;
    int c;
};

int main(void) {  
    
    struct str1 a;
    struct str2 b;
    printf("Size of structure str1 is: %d\nSize of structure str2 is: %d\n" 
            , sizeof(a), sizeof(b));
    
    return 0; 
    
} 