#include <stdio.h>
#include <stdlib.h>

short startingId = 1; 

typedef struct node {
short id;
int value;
struct node *next;
} Node;

void printMenu();
void printList(Node *);
Node *createLinkedList(Node *);
Node *insertElement(Node *);
Node *deleteElement(Node *);
void searchElement(Node *);
void getNumberOfElements(Node *);
void getAddressOfElement(Node *);
void getAddressOfList(Node *);
void getSizeOfElement(Node *);
void getSizeOfList(Node *);
int exitProgram();

int main() {
    
    int logicState = 1, menuChoice;
    Node *head = NULL;
    
    while(logicState) {
        printMenu();
        
        scanf("%d", &menuChoice);
        
        switch(menuChoice) {
            case 1:
                head = createLinkedList(head);
                break;
            case 2:
                head = insertElement(head);
                break;
            case 3:
                head = deleteElement(head);
                break;
            case 4:
                searchElement(head);
                break;
            case 5:
                getNumberOfElements(head);
                break;
            case 6:
                getAddressOfElement(head);
                break;
            case 7:
                getAddressOfList(head);
                break;
            case 8:
                getSizeOfElement(head);
                break;
            case 9:
                getSizeOfList(head);
                break;
            case 10:
                logicState = exitProgram();
                break;
            default:
                printf("Choose between 1 to 10.\n\n");
        }
    }
    return 0;
    
}

void printMenu() {
    printf("Menu\n\n");
    printf("(1) Create a linked list.\n");
    printf("(2) Insert an element ascendingly into the list.\n");
    printf("(3) Delete an existing element from the list.\n");
    printf("(4) Check the existence of an element.\n");
    printf("(5) Print the number of all sorted elements in the list.\n");
    printf("(6) Print the address of a chosen element.\n");
    printf("(7) Print the address of the list.\n");
    printf("(8) Print the size of a chosen element.\n");
    printf("(9) Print the size of the list.\n");
    printf("(10) Exit program.\n\n");
    printf("Please enter your choice (1 - 10): ");
}

void printList(Node *h) {
    printf("List: ");
    
    while (h != NULL) {
        printf("(%hd) %d -> ",  h->id, h->value);
        h = h->next;
    }
    
    printf("(NULL node) -1\n");
}

Node *createLinkedList(Node *h) {
    h = NULL;
    int v;
    
    for(int i = 0; i < 5; i++) {
        h = insertElement(h);
    }
   
    return h;
}

Node *insertElement(Node *h) {
    Node *node;
    Node *tmp = h;
    int v;
    
    printf("Enter a new element's value to be sorted: ");
    scanf("%d", &v);
    
    node = (Node *) malloc(sizeof(Node));
    node->value = v;
    node->id = startingId++;
    
    if( (h == NULL) || (h->value >= v) ) {
        node->next = h;
        printList(node);
        printf("\n");
        return node;
    }
    
    while( (tmp->next != NULL) && (tmp->next->value < v) ) {
        tmp = tmp->next; 
    }
    
    node->next = tmp->next;
    tmp->next = node;
    
    printList(h);
    printf("\n");
    
    return h;
}

Node *deleteElement(Node *h) {
    Node *node = h;
    Node *tmp = h;
    short s;
    
    printf("Enter the element's ID that is to be deleted: ");
    scanf("%hd", &s);
    
    if(h == NULL) {
        printf("This list is empty.\n");
        return NULL;
    }
    
    if(node->id == s) {
        tmp = node->next;
        free(node);
        printList(tmp);
        printf("\n");
        return tmp;
    }
    
    while( (tmp->next != NULL) && (tmp->next->id != s) ) {
        tmp = tmp->next;
    }

    if(tmp->next == NULL) {
        printf("This ID is wrong.\n");
        return h;
    }
    
    node = tmp->next;
    tmp->next = node->next;
    free(node);
    printList(h);
    printf("\n");
    return h;
}

void searchElement(Node *h) {
    Node *tmp = h;
    int v;
    
    printf("Enter an element's value to be checked: ");
    scanf("%d", &v);
    
    while(tmp != NULL) {
        if(tmp->value == v) {
            printf("Element exist at node with ID of %hd\n", tmp->id);
            printList(h);
            printf("\n");
            return;
        }
        tmp = tmp->next;
    }
    
    printf("This element does not exist in this list.\n");
    
    printList(h);
    printf("\n");
}

void getNumberOfElements(Node *h) {
    int number = 0;
    
    while(h != NULL) {
        number++;
        h = h->next;
    }
    
    printf("This list has %d element(s).\n", number);
    
    printList(h);
    printf("\n");
}

void getAddressOfElement(Node *h) {
    Node *node = h;
    short s;
    
    printf("Enter the ID of the element to be located (address): ");
    scanf("%hd", &s);
    
    while(node != NULL) {
        if(node->id == s) {
            printf("This element is stored at address: %#010x.\n", node);
            return;
        }
        node = node->next;
    }
    
    printf("This ID is wrong.\n");
}

void getAddressOfList(Node *h) {
    printf("This list is located at address: %#010x.\n", h);
}

void getSizeOfElement(Node *h) {
    Node *node = h;
    short s;
    
    printf("Enter the ID of the element to be sized: ");
    scanf("%hd", &s);
    
    while(node != NULL) {
        if(node->id == s) {
            printf("This element's size is: %d bytes.\n", sizeof(node));
            return;
        }
        node = node->next;
    }
    
    printf("This ID is wrong.\n");
}

void getSizeOfList(Node *h) {
    int size = 0;
    
    while(h != NULL) {
        size += sizeof(h);
        h = h->next;
    }
    
    printf("This list's size is: %d bytes\n", size);
}

int exitProgram() {
    printf("Program terminating.\n");
    
    return 0;
}