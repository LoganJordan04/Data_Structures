/*
Logan Jordan - 10/23/24
skipList.c: Skip list implementation
*/

#include "skipList.h"
#include <malloc.h>
#include <time.h>
#include <assert.h>

/*
initSkipList: Skiplist is initialized - memory is allocated for the sentinel
param1: lst - the list
param2: maxLvl - maximum depth of the list
pre: lst is not null
pre: maxLvl is greater than 0
post: rand() has been seeded
post: memory is allocated to sentinel
post: sentinel points to NULL at every level
post: maxLevel is set to maxLvl - should be log n(size of list)
post: currMax is set to 0
post: size is set to 0
*/
void initSkipList(struct skipList *lst, int maxLvl) {
    assert(lst != NULL);
    assert(maxLvl > 0);
	printf("Initializing...\n");

    srand(time(NULL));

	lst->sentinel = malloc(sizeof(struct sLink)); /* sentinel->next is the sentinel*/
	lst->sentinel->next = malloc(sizeof(struct sLink*) * maxLvl); /* sentinel->next is an array with a pointer to every level */

    int i;
	for(i = 0; i < maxLvl; i++) {
		lst->sentinel->next[i] = lst->sentinel; /* sentinel points to the sentinel at every level */
	}

	lst->maxLevel = maxLvl; /* max allowable levels */
	lst->currMax = 0; /* level of highest node currently */
	lst->size = 0; /* number of level 0 links */
}

/*
levelGen: Generate a random level for new links - probabilistically determined
param1: lst - the list
return: random level from 0 to lst->maxLevel - 1
pre: lst is not null
*/
int levelGen(struct skipList *lst) {
    assert(lst != NULL);

	int level = 0;

    /* random levels are generated by a "series of coin flips" that don't exceed the max level */
    while(rand() % 2 == 0 && level < lst->maxLevel) {
        level++;
    }
    if(level > lst->currMax) {
        lst->currMax++;
        level = lst->currMax;
    }

	return level;
}

/*
addValTest: Adds a value to the skipList at a specified level - for testing purposes
param1: lst - the list
param2: val - the value to add
param3: lvl - the level of the link
pre: lst is not null
pre: lvl >= 0
pre: lvl < maxLevel
post: memory has been allocated to the new skip link
post: value has been set for the new skip link at each necessary level
post: pointers have been adjusted at each necessary level
*/
void addValTest(struct skipList *lst, TYPE val, int lvl) {
	printf("inserting %d as a lvl %d node\n", val, lvl);
	assert(lst != NULL);
	assert(lvl < lst->maxLevel);
	assert(lvl >= 0);

	/* allocate memory for link to insert - extra space is allocated for the "height" of the link +1 (in case it is zero) */
	struct sLink *insert = malloc(sizeof(struct sLink));
	insert->next = malloc(sizeof(struct sLink*) * (lvl+1));
	insert->value = val;
	insert->level = lvl;

	/* pointer for iterator node. Points to sentinel */
	struct sLink *curr = lst->sentinel;

    if (lvl > lst->currMax) {
        lst->currMax = lvl;
    }

    /* start from the highest current level and move down */
    int currLevel;
    for (currLevel = lst->currMax; currLevel >= 0; currLevel--) {
        /* traverse the list at the current level until we find the correct insertion point */
        while (curr->next[currLevel] != NULL && curr->next[currLevel] != lst->sentinel && val > curr->next[currLevel]->value) {
            curr = curr->next[currLevel];
        }

        /* insert the node if at or below the node's specified level */
        if (currLevel <= lvl) {
            insert->next[currLevel] = curr->next[currLevel];
            curr->next[currLevel] = insert;
        }
    }

    lst->size++;
}

/*
addVal: Adds a new sLink to the skipList at a random level and maintains the skip list
param1: lst - the list
param2: val - the value to add
pre: lst is not null
post: a new sLink is added to the skip list at each necessary level with the specified value - level is generated randomly
*/
void addVal(struct skipList *lst, TYPE val) {
	int lvl = levelGen(lst);
    addValTest(lst, val, lvl);
}

/*
searchVal: Searches the skipList for a value
param1: lst - the list
param2: val - the search value
pre: lst is not null
post: return an integer greater than 0 if found - Is not found, return 0
Returns the number of comparisons needed to find the value if found (will work as boolean return)
*/
int searchVal(struct skipList *lst, TYPE val) {
	printf("Searching for: %d\n", val);
	assert(lst != NULL);

    struct sLink *curr = lst->sentinel;
    int comparisons = 0;

    /* traversing the list the same way as addValTest() */
    int currLevel;
    for (currLevel = lst->currMax; currLevel >= 0; currLevel--) {
        while (curr->next[currLevel] != NULL && curr->next[currLevel] != lst->sentinel && val > curr->next[currLevel]->value) {
            curr = curr->next[currLevel];
            comparisons++;
        }

        /* value was found */
        if (curr->next[currLevel]->value == val) {
            return comparisons + 1;
        }
    }

    /* value was not found */
	return 0;
}

/*
printLv: Print the specified level of the list
param1: lst - the list
param2: lv - level of the list to print
pre: lst is not null
pre: lv is greater than or equal to 0 and not greater than list->maxLevel
post: prints all of the values at a specified level
*/
void printLv(struct skipList *lst, int lv) {
	printf("Level %d: ", lv);
    assert(lst != NULL);
    assert(lv >= 0);
    assert(lv < lst->maxLevel);

    struct sLink *curr = lst->sentinel->next[lv];
    while (curr != NULL && curr != lst->sentinel) {
        printf("%d ", curr->value);
        curr = curr->next[lv];
    }
    printf("\n");
}

/*
removeLink: Remove the first instance of the link containing the value from the list and maintains the skip list
pre: lst is not null
pre: val is in the list
param1: lst - the list
param2: val - value to remove
post: pointers are adjusted at each relevant level
post: link is freed from the list (after pointers are adjusted at each level)
HINT: start at the top or bottom and search for the value on that level
HINT: each level of pointers needs to be adjusted as applicable
HINT: print statements displaying slides and dropping down a level might help to see what is happening
*/
void removeLink(struct skipList *lst, TYPE val) {
	/* FIX ME */

}

/*
getSize: return the number of level 0 links in the skip list
param1: lst - the list
pre: lst is not null
post: return the number of level 0 links in the list
HINT: count the number of links at level 0
*/
int getSize(struct skipList *lst) {
	/* FIX ME */

	return 0;
}

/*
deleteList: memory is freed for the skip list
param1: lst - the list
pre: lst is not null
post: sLinks are freed
post: sLinks->next are freed
post: lst is freed
*/
void deleteList(struct skipList *lst) {
	/* FIX ME */

}
