/*
Logan Jordan - 10/9/24
Lab3.c: Doubly linked inked list implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TYPE double

/* links with forward (next) and back (prev) pointers */
struct DLink {
    TYPE value;
    struct DLink *next;
    struct DLink *prev;
};

/* doubly linked list contains a sentinel (head) link along with size */
struct List {
    struct DLink *head;
    int size;
};

/*
function: initList - memory is allocated for head sentinel and the doubly linked list is initialized
param1: lst - doubly linked list
pre: lst is not null
post: memory has been allocated for head
post: head->next points to NULL
post: head->prev points to NULL
post: size set to 0
*/
void initList(struct List *lst) {
    assert(lst != NULL);
    printf("List initialized\n");

    lst->head = malloc(sizeof(struct DLink));
    lst->head->next = NULL;
    lst->head->prev = NULL;

    lst->size = 0;
}

/*
function: addFront - add new DLink to the front of the doubly linked list
param1 - lst - doubly linked list
param2 - val - value to insert
pre: lst is not null
post: memory for a new DLink has been allocated dynamically
post: new DLink has value - val
post: new DLink has been added to the front of the doubly linked list - pointers have been updated
post: head->next points to the new link
*/
void addFront(struct List *lst, TYPE val) {
    assert(lst != NULL);
    printf("addFront: %.1f \n", val);

    struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = val;
    temp->next = lst->head->next;
    temp->prev = lst->head;

    if(lst->size == 0) {
        lst->head->next = temp;
    } else {
        lst->head->next->prev = temp;
        lst->head->next = temp;
    }
    lst->size++;
}

/*
function: addBack - add new DLink to the back of the doubly linked list
param1 - lst - doubly linked list
param2 - val - value to insert
pre: lst is not null
post: memory for a new DLink has been allocated dynamically
post: new DLink has value - val
post: new DLink has been added to the back of the doubly linked list - pointers have been updated
*/
void addBack(struct List *lst, TYPE val) {
    assert(lst != NULL);
    printf("addBack: %.1f \n", val);

    struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = val;
    temp->next = NULL;

    if(lst->size == 0) {
        lst->head->next = temp;
        temp->prev = lst->head;
    } else {
        struct DLink *curr = lst->head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        temp->prev = curr;
        curr->next = temp;
    }
    lst->size++;
}

/*
function: printForward - print from front DLink to back DLink
param1 - lst - doubly linked list
pre: lst is not null
post: lst has been printed forward to standard output - output is separated by spaces
post: no changes to the list
*/
void printForward(struct List *lst) {
    assert(lst != NULL);
    printf("Print list: ");

    struct DLink *curr = lst->head->next;
    while(curr != NULL) {
        printf("%.1f ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/*
function: printBackward - print from back DLink to front DLink
param1 - lst - doubly linked list
pre: lst is not null
post: lst has been printed backwards to standard output - output is separated by spaces
post: no changes to the list
*/
void printBackward(struct List *lst) {
    assert(lst != NULL);
    printf("Print list backwards: ");

    struct DLink *curr = lst->head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    while(curr != lst->head) {
        printf("%.1f ", curr->value);
        curr = curr->prev;
    }
    printf("\n");
}

/*
function: removeFront - front DLink is removed from the doubly linked list
param1 - lst - doubly linked list
pre: lst is not null
pre: lst is not empty
post: a DLink has been removed from front of the doubly linked list - pointers have been updated
post: the DLink has been freed
*/
void removeFront(struct List *lst) {
    assert(lst != NULL);
    assert(lst->size != 0);
    printf("removeFront\n");

    struct DLink *delCurr = lst->head->next;
    lst->head->next = delCurr->next;

    if(lst->size > 1) {
        delCurr->next->prev = lst->head;
    }
    free(delCurr);
    lst->size--;
}

/*
function: removeBack - back DLink is removed from the doubly linked list
param1 - lst - doubly linked doubly linked list
pre: lst is not null
pre: lst is not empty
post: a DLink has been removed from back of the doubly linked list - pointers have been updated
post: the DLink has been freed
*/
void removeBack(struct List *lst) {
    assert(lst != NULL);
    assert(lst->size > 0);
    printf("removeBack\n");

    struct DLink *delCurr = lst->head;
    struct DLink *prev = NULL;
    while(delCurr->next != NULL) {
        prev = delCurr;
        delCurr = delCurr->next;
    }
    prev->next = NULL;
    free(delCurr);
    lst->size--;
}

int main() {
    struct List *lst = malloc(sizeof(struct List));
    initList(lst);

    printf("------------testing addFront()------------\n");
    addFront(lst, 2);
    printForward(lst);
    printBackward(lst);
    addFront(lst, 8);
    printForward(lst);
    printBackward(lst);

    printf("------------testing addBack()------------\n");
    addBack(lst, 1);
    printForward(lst);
    printBackward(lst);
    addBack(lst, 7);
    printForward(lst);
    printBackward(lst);

    printf("------------testing removeFront()------------\n");
    removeFront(lst);
    printForward(lst);
    printBackward(lst);

    printf("------------testing removeBack()------------\n");
    removeBack(lst);
    printForward(lst);
    printBackward(lst);

    return 0;
}