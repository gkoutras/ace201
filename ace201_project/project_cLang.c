#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long ZERO = 0, RA;
long long V0, V1;
long long A0, A1, A2, A3;
long long T0, T1, T2, T3, T4, T5, T6, T7, T8, T9;
long long S0, S1, S2, S3, S4, S5, S6, S7;

char temp[100];
char map[232] = "I.IIIIIIIIIIIIIIIIIIII....I....I.......I.IIII.IIIII.I.I.III.I.II.I.....I..I..I.....II.I.III.II...II.I.IIII...I...III.I...I...IIIIII.IIIII.III.III.II.............I.I...IIIIIIIIIIIIIIII.I.III@...............I..IIIIIIIIIIIIIIIIIIIIIII";

void printLabyrinth(void);
void makeMove(void);

void main() {
    
    S0 = 1;
    S4 = 21;
    S5 = 11;
    
    printf("Welcome to the Labyrinth.\n");
    S1 = S0;
    printLabyrinth();
    
    whileLabel1:    S2 = map[S1];
                    T0 = 64;
                    if(S2 == T0) goto afterWhile1;
                    T0 = 35;
                    if(S2 == T0) goto afterWhile1;
                    printf("\nMove by pressing W, A, S, D or press E for the optimal solution.\n");
                    printf("Please type a command key: ");
                    scanf("%s", &S3);
                    
                    T0 = 87;
                    if(S3 == T0) goto case87; 
                    T0 = 65;
                    if(S3 == T0) goto case65;
                    T0 = 83;
                    if(S3 == T0) goto case83;
                    T0 = 68;
                    if(S3 == T0) goto case68;
                    T0 = 69;
                    if(S3 == T0) goto case69;
                    printf("\nType between your options.\n");
                    goto whileLabel1;
                    
                    case87: if(S1 != S0) goto elseLabel;
                            printf("\nLeaving so soon?\n");
                            goto whileLabel1;
                            elseLabel:  S3 = S1 - S4;
                                        S2 = map[S3];
                                        T0 = 73;
                                        if(S2 != T0) goto elseLabel1;
                                        printf("\nYou cannot walk through walls.\n");
                                        goto whileLabel1; 
                                        elseLabel1: S1 = S1 - S4;
                                                    printLabyrinth();
                                                    goto whileLabel1;
                    case65: S3 = S1 - 1;
                            S2 = map[S3];
                            T0 = 73;
                            if(S2 != T0) goto elseLabel2;
                            printf("\nYou cannot walk through walls.\n");
                            goto whileLabel1; 
                            elseLabel2: S1 = S1 - 1;
                                        printLabyrinth();
                                        goto whileLabel1;
                    case83: S3 = S1 + S4;
                            S2 = map[S3];
                            T0 = 73;
                            if(S2 != T0) goto elseLabel3;
                            printf("\nYou cannot walk through walls.\n");
                            goto whileLabel1; 
                            elseLabel3: S1 = S1 + S4;
                                        printLabyrinth();
                                        goto whileLabel1;
                    case68: S3 = S1 + 1;
                            S2 = map[S3];
                            T0 = 73;
                            if(S2 != T0) goto elseLabel4;
                            printf("\nYou cannot walk through walls.\n");
                            goto whileLabel1; 
                            elseLabel4: S1 = S1 + 1;
                                        printLabyrinth();
                                        goto whileLabel1;
                    case69: A0 = S0;
                            makeMove();
                            printLabyrinth();
                            printf("\n# marks the most optimal path.\n");
                            goto whileLabel1;
                            
    afterWhile1:    S2 = map[S1];
                    T0 = 64;
                    if(S2 == T0)
                    printf("\nWinner Winner Chicken Dinner!\n");
                    return; 
                    
}

void printLabyrinth() {
    
    T0 = ZERO;
    T2 = ZERO;
    
    usleep(200000);
    printf("\nLabyrinth:\n\n");
    
    forLoop1:   if(T0 >= S5) goto afterLoop1;
                T1 = ZERO;
                forLoop2:   if(T1 >= S4) goto afterLoop2;
                            if(T2 != S1) goto elseLabel5;
                            T3 = 80;
                            temp[T1] = T3;
                            goto afterCondition1;
                            elseLabel5:         T3 = map[T2];
                                                temp[T1] = T3;
                                                goto afterCondition1;
                            afterCondition1:    T2 = T2 + 1;
                                                T1 = T1 + 1;
                                                goto forLoop2;
                afterLoop2: T1 = T1 + 1;
                            temp[T1] = ZERO;
                            printf("%s\n", temp);
                            T0 = T0 + 1;
                            goto forLoop1;
    afterLoop1: return;
    
}

void makeMove() {   
    
    int buff[2];
    buff[0] = T4;
    S0 = 231;
    T4 = A0;
    
    if(T4 >= 0) goto afterCondition2;
    V0 = ZERO;
   
    afterCondition2:    if(T4 < S0) goto afterCondition3;
                        V0 = ZERO;
                        
    afterCondition3:    T5 = map[T4];
                        if(T5 != 46) goto elseLabel6;
                        T6 = 42;
                        goto afterCondition4;
                        elseLabel6:         if(T5 != 80) goto elseLabel7;
                                            T6 = 80;
                        afterCondition4:    map[T4] = T6;
                                            printLabyrinth();
                                            
                        A0 = T4 + 1;
                        makeMove();
                        RA = buff[1];
                        T7 = V0;
                        if(T7 == 1) goto afterCondition5;
                        
                        A0 = T4 + S4;
                        makeMove();
                        RA = buff[1];
                        T7 = V0;
                        if(T7 == 1) goto afterCondition5;
                        
                        A0 = T4 - 1;
                        makeMove();
                        RA = buff[1];
                        T7 = V0;
                        if(T7 == 1) goto afterCondition5;
                        
                        A0 = T4 - S4;
                        makeMove();
                        RA = buff[1];
                        T7 = V0;
                        if(T7 == 1) goto afterCondition5;
                        
                        elseLabel7:         T5 = map[T4];
                                            if(T5 != 64) goto afterCondition6;
                                            T9 = 37;
                                            map[T4] = T9;
                                            printLabyrinth();
                                            V0 = 1;
                                            T4 = buff[0];
                                            return;
                        afterCondition5:    T8 = 35;
                                            map[T4] = T8;
                                            V0 = 1;
                                            T4 = buff[0];
                                            return;
                        afterCondition6:    V0 = 0;
                                            T4 = buff[0];
                                            return;
                                            
}