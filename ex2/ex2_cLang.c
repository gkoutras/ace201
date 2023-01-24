#include <stdio.h> 
#include <stdlib.h>
 
long long R0 = 0, R14 = 1, R31=(-1);
long long R1, R2, R3, R4, R5, R6, R7, 
        R8, R9, R10, R11, R12, R13, R15, 
        R16, R17, R18, R19, R20, R21, R22, 
        R23, R24, R25, R26, R27, R28, R29, R30;
 
typedef struct list {
short id;
int value;
struct list *next;
} Node;

void printMenu();
void printList(long long);
long long createLinkedList(long long);
long long insertElement(long long);
long long deleteElement(long long);
void searchElement(long long);
void getNumberOfElements(long long);
void getAddressOfElement(long long);
long long exitProgram();

void main() {
    
    Node *head = (Node *)(-1);
    
    R1 = 1;
    R3 = (long long)head;
    
    while_label: if(R1 == R0) goto after_loop;
        printMenu();
        
        scanf("%d", &R4);
        R5 = 1;
        
        switch_label: 
        if(R4 == R5) goto case1;
            R5 = R5 + 1; 
        if(R4 == R5) goto case2;
            R5 = R5 + 1; 
        if(R4 == R5) goto case3;
            R5 = R5 + 1; 
        if(R4 == R5) goto case4;
            R5 = R5 + 1; 
        if(R4 == R5) goto case5;
            R5 = R5 + 1; 
        if(R4 == R5) goto case6;
            R5 = R5 + 1; 
       if(R4 == R5) goto case7;
            printf("Choose between 1 to 7.\n\n");
            goto while_label;

        case1: R3 = createLinkedList(R3);
            head = (Node *)R3; 
            goto while_label; 
        case2: R3 = insertElement(R3);
            head = (Node *)R3; 
            goto while_label;
        case3: R3 = deleteElement(R3);
            head = (Node *)R3; 
            goto while_label;
        case4: searchElement(R3);
            goto while_label;
        case5: getNumberOfElements(R3);
            goto while_label;
        case6: getAddressOfElement(R3);
            goto while_label;
        case7: R1 = exitProgram();
            goto while_label;
        
    goto while_label;
        
    after_loop: return;
    
}

void printMenu() {
    printf("Menu\n\n");
    printf("(1) Create a linked list.\n");
    printf("(2) Insert an element ascendingly into the list.\n");
    printf("(3) Delete an existing element from the list.\n");
    printf("(4) Check the existence of an element.\n");
    printf("(5) Print the number of all sorted elements in the list.\n");
    printf("(6) Print the address of a chosen element.\n");
    printf("(7) Exit program.\n\n");
    printf("Please enter your choice (1 - 7): ");
}

void printList(long long R7) {
    Node *node = (Node *)R7; 
    R6 = (long long)node;
    
    printf("List: ");
    
    while_label: if(R6 == R31) goto after_loop;
        R8 = node->value;
        R9 = node->id;
        printf("(%hd) %d -> ", (short)R9, (int)R8);
        node = node->next;
        R6 = (long long)node;
        goto while_label;
    
    after_loop: printf("(NULL node) -1\n");
}

long long createLinkedList(long long R7) {
    int i = 0;
    
    R7 = R31;
    R10 = i;
    R10 = R0;
    R11 = 5;
    
    loop_label: if(R10 >= R11) goto after_loop;
        R7 = insertElement(R7);
        R10 = R10 + 1;
        goto loop_label;
    
    after_loop: R2 = R7;
        return R2;
}

long long insertElement(long long R7) {
    Node *node;
    Node *tmp = (Node *)R7;
    
    printf("Enter a new element's value to be sorted: ");
    scanf("%d", &R12);
    
    R13 = (long long) malloc(sizeof(Node));
    node = (Node *)R13;
    
    node->value = R12;
    node->id = R14;
    R14 = R14 + 1;
    
    if(R7 != R31) goto and_cond;
        node->next = (Node *)R7;
        goto after_if;
    
    and_cond: if(tmp->value < R12) goto end_if;
        node->next = (Node *)R7;
        goto after_if;
            
    after_if: R13 = (long long)node;
        printList(R13);
        printf("\n");
        R2 = R13;
        return R2;
        
    end_if: while_label:
        if(tmp->next == (Node *)R31) goto after_loop;
            if(tmp->next->value >= R12) goto after_loop;
                tmp = tmp->next;
                goto while_label;
     
    after_loop: 
    node->next = tmp->next;
    tmp->next = node;
    
    printList(R7);
    printf("\n");
    
    R2 = R7;
    return R2;
}

long long deleteElement(long long R7) {
    Node *node = (Node *)R7;
    Node *tmp = (Node *)R7;
    
    printf("Enter the element's ID that is to be deleted: ");
    scanf("%hd", &R15);
    
    if(R7 != R31) goto after_if_label1;
        printf("This list is empty.\n");
        R2 = R31;
        return R2;
        
    after_if_label1: R16 = node->id;
        if(R16 != R15) goto after_if_label2;
            tmp = node->next;
            free(node);
            R17 = (long long)tmp;
            printList(R17);
            printf("\n");
            R2 = R17;
            return R2;
            
        after_if_label2: while_label:
            if(tmp->next == (Node *)R31) goto if_label;
                R18 = tmp->next->id;
                if(R18 == R15) goto if_label;
                    tmp = tmp->next;
                    goto while_label;
                        
            if_label: if(tmp->next != (Node *)R31) goto end_if;
                printf("This ID is wrong.\n");
                R2 = R7;
                return R2;
                    
            end_if: node = tmp->next;
                tmp->next = node->next;
                free(node);
                printList(R7);
                printf("\n");
                R2 = R7;
                return R2;
}

void searchElement(long long R7) {
    Node *node = (Node *)R7;
    R19 = (long long)node;
    
    printf("Enter an element's value to be checked: ");
    scanf("%d", &R20);
    
     while_label:        
        if(R19 == R31) goto after_loop; 
            R21 = node->value;
            R22 = node->id;
            if(R21 != R20) goto after_if_label;
                printf("Element exist at node with ID of %hd\n", (short)R22);
                printList(R7);
                printf("\n");
                return;
                
        after_if_label: node = (Node *)R19;
            node = node->next;
            R19 = (long long)node;
            goto while_label; 
    
    after_loop: printf("This element does not exist in this list.\n");
        printList(R7);
        printf("\n");
}

void getNumberOfElements(long long R7) {
    Node *node = (Node *)R7; 
    R23 = (long long)node;
    R24 = R0;
    
    while_label:
        if(R23 == R31) goto after_loop;
            R24 = R24 +1;
            node = (Node *)R23; 
            node = node->next;
            R23 = (long long)node;
            goto while_label;
            
    after_loop: printf("This list has %d element(s).\n", (int)R24);
        printList(R7);
        printf("\n");
}

void getAddressOfElement(long long R7) {
    Node *node = (Node *)R7;
    R25 = (long long)node;
    
    printf("Enter the ID of the element to be located (address): ");
    scanf("%hd", &R26);
    
    while_label:        
        if(R25 == R31) goto after_loop; 
            R27 = node->id;
            if(R27 != R26) goto after_if_label;
                printf("This element is stored at address: %#010x.\n", R25);
                return;
                
        after_if_label: node = (Node *)R25;
            node = node->next;
            R25 = (long long)node;
            goto while_label; 
    
    after_loop: printf("This ID is wrong.\n");
}

long long exitProgram() {
    printf("Program terminating.\n");
    R2 = R0;
    return R2;
}