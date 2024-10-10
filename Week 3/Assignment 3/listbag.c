/*
Logan Jordan - 10/10/24
listbag.c: Linked list implementation
*/

#include "listbag.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* Turn on for debugging messages */
int debug = 1;

/*
initList: initialize the list - create the head and initialize pointers
param: lst is the list
pre: lst is not null
post: memory has been dynamically allocated for the head
post: head next is initialized to NULL
*/
void initList (struct List *lst) {
	assert(lst != NULL);
	lst->head = malloc(sizeof(struct Link));
	lst->head->next = NULL;
}

/*
addFrontList: add a value to the front of the list
param: head is the head of the list
param: e is the value to add to the list
pre: head is not null
post: memory has been dynamically allocated for a new link
post: new link is added to the front of the list
*/
void addFrontList (struct Link *head, TYPE e) {
	if(debug)printf("Inserting %d at head of list\n", e);
	assert(head != NULL);

    struct Link *temp = malloc(sizeof(struct Link));
    temp->value = e;
    temp->next = head->next;

    head->next = temp;
}

/*
addBackList: add a value to the back of the list
param: head is the front of the list
param: e is the value to add to the list
pre: head is not null
post: memory has been dynamically allocated for a new link
post: new link is added to the back of the list
*/
void addBackList(struct Link *head, TYPE e) {
	if(debug) printf("Inserting %d at back of list\n", e);
    assert(head != NULL);

    struct Link *temp = malloc(sizeof(struct Link));
    temp->value = e;
    temp->next = NULL;

    struct Link *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;
}

/*
displayList: print the contents of the list
param: head is the front of the list
pre: head is not null
pre: list is not empty
post: list contents are displayed - separated by spaces
post: no changes to the list
*/
void displayList (struct Link *head) {
    printf("List Contents: ");
	assert(head != NULL);
    assert(!isEmptyList(head));

    struct Link *curr = head->next;
    while(curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

/*
frontList: return the element at the head of the list
param: head is the front of the list
return: return value at front of the list
pre: head is not null
pre: list is not empty
post: no changes to the list
*/
TYPE frontList (struct Link *head) {
    assert(head != NULL);
    assert(!isEmptyList(head));

	return head->next->value;
}

/*
backList: return the element at the back of the list
param: head is the front of the list
return: return value at back of the list
pre: head is not null
pre: list is not empty
post: no changes to the list
*/
TYPE backList(struct Link *head) {
    assert(head != NULL);
    assert(!isEmptyList(head));

    struct Link *curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }

    return curr->value;
}

/*
removeFrontList: remove element from front of list
param: head is the front of the list
pre: head is not null
pre: list is not empty
post: head points to head->next
post: old head has been freed
*/
void removeFrontList(struct Link *head) {
	if(debug) printf("remove front of list: \n");
    assert(head != NULL);
    assert(!isEmptyList(head));

    struct Link *delCurr = head->next;
    head->next = delCurr->next;

    free(delCurr);
}

/*
removeBackList:	remove element from back of list
param: head is the front of the list
pre: head is not null
pre: list is not empty
post: link before the end points to NULL
post: old head has been freed
*/
void removeBackList (struct Link *head) {
	if(debug) printf("remove back of list: \n");
    assert(head != NULL);
    assert(!isEmptyList(head));

    struct Link *delCurr = head;
    struct Link *curr = NULL;
    while(delCurr->next != NULL) {
        curr = delCurr;
        delCurr = delCurr->next;
    }
    curr->next = NULL;
    free(delCurr);
}

/*
listRemove: remove the first occurrence of the value from the list
param: head is the front of the list
param: e is the value to remove
pre: head is not null
pre: list is not empty
post: link containing  first occurrence of value e has been freed
post: pointer before link containing  first occurrence of value has been updated
*/
void listRemove (struct Link *head, TYPE e) {
	if(debug) printf("remove %d from list: \n", e);
	/* FIX ME*/

}

/*
isEmptyList: checks whether the list is empty or not
param: head is the front of the list
return: Return 1 if empty, 0 if not
pre: head is not null
post: no changes to the list
*/
int isEmptyList(struct Link *head) {
	assert(head != NULL);
	if(head->next == NULL) {
		return 1;
	}
	return 0;
}

/*
freeList: Free the list
param: head is the front of the list
pre: head is not null
post: each link of the list has been freed
post: lst has been freed
post: lst points to nothing
*/
void freeList(struct List *lst) {
	/* FIX ME*/

}

/* -----------------------ListBag functions begin here---------------------- */

/*
initBag: initialize bag
param: b is the bag
pre: b is not null
post: memory for list is dynamically allocated
post: lst is initialized using initList()
post: size  is initialized to 0
*/
void initBag(struct bag* b) {
	assert( b != NULL);
	b->lst = (struct List*)malloc(sizeof(struct List));/*Allocate for the list part of the bag*/
	initList(b->lst);/*Initialize list*/
	b->size=0;
}

/*
addToBag: add an element to the bag
param: b is the bag
param: val is the value added to the bag
pre: b is not null
post: val is added to the bag (list implementing the bag)
post: size is incremented
HINT: use linked list functions to manipulate the list
HINT: You will pass the head of the list which is part of the bag (b->list->head)
*/
void addToBag(struct bag* b, TYPE val) {
 	/* FIX ME*/

}

/*
bagContains: test if an element exists in the bag
param: b is the bag
param: val is the value to search for
return: return 1 if found, otherwise return 0
pre: b is not null
post: no changes to the bag
*/
int bagContains(struct bag* b, TYPE val) {
	/* FIX ME*/

	return 0;
}

/*
removeFromBag: remove an element from the bag
param: b is the bag
param: val is the value to remove from the bag
pre: b is not null
pre: b contains val - use bagContains()
post: link is removed from bag
post: size is decremented
HINT: use linked list functions to manipulate the list
*/
void removeFromBag(struct bag* b, TYPE val) {
	/*FIX ME*/

}

/*
isEmptyBag: test if the bag is empty
param: b is the bag
return: return 1 if found, otherwise return 0
pre: b is not null
post: no changes to the bag
*/
int isEmptyBag(struct bag* b) {
	/* FIX ME*/

    return 0;
}

/*
freeBag: deallocate bag memory
param: b is the the bag
pre: b is not null
post: bag is freed
post: list is freed
HINT: use linked list functions to manipulate the list
*/
void freeBag(struct bag *b) {
	/* FIX ME*/

}

/*-------------------- Pt II - Algorithm Analysis --------------------------*/

/*

#1 - What is the worst case performance of the removeFromBag() operation expressed in terms of the size of the bag(n)? Describe the worst case in words.(2 Pt)

#2 - What is the best case performance of the removeFromBag() operation expressed in terms of the size of the bag(n)? Describe the best case in words. (2 Pts)

#3 - What is the average number of comparisons that removeFromBag() performs expressed in terms of the size of the bag(n)? (1 Pt)

#4 - What is the worst case performance for the addToBag() operation?  (1 Pts)

#5 - What is the best case performance for the addToBag() operation? (1 Pts)

#6 - Did you use addFrontList() or addBackList() to add elements to your bag? Why was this the best choice? (2 Pts)

#7 - Is a linked list or a dynamic array a better choice for adding elements to a bag? Explain your answer. (3 Pts)

*/
