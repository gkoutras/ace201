#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int W = 21;
int H = 11;
int startX = 1;
int totalElements = 231;
int playerPos;

char temp[100];
char map[232] = "I.IIIIIIIIIIIIIIIIIII"
                "I....I....I.......I.I"
                "III.IIIII.I.I.III.I.I"
                "I.I.....I..I..I.....I"
                "I.I.III.II...II.I.III"
                "I...I...III.I...I...I"
                "IIIII.IIIII.III.III.I"
                "I.............I.I...I"
                "IIIIIIIIIIIIIII.I.III"
                "@...............I..II"
                "IIIIIIIIIIIIIIIIIIIII";

void printLabyrinth(void);
int makeMove(int);

void main() {
    
    char choice;
    printf("Welcome to the Labyrinth.\n");
    playerPos = startX;
    printLabyrinth();
    while( (map[playerPos] != 64) && (map[playerPos] != 35) ) {
        printf("\nMove by pressing W, A, S, D or press E for the optimal solution.\n");
        printf("Please type a command key: ");
        scanf("%s", &choice);
        switch(choice) {
            case 87:
                if(playerPos == startX) {
                    printf("\nLeaving so soon?\n");
                } else if(map[playerPos - W] == 73) {
                    printf("\nYou cannot walk through walls.\n");
                } else {
                    playerPos -= W;
                    printLabyrinth();
                } break;
            case 65:
                if(map[playerPos - 1] == 73) {
                    printf("\nYou cannot walk through walls.\n");
                } else {
                    playerPos -= 1;
                    printLabyrinth();
                } break;
            case 83:
                if(map[playerPos + W] == 73) {
                    printf("\nYou cannot walk through walls.\n");
                } else {
                    playerPos += W;
                    printLabyrinth();
                } break;
            case 68:
                if(map[playerPos + 1] == 73) {
                    printf("\nYou cannot walk through walls.\n");
                } else {
                    playerPos += 1;
                    printLabyrinth();
                } break;
            case 69:
                makeMove(startX);
                printLabyrinth();
                printf("\n# marks the most optimal path.\n");
                break;
            default:
                printf("\nType between your options.\n");
        }          
    }
    if(map[playerPos] == 64)
        printf("\nWinner Winner Chicken Dinner!\n");
    return;
    
}

void printLabyrinth() {
    
    int i ,j ,k = 0;
    usleep(200000);
    printf("\nLabyrinth:\n\n");
    for(i = 0; i < H; i++) {
        for(j = 0; j < W; j++) {
            if(k == playerPos)
                temp[j] = 80;
            else 
                temp[j] = map[k];
            k++;
        }
        temp[j + 1] = '\0';
        printf("%s\n", temp);
    } 
    
}

int makeMove(int index) {
    
    if( (index < 0) || (index >= totalElements) )
        return 0;
    
    if( (map[index] == 46) || (map[index] == 80) ) {
        if(map[index] == 80)
            map[index] = 80;
        else 
            map[index] = 42;
        printLabyrinth();
        if(makeMove(index + 1) == 1) {
            map[index] = 35;
            return 1;
        }
        if(makeMove(index + W) == 1) {
            map[index] = 35;
            return 1;
        }
        if(makeMove(index - 1) == 1) {
            map[index] = 35;
            return 1;
        }
        if(makeMove(index - W) == 1) {
            map[index] = 35;
            return 1;
        }
    } else if(map[index] == 64) {
        map[index] = 37;
        printLabyrinth();
        return 1;
    } 
    return 0;
    
}

