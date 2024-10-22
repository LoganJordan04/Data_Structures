/*
Logan Jordan - 10/22/24
lab5.c: Sorted linked list implementation and testing
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TYPE int

/*
singly-linked list node
*/
struct node {
	TYPE value;
	struct node *next;
};

/*
simple linked list with a head pointer (sentinel node)
*/
struct list {
	struct node *head;
};

/*
initList: initialize the list
param: none
pre: none
post: allocate memory for the list
post: allocate memory for list->head (sentinel)
post: head->next is set to NULL
return: a pointer to the newly allocated list
*/
struct list *initList() {
	/*FIX ME*/

	return 0;
}

/*
slideRight: find the node with the previous link relative to the specified value
param1: lst is the linked list
param2: val - the value which determines the previous link
ret - pointer to the  link with a value before the specified value
pre: list is not null
post: no changes to the list
*/
struct node* slideRight(struct list *lst, TYPE val) {
    /*FIX ME*/

    return 0;
}

/*
addItem: add an element to a sorted list
param: lst is the linked list
param: val is the value to add
pre: lst is not null
post: memory for the new link has been allocated
post: value of new node is set
post: pointers are adjusted
post: a node has been added to the sorted linked list
HINT: use slideRight()
*/
void addItem(struct list *lst, TYPE val) {
    printf("Adding value: %d\n", val);
    /*FIX ME*/

}

/*
containsItem: determine if a value is in a list
param: lst is the linked list
param: val is the value to search for
pre: lst is not null
post: no changes to the list
return: return 1 if found, otherwise return 0
*/
int containsItem(struct list *lst, TYPE val) {
    /*FIX ME*/

    return 0;
}

/*
deleteItem: remove an element from a sorted list
param: lst is the linked list
param: val is the value to add
pre: lst is not null
pre: val is in the list
post: memory for the link has been freed
post: pointers are adjusted
post: a node has been removed from the sorted linked list
*/
void deleteItem(struct list *lst, TYPE val) {
    printf("Delete value: %d\n", val);
    /*FIX ME*/

}

/*
printList: prints a list - should reveal sorted order
param: curr is the starting node to print
pre: curr is not null
post: no changes to the list
*/
void printList(struct list *lst) {
	/*FIX ME*/

}

/*
printListRev: recursive function prints a list
param: curr is the current node - initially the head
pre: none
post: the list is printed in reverse order separated by spaces
post: no changes to the list
*/
void printListRev(struct node *curr) {
	/*FIX ME*/

}

/*
freeList: free the memory for the lost
param: lst - the list
pre: lst is not null
post: every node in the list has been freed
post: lst has been freed
*/
void freeList(struct list *lst) {
    /*FIX ME*/

}

int main() {
	struct list *lst = initList();

	addItem(lst, 12);
	addItem(lst, 10);
	addItem(lst, 8);
	addItem(lst, 6);
	addItem(lst, 4);
	addItem(lst, 2);
	addItem(lst, 7);
	addItem(lst, 9);

    printf("---------------printing list---------------\n");
	printList(lst);

	printf("---------------testing contains---------------\n");
	printf("Testing containsItem(8): %d\n", containsItem(lst, 8) == 1);
	printf("Testing containsItem(3): %d\n", containsItem(lst, 3) == 0);

	deleteItem(lst, 10);
    printf("---------------printing list---------------\n");
	printList(lst);
	deleteItem(lst, 2);
    printf("---------------printing list---------------\n");
	printList(lst);
	deleteItem(lst, 12);
    printf("---------------printing list---------------\n");
    printList(lst);

    printf("---------------printing list backwards---------------\n");
	printListRev(lst->head->next);
	printf("\n");

	freeList(lst);

	return 0;
}
