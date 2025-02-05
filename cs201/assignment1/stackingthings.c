#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node{
    char c;
    Node* next;
};

struct Stack {
    Node* head;
};

Stack* constructStack(){
    Stack* newStack = malloc(sizeof(Stack));
    newStack->head  = NULL;
};

void stackPush(Stack* s, char data){
    printf("Pushing %c\n", data);
    Node* newNode = malloc(sizeof(Node));
    newNode->c = data;
    newNode->next = s->head ? s->head : NULL;

    s->head = newNode;
};

void stackPop(Stack* s){
    if(!s->head){
        printf("There is currently nothing stacked here");
        return;
    }
    char corn;
    corn = s->head->c;
    printf("Popping %c\n", corn);

    Node* zero = s->head;
    s->head = s->head->next ? s->head->next : NULL;

    zero->c = 0;
    zero->next = 0;
    free(zero);
}

void stackPrint(Stack* s){
    if(!s->head) {
        printf("The list is empty. There is nothing to print!\n");
        return;
    }

    printf("Printing stack without popping anything\n");
    Node* iter = s->head;

    while (iter){
        printf("%c\n", iter->c);
        iter = iter->next;
    }
};

void stackDump(Stack* s){
    if(!s->head) {
        printf("The list is empty. There is nothing to dump!\n");
        return;
    }

    printf("dumping stack\n");

    while (s->head){
        stackPop(s);
    }
};

void stackDestroy(Stack* s){
    s->head = NULL;
    free(s);
};

int main(){
    Stack* stack = constructStack();
    
    stackPush(stack, 'x');
    stackPush(stack, 'y');
    stackPush(stack, 'z');
    stackPrint(stack);
    stackPush(stack, 'c');
    stackPop(stack);
    stackPop(stack);
    stackPush(stack, 'Q');
    stackPush(stack, '9');
    stackDump(stack);
    stackPrint(stack);
    stackPush(stack, '2');
    stackPush(stack, 'Q');
    stackPush(stack, 'x');
    stackPush(stack, ';');
    stackPrint(stack);
    stackPop(stack);
    stackPop(stack);
    stackPrint(stack);
    stackPush(stack, '.');
    stackPop(stack);
    stackPop(stack);
    stackPush(stack, 'e');
    stackDump(stack);


    stackDestroy(stack);    
    return 0;
}