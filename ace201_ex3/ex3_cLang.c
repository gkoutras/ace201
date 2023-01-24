#include <stdio.h>
#include <stdlib.h>

long long ZERO = 0;
long long V0, V1;
long long A0, A1, A2, A3;
long long T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
long long S0, S1, S2, S3, S4, S5, S6, S7;
long long RA;

long long array[5];
long long multipliedArray[5];

void getTriangle(void);
void checkEvenOrOdd(void);
void multiplyByFour(void);

void main() {
    S0 = 1;
    
    printf("Welcome\n\n");
    
    whileLabel: if(S0 == ZERO) goto afterWhile;
    
        printf("Menu\n\n");
        printf("(1) Create a triangle.\n");
        printf("(2) Check if an integer is even or odd.\n");
        printf("(3) Enter five integers and check their value multiplied by five.\n");
        printf("(4) Exit program.\n\n");
        printf("Please enter your choice (1 - 4): ");
        scanf("%d", &S1);
        
        S2 = 1;
        if(S1 == S2) goto case1;
        S2 = S2 + 1; 
        if(S1 == S2) goto case2;
        S2 = S2 + 1; 
        if(S1 == S2) goto case3;
        S2 = S2 + 1;
        if(S1 == S2) goto case4;
        printf("\nChoose between 1 to 4.\n\n\n");
        goto whileLabel;

        case1:
            printf("\nPlease enter integer N (number of lines): ");
            scanf("%lld", &A0);
            getTriangle();
            printf("\nNumber of elements is: %lld\n\n\n", V0);
            goto whileLabel; 
        case2: 
            printf("\nPlease enter integer N to be checked: ");
            scanf("%d", &A1);
            checkEvenOrOdd();
            
            S3 = V0;
            if(S3 <= ZERO) goto elseLabel;
            printf("This integer is an odd number.\n\n\n");
            goto whileLabel;
            
            elseLabel:
                printf("This integer is an even number.\n\n\n");
                goto whileLabel;
        case3:  
            printf("\nPlease enter the five integers.\n");
            S4 = ZERO;
            S5 = 5;
            
            forLoop1:
                if(S4 >= S5) goto afterLoop1;
                S6 = S4 + 1;
                printf("Integer %lld: ", S6);
                scanf("%lld", &array[S4]);
                S4 = S4 + 1;
                goto forLoop1;
            
            afterLoop1:
                printf("\n");
                S4 = ZERO;
           
            forLoop2:  
                if(S4 >= S5) goto afterLoop2;
                S6 = S4 + 1;
                multiplyByFour();
                printf("Integer %lld (%lld) multiplied by 4 equals: %lld\n", S6, array[S4], multipliedArray[S4]);
                S4 = S4 + 1;
                goto forLoop2;
            
            afterLoop2: 
                printf("\n\n");
                goto whileLabel;
        case4: 
            printf("\nProgram terminating.\n\n");
            S0 = ZERO;
            goto whileLabel;
                
    afterWhile: 
        return;
}

void getTriangle() {
    T0 = ZERO;
    T3 = A0;
    T4 = ZERO;
    
    forLoop1: 
        if(T0 > T3) goto afterLoop1;
        T1 = ZERO;
    
    forLoop2:
        if(T1 >= T0) goto afterLoop2;
        T2 = T1 + 1;
        printf("%2lld ", T2);
        T4 = T4 + 1;
        T1 = T1 + 1;
        goto forLoop2;
    
    afterLoop2:
        printf("\n");
        T0 = T0 + 1;
        goto forLoop1;
    
    afterLoop1: 
        V0 = T4;
        return;
}

void checkEvenOrOdd() {
    T0 = A1;
    T1 = 2;
    
    if(T0 < T1) goto afterCondition;
    T2 = T0 - T1;
    A1 = T2;
    checkEvenOrOdd();
     
    afterCondition: 
        V0 = A1;
        return;
        
}

void multiplyByFour() { 
    T0 = ZERO;
    T1 = 4;
    
    forLoop1: 
        if(T0 > T1) goto afterLoop1;
        multipliedArray[T0] = ZERO;
        T2 = ZERO;
    
    forLoop2:
        if(T2 >= T1) goto afterLoop2;
        T3 = array[T0];
        T4 = multipliedArray[T0];
        T4 = T4 + T3;
        multipliedArray[T0] = T4;
        T2 = T2 + 1;
        goto forLoop2;
    
    afterLoop2:
        T0 = T0 + 1;
        goto forLoop1;
    
    afterLoop1:
        return;
}   
