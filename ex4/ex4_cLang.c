#include <stdio.h>
#include <stdlib.h>

long long ZERO = 0;
long long V0, V1;
long long A0, A1, A2, A3;
long long T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
long long S0, S1, S2, S3, S4, S5, S6, S7;

int array[5];
int multipliedArray[5];

char string[100];
char changedCaseString[100];

void getTriangle(void);
void checkEvenOrOdd(void);
void multiplyByFour(void);
void changeCase(void);

void main() {
    T0 = 1;
    
    printf("Welcome\n\n");
    
    whileLabel1: if(T0 == ZERO) goto afterWhile1;
    
        printf("Menu\n\n");
        printf("(1) Create a triangle.\n");
        printf("(2) Check if an integer is even or odd.\n");
        printf("(3) Multiply five integers by four.\n");
        printf("(4) Enter the case of a string of characters.\n");
        printf("(5) Exit program.\n\n");
        printf("Please enter your choice (1 - 5): ");
        scanf("%d", &T1);
        
        T2 = 1;
        if(T1 == T2) goto case1;
        T2 = T2 + 1; 
        if(T1 == T2) goto case2;
        T2 = T2 + 1; 
        if(T1 == T2) goto case3;
        T2 = T2 + 1;
        if(T1 == T2) goto case4;
        T2 = T2 + 1;
        if(T1 == T2) goto case5;
        printf("\nChoose between 1 to 5.\n\n\n");
        goto whileLabel1;

        case1:
            printf("\nPlease enter integer N (number of lines): ");
            scanf("%lld", &A0);
            getTriangle();
            T3 = V0;
            printf("\nNumber of elements is: %lld\n\n\n", T3);
            goto whileLabel1; 
        case2: 
            printf("\nPlease enter integer N to be checked: ");
            scanf("%d", &A1);
            checkEvenOrOdd();
            T3 = V0;
            if(T3 <= ZERO) goto elseLabel1;
            printf("\nThis integer is an odd number.\n\n\n");
            goto whileLabel1;
            
            elseLabel1:
                printf("\nThis integer is an even number.\n\n\n");
                goto whileLabel1;
        case3:  
            printf("\nPlease enter the five integers.\n\n");
            T3 = ZERO;
            T4 = 1;
            
            forLoop1:
                if(T3 >= 5) goto afterLoop1;
                printf("Integer %lld: ", T4);
                scanf("%d", &array[T3]);
                T4 = T4 + 1;
                T3 = T3 + 1;
                goto forLoop1;
            
            afterLoop1:
                printf("\n");
                T3 = ZERO;    
                multiplyByFour();
                T4 = 1;
            
            forLoop2:  
                if(T3 >= 5) goto afterLoop2;
                T6 = (long long)multipliedArray[T3];
                printf("Integer %lld multiplied by 4 equals: %lld\n", T4, T6);
                T4 = T4 + 1;
                T3 = T3 + 1;
                goto forLoop2;
            
            afterLoop2: 
                printf("\n\n");
                goto whileLabel1;
        case4: 
            printf("\nPlease enter the string you want to change the case of.\n\n");
            printf("String: ");
            scanf("%s", string);
            changeCase();
            printf("\nChanged case string: %s\n\n\n", changedCaseString);
            goto whileLabel1;
        case5:
            printf("\nProgram terminating.\n\n");
            T0 = ZERO;
            goto whileLabel1;
                
    afterWhile1: 
        return;
}

void getTriangle() {
    S0 = A0;
    S1 = ZERO;
    
    forLoop4: 
        if(S1 > S0) goto afterLoop4;
        S2 = ZERO;
    
    forLoop5:
        if(S2 >= S1) goto afterLoop5;
        S3 = S2 + 1;
        printf("%2lld ", S3);
        S4 = S4 + 1;
        S2 = S2 + 1;
        goto forLoop5;
    
    afterLoop5:
        printf("\n");
        S1 = S1 + 1;
        goto forLoop4;
    
    afterLoop4: 
        V0 = S4;
        S4 = ZERO;
        return;
}

void checkEvenOrOdd() {
    S0 = A1;
    
    whileLabel2:
        if(S0 < 2) goto afterWhile2;
        S0 = S0 - 2;
        goto whileLabel2;
     
    afterWhile2: 
        V0 = S0;
        return;    
}

void multiplyByFour() { 
    S0 = ZERO;
    
    forLoop6: 
        if(S0 > 4) goto afterLoop6;
        multipliedArray[S0] = (int)ZERO;
        S1 = ZERO;
    
    forLoop7:
        if(S1 >= 4) goto afterLoop7;
        S2 = (long long)array[S0];
        S3 = (long long)multipliedArray[S0];
        S3 = S3 + S2;
        multipliedArray[S0] = (int)S3;
        S1 = S1 + 1;
        goto forLoop7;
    
    afterLoop7:
        S0 = S0 + 1;
        goto forLoop6;
    
    afterLoop6:
        return;
}   

void changeCase() {
    S0 = ZERO;
    
    forLoop7:
        if(S0 >= 100) goto afterLoop7;
        if(string[S0] == 0) goto afterLoop7;
        S0 = S0 + 1;
        goto forLoop7;
    
    afterLoop7:
        S1 = ZERO;
    
    forLoop8:
        S2 = (long long)string[S1];
        S5 = (long long)changedCaseString[S1];
        if(S1 >= S0) goto afterLoop8;
        if(S2 < 65) goto elseLabel2;
        if(S2 > 90) goto elseLabel2;
        S5 = S2 + 32;
        changedCaseString[S1] = (char)S5;
        goto endIf;
        
        elseLabel2:
            S5 = S2 - 32;
            changedCaseString[S1] = (char)S5;
            goto endIf;
 
        endIf:
            S1 = S1 + 1;
            goto forLoop8;
            
    afterLoop8:
            return;
}
