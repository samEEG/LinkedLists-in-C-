#include <stdio.h>
#include <stdlib.h>
struct myList {
    int info; //information field
    struct myList *link;    // self reeferencial structure
};


int main() {
    // Creating of the nodes
    struct myList *a;
    struct myList *b;
    struct myList *c;


    b = (struct myList *) malloc(sizeof (struct myList));
    b = (struct myList *) malloc(sizeof (struct myList));

    a->link = NULL;
    b->link = NULL;
    c->link = NULL;

    printf("a data:\n");
    scanf("%d", &a->info);
    printf("b data:\n");
    scanf("%d", &b->info);
    printf("c data:\n");
    scanf("%d", &c->info);
    a->link = b;
    b->link = c;
    printf("%d", a->link);
    free(a);
    free(b);
    free(c);
    a = (struct myList *)NULL;
    b = (struct myList *)NULL;
    c = (struct myList *)NULL;
}
