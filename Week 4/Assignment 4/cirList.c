/*
Logan Jordan - 10/16/24
cirList.c: Circularly linked list implementation
*/

#include "cirList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
initCirList: Initialize the circularly linked list
param: c pointer to the circularly linked list
pre: c is not null
post: memory for c->Sentinel is dynamically allocated
post: Sentinel links are initialized to point to the sentinel
*/
void initCirList(struct CirList *c) {
	assert(c != NULL);
    c->sentinel = malloc(sizeof(struct DLink));
    c->sentinel->next = c->sentinel;
    c->sentinel->prev = c->sentinel;
}

/*
addFrontCirList: Adds a link to the front of the circularly linked list
param: c pointer to the circularly linked list
param: val value for the link to be added
pre: c is not null
post: a link storing val is added to the front of the circularly linked list
post: memory is dynamically allocated for the new link
post: pointers have been adjusted
*/
void addFrontCirList(struct CirList *c, TYPE val) {
	printf("Add to front: %d\n", val);
    assert(c != NULL);

    struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = val;

    if(isEmptyCirList(c)) {
        temp->next = c->sentinel;
        temp->prev = c->sentinel;

        c->sentinel->next = temp;
        c->sentinel->prev = temp;
    } else {
        temp->next = c->sentinel->next;
        temp->prev = c->sentinel;

        c->sentinel->next->prev = temp;
        c->sentinel->next = temp;
    }
}

/*
addBackCirList: Adds a link to the back of the circularly linked list
param: c pointer to the circularly linked list
param: val value for the link to be added
pre: c is not null
post: a link storing val is added to the back of the circularly linked list
post: memory is dynamically allocated for the new link
post: pointers have been adjusted
*/
void addBackCirList (struct CirList *c, TYPE val) {
	printf("Add to back %d \n", val);
    assert(c != NULL);

    struct DLink *temp = malloc(sizeof(struct DLink));
    temp->value = val;

    if(isEmptyCirList(c)) {
        temp->next = c->sentinel;
        temp->prev = c->sentinel;

        c->sentinel->next = temp;
        c->sentinel->prev = temp;
    } else {
        temp->next = c->sentinel;
        temp->prev = c->sentinel->prev;

        c->sentinel->prev->next = temp;
        c->sentinel->prev = temp;
    }
}

