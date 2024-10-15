/*
Logan Jordan - 10/15/24
deque.c: Deque implementation using a linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

/*
function: initList - the deque is initialized
param1 - d - deque
pre: d is not null
post: head points to NULL
post: tail points null
post: size set to 0
*/
void initList(struct Deque *d) {
    printf("Deque initialized\n");
    assert(d != NULL);

    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
}

/*
function: addFront - add new Link to the front of the deque
param1 - d - deque
param2 - val - value to insert
pre: d is not null
post: memory for a new Link has been allocated dynamically
post: new Link has value - val
post: new Link has been added to the head of the deque
post: pointers have been updated
*/
void addFront(struct Deque *d, TYPE val) {
    printf("addFront: %.1f \n", val);
    assert(d != NULL);

    struct Link *temp = malloc(sizeof(struct Link));
    temp->value = val;
    temp->next = d->head;

    if(d->size == 0) {
        d->tail = temp;
    }
    d->head = temp;
    d->size++;
}

/*
function: addBack - add new Link to the back of the deque
param1 - d - deque
param2 - val - value to insert
pre: d is not null
post: memory for a new Link has been allocated dynamically
post: new Link has value - val
post: new Link has been added to the tail of the deque
post: pointers have been updated
*/
void addBack(struct Deque *d, TYPE val) {
    printf("addBack: %.1f \n", val);
    assert(d != NULL);

    struct Link *temp = malloc(sizeof(struct Link));
    temp->value = val;
    temp->next = NULL;

    if(d->size == 0) {
        d->head = temp;
    }
    d->tail->next = temp;
    d->tail = temp;
    d->size++;
}

/*
function: print - print from front head to tail
param1 - d - deque
pre: d is not null
post: d has been printed to standard output - output is separated by spaces
post: no changes to the deque
*/
void print(struct Deque *d) {
    assert(d != NULL);

    if(d->size == 0) {
        printf("Empty deque\n");
    }

    struct Link *curr = d->head;
    while (curr != NULL) {
        printf("%.1f ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/*
function: printReverse - recursive function to print from front tail to head
param1 - d - deque
pre: none
post: d has been printed to standard output -  output is separated by spaces
post: no changes to the deque
*/
void printReverse(struct Link *curr) {
    /* FIX ME */

}

/*
function: getFront - value of the head Link is returned
param1 - d - deque
ret: value of the head Link
pre: d is not null
pre: d is not empty
post: no changes to the deque
*/
TYPE getFront(struct Deque *d) {
    /* FIX ME */

    return 0;
}

/*
function: getBack - value of the tail Link is returned
param1 - d - deque
ret: value of the tail Link
pre: d is not null
pre: d is not empty
post: no changes to the deque
*/
TYPE getBack(struct Deque *d) {
    /* FIX ME */

    return 0;
}

/*
function: removeFront - front Link is removed from the deque
param1 - d - linked list
pre: d is not null
pre: d is not empty
post: front of the linked list has been removed from the list
post: memory has been freed for the Link
post: size is decremented
HINT: A list with one link is a special case
*/
void removeFront(struct Deque *d) {
    printf("removeFront\n");
    /* FIX ME */

}

/*
function: removeBack - back Link is removed from the deque
param1 - d - linked list
pre: d is not null
pre: d is not empty
post: back of the linked list has been removed from the list
post: memory has been freed for the Link
post: size is decremented
HINT: A list with one link is a special case
*/
void removeBack(struct Deque *d) {
    printf("removeBack\n");
    /* FIX ME */

}

/*
function: freeDeque - free all the links in the deque
param1 - d - linked list
pre: d is not null
post: all links have been freed
post: the deque has been freed
*/
void freeDeque(struct Deque *d) {
    /* FIX ME */

}
