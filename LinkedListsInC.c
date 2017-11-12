#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node *head; /*Declare a global head node*/

void printList(struct node *head);
struct node *getNode();
void push(int v);
int isEmpty(struct node *nodeC);
void removeIndex(int index);
void pushIndex(int v, int index);
void pop(struct node *nodeC);
void popFirst();
void pushBegin(int v);


int main () {
    push(1);    /*Can test any of the methods defined above*/
    push(2);
    push(3);
    push(60);
    push(90);
    /*
    pushBegin(100);
    popFirst();
    removeIndex(2);
    pushIndex(100,2);
    removeIndex(3);
    printList(head); */

}
//create memory for new node
struct node *getNode() {

/*Pops first element */
void popFirst() {
    struct node *current = head;
    head = head->next;
    free(current);
}

/*pop last node in list*/
void pop(struct node *nodeC) {
    struct node *current = nodeC;
    struct node *temp;
    while(current->next != NULL) {
        temp = current;
        current = current ->next;
    }
    temp ->next = NULL;
    free(current);
}

/*Remove node at specific index*/
void removeIndex(int index) {
    struct node *current = head;
    struct node *temp;
    int i;
    for(i = 0; i < index -1; i++){
        temp = current;
        current = current->next;
    }
    temp->next = current ->next;
    free(current);

}

/*pushing node at specific index*/
void pushIndex(int val, int index) {
    struct node *current = head;
    struct node *newNode = getNode();
    struct node *temp;
    newNode->val = val;
    int i;
    for(i = 0; i < index -1; i++) {
        temp = current;
        current = current->next;
    }
    temp ->next = newNode;
    newNode->next = current;
}
/*pushing node at the beginning*/
void pushBegin(int val) {
    struct node *newNode = getNode();
    newNode->val = val;
    newNode->next = head;
    head = newNode;
}

/*add to the end of a linked list*/
void push(int val) {
    struct node *current = head;
    if(head == NULL) {
        head = getNode();
        head->val = val;
        head ->next;
    }
    else {
        while(current ->next != NULL) {
            current = current ->next;
        }
        current->next = getNode();
        current = current->next;
        current->val = val;
        current->next = NULL;
    }
}
/*checks to see if the list is empty*/
int isEmpty(struct node *nodeC) {
    if(nodeC) {
        return 1;
    }
    return nodeC;
}

/*prints the Linkedlist */
void printList(struct node *head) {
    struct node *current = head;
    while(current != NULL) {
        printf("%d      %d\n", current ->val, current ->next);
        current = current ->next;
    }
}