/*
printCirList: Print the links in the circularly linked list from front to back
param: c pointer to the circularly linked list
pre: c is not null and q is not empty
post: the links in the circularly linked list are printed from front to back
post: no changes to the circularly linked list
*/
void printCirList(struct CirList *c) {
    assert(c != NULL);

    struct DLink *curr = c->sentinel->next;
    while(curr != c->sentinel) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/*
frontCirList: Get the value of the front of the circularly linked list
param: c pointer to the circularly linked list
ret: value of the front of the circularly linked list
pre: c is not null
pre: c is not empty
post: no changes to the circularly linked list
*/
TYPE frontCirList(struct CirList *c) {
    assert(c != NULL);
    assert(!isEmptyCirList(c));

	return c->sentinel->next->value;
}

/*
backCirList: Get the value of the back of the circularly linked list
param: c pointer to the circularly linked list
ret: value of the back link in the circularly linked list
pre: c is not null
pre: c is not empty
post: no changes to the circularly linked list
*/
TYPE backCirList(struct CirList *c) {
    assert(c != NULL);
    assert(!isEmptyCirList(c));

    return c->sentinel->prev->value;
}

/*
removeFrontCirList: Remove the front of the circularly linked list
param: c pointer to the circularly linked list
pre: c is not null
pre: c is is not empty
post: the front node is removed from the circularly linked list
post: memory is freed for the front link
post: pointers are adjusted
*/
void removeFrontCirList(struct CirList *c) {
	printf("Remove front: %d\n", c->sentinel->next->value);
    assert(c != NULL);
    assert(!isEmptyCirList(c));

    struct DLink *del = c->sentinel->next;

    c->sentinel->next = del->next;
    del->next->prev = c->sentinel;

    free(del);
    del = 0;
}

/*
removeBackCirList: Remove the back of the circularly linked list
param: c pointer to the circularly linked list
pre: c is not null
pre: c is is not empty
post: the back node is removed from the circularly linked list
post: memory is freed for the back link
post: pointers are adjusted
*/
void removeBackCirList(struct CirList *c) {
	printf("Remove back: %d\n", c->sentinel->next->value);
    assert(c != NULL);
    assert(!isEmptyCirList(c));

    struct DLink *del = c->sentinel->prev;

    c->sentinel->prev = del->prev;
    del->prev->next = c->sentinel;

    free(del);
    del = 0;
}

/*
isEmptyCirList: Check whether the circularly linked list is empty
param: c pointer to the circularly linked list
pre: c is not null
ret: 1 if the circularly linked list is empty - otherwise return 0
post: no changes to the circularly linked list
*/
int isEmptyCirList(struct CirList *c) {
    assert(c != NULL);
    if(c->sentinel == c->sentinel->next) {
        return 1;
    }
	return 0;
}

/*
freeCirList: Free all links of the circularly linked list
param: c pointer to the circularly linked list
pre: c is not null
post: All links have been freed
post: sentinel has been freed
post: CirList has been freed
*/
void freeCirList(struct CirList *c) {
    assert(c != NULL);

    struct DLink *curr = c->sentinel->next;
    struct DLink *del = NULL;

    while (curr != c->sentinel) {
        del = curr;
        curr = curr->next;
        free(del);
        del = 0;
    }
    free(c->sentinel);
    free(c);
    c = 0;

    printf("CirList was freed!\n");
}

/***********************************Stack Interface***********************************/

/*
initStack: Initialize the stack
param: s pointer to the stack
pre: s is not null
post: memory is allocated for the underlying circularly linked list
post: size is set to 0
post: s->lst is passed to initCirList()
*/
void initStack(struct Stack *s) {
    printf("Init stack\n");
    assert(s != NULL);

    s->lst = malloc(sizeof(struct CirList));
    initCirList(s->lst);
    s->size = 0;
}

/*
push: Add to the stack
param: s pointer to the stack
param: val value to be added
pre: s is not null
post: size is incremented
post: an item has been pushed to the front on the list
*/
void push(struct Stack *s, TYPE val) {
    assert(s != NULL);

    addFrontCirList(s->lst, val);
    s->size++;
}

/*
pop: Pop from stack
param: s pointer to the stack
pre: s is not null
pre: s lst is not empty
post: size is decremented
post: an item has been removed from the back of the list
*/
void pop(struct Stack *s) {
    assert(s != NULL);
    assert(!isEmptyStack(s));

    removeFrontCirList(s->lst);
    s->size--;
}

/*
peek: Return the value at the top of the stack
param: s pointer to the stack
return: value of the top items of the stack
pre: s is not null
pre: s->lst is not empty
post: value at the top of the stack is returned
post: no changes to the stack
*/
TYPE peek(struct Stack *s) {
    assert(s != NULL);
    assert(!isEmptyStack(s));

    return frontCirList(s->lst);
}

/*
isEmptyStack: Determine if the stack is empty
param: s pointer to the stack
return: int - 1 for true, 0 for false
pre: s is not null
post: no changes to the stack
*/
int isEmptyStack(struct Stack *s) {
    assert(s != NULL);

    return isEmptyCirList(s->lst);
}

/*
freeStack: Free memory for the stack and underlying list
param: s pointer to the stack
pre: s is not null
post: memory has been freed for s->lst
post: memory has been freed for the stack
*/
void freeStack(struct Stack *s) {
    assert(s != NULL);

    freeCirList(s->lst);
}

/***********************************Queue Interface***********************************/

/*
initQueue: Initialize the queue
param: q pointer to the queue
pre: q is not null
post: memory is allocated for the underlying circularly linked list
post: size is set to 0
post: q->lst is passed to initCirList()
*/
void initQueue(struct Queue* q) {
    printf("Init queue\n");
    assert(q != NULL);

    q->lst = malloc(sizeof(struct CirList));
    initCirList(q->lst);
    q->size = 0;

}

/*
enqueue: Add to the queue
param: q pointer to the queue
param: val value to be added
pre: q is not null
post: size is incremented
post: an item has been added to the back to the queue
*/
void enqueue(struct Queue* q, TYPE val){
    assert(q != NULL);

    addBackCirList(q->lst, val);
    q->size++;
}

/*
dequeue: Remove from the queue
param: q pointer to the queue
pre: q is not null
pre: q is not empty
post: size is decremented
post: an item has been removed from the front the queue
HINT: pass q->lst to a circularly linked list function
*/
void dequeue(struct Queue* q) {
    assert(q != NULL);
    assert(!isEmptyQueue(q));

    removeFrontCirList(q->lst);
    q->size--;
}

/*
peekQ: Return the value at the front of the queue
param: q pointer to the queue
return: value of the top items of the queue
pre: q is not null
pre: q->lst is not empty
post: value at the top of the queue is returned
post: no changes to the queue
*/
TYPE peekQ(struct Queue* q) {
    assert(q != NULL);
    assert(!isEmptyQueue(q));

    return frontCirList(q->lst);
}

/*
isEmptyQueue: Determine if the queue is empty
param: q pointer to the queue
return: int - 1 for true, 0 for false
pre: q is not null
post: no changes to the queue
*/
int isEmptyQueue(struct Queue* q) {
    assert(q != NULL);

    return isEmptyCirList(q->lst);
}

/*
freeQueue: Free memory for the queue and underlying list
param: s pointer to the queue
pre: s is not null
post: memory has been freed for q->lst
post: memory has been freed for the queue
*/
void freeQueue(struct Queue* q) {
    assert(q != NULL);

    freeCirList(q->lst);
}
