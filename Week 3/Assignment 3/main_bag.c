/*
Logan Jordan - 10/10/24
main_bag.c: This file is used for testing the listbag.c file
*/

#include "listbag.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message) {
	printf("%s: ", message);
	if (predicate)
		printf("Pass \n");
	else
		printf("Fail \n");
}

int main() {
	struct List *lst = malloc(sizeof(struct List));
	initList(lst);
	printf("Initialized List \n");

    printf("---------testing addFrontList---------- \n");

    addFrontList(lst->head, 3);
    addFrontList(lst->head, 2);
    addFrontList(lst->head, 1);

    printf("List should contain [1, 2, 3]\n");
    displayList(lst->head);

    assertTrue(frontList(lst->head) == 1, "Testing head == 1 ");

    printf("---------testing addBackList---------- \n");

    addBackList(lst->head, 4);
    addBackList(lst->head, 5);

    printf("List should contain [1, 2, 3, 4, 5]\n");
    displayList(lst->head);

    assertTrue(frontList(lst->head) == 1, "Testing head == 1 ");
    assertTrue(backList(lst->head) == 5, "Testing tail == 5 ");

    printf("---------testing removeFrontList---------- \n");

    removeFrontList(lst->head);
    printf("List should contain [2, 3, 4, 5]\n");
    displayList(lst->head);
    assertTrue(frontList(lst->head) == 2, "Testing head == 2 ");
    assertTrue(backList(lst->head) == 5, "Testing tail == 5 ");

    printf("---------testing removeBackList---------- \n");

    removeBackList(lst->head);
    printf("List should contain [2, 3, 4]\n");
    displayList(lst->head);
    assertTrue(frontList(lst->head) == 2, "Testing head == 2 ");
    assertTrue(backList(lst->head) == 4, "Testing tail == 4 ");

    printf("---------testing listRemove---------- \n");

    printf("listRemove(3)\n");
    listRemove(lst->head, 3);

    assertTrue(frontList(lst->head) == 2, "Testing head == 2 ");
    assertTrue(backList(lst->head) == 4, "Testing tail == 4 ");

    printf("List should contain [2, 4]\n");
    displayList(lst->head);

    printf("---------testing freeList---------- \n");
    freeList(lst);

    printf("----------------- ******** testing listBag ******** ----------------- \n");

    struct bag *b = malloc(sizeof(struct bag));
	initBag(b);

	printf("---------testing addToBag---------- \n");
	addToBag(b, 1);
	addToBag(b, 2);
	addToBag(b, 3);
	addToBag(b, 7);
	addToBag(b, 11);
	addToBag(b, 8);
	addToBag(b, 3);
	addToBag(b, 9);

    printf("Bag should contain [9, 3, 8, 11, 7, 3, 2, 1]\n");
    displayList(b->lst->head);

    printf("---------testing bag contents using linked list functions---------- \n");
    assertTrue(frontList(b->lst->head) == 9, "Testing head == 9 ");
    assertTrue(backList(b->lst->head) == 1, "Testing tail == 1 ");

    printf("---------testing bagContains---------- \n");
	assertTrue(bagContains(b, 3), "Testing bagContains(b, 3)");
	assertTrue(bagContains(b, 1), "Testing bagContains(b, 1)");
	assertTrue(!bagContains(b, 4), "Testing bagContains(b, 4)");

    printf("---------testing removeFromBag---------- \n");
	printf("Removing 2\n");
	removeFromBag(b, 2);

    printf("Bag should contain [9, 3, 8, 11, 7, 3, 1]\n");
    displayList(b->lst->head);

	assertTrue(!bagContains(b, 2), "Testing bagContains(b, 2)");
	assertTrue(bagContains(b, 3), "Testing bagContains(b, 3)");

    printf("---------testing isEmptyBag---------- \n");
	assertTrue(isEmptyBag(b), "Testing isEmpty ");

	freeBag(b);

	return 0;
}
