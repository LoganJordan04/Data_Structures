/*
Logan Jordan - 11/29/24
hashLab.c: Hash Table implementation and testing
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct hashLink {
    char *key; /* The key is what you use to look up a hashLink */
    int val; /* The value stored with the hashLink */
    struct hashLink *next; /* Notice how these are like linked list nodes */
};

struct hashTable {
    struct hashLink **table; /* Array of pointers to hashLinks */
    int cap; /* Capacity of the table */
    int count; /* Number of hash links */
};

int hash(char *word);
void initHash(struct hashTable *ht, int size);
void addHash(struct hashTable *ht, char *key, int val);
void reHash(struct hashTable *ht, int size);
void printHash(struct hashTable *ht);


/*
hash: the sum of the ASCII values of the parameter are computed
param1: word - the c-string to hash
pre: str is not NULL
return: the sum of the character values of the string are returned
post: none
HINT - you can treat chars like ints
HINT - return the absolute value - negative hashes don't work
*/
int hash(char *word) {
    printf("hashing %s \n", word);
    /* FIX ME */

    return 0;
}

/*
initHash: Initialize the hash table
param1: ht - the hash table to initialize
param2: size - the initial size of the hash table
pre: ht is not NULL
pre: size is greater than 0
post: cap has been set to size
post: count is set to 0
post: memory for array has been allocated
post: all hash links (buckets) are initialized to NULL
*/
void initHash(struct hashTable *ht, int size) {
    printf("Initializing hashTable \n");
    /* FIX ME */

}

/*
addHash: insert the key/value into a hash table using chaining
param1: ht - the hash table
param2: key - the key to insert
param3: val - the value to insert
pre: ht is not NULL
post: hash table contains the key/value
post: memory has been allocated dynamically for new hash link - if it is a
new key - no duplicate keys are permitted
post: count has been incremented
post: Resize table if load factor exceeds .75 - numHashLinks / capacity
HINT: If the key already exists, then just update the value
HINT: Add to the hashLink to the back of the linked list if it is a new key
HINT: Use strcmp to compare c-strings
HINT: integer division does not work as expected in c
*/
void addHash(struct hashTable *ht, char *key, int val) {
    printf("Inserting: %s \n", key);
    assert(ht != NULL);
    /* FIX ME */

}

/*
reHash: Resizes the hash table to specified size. Rehashes all the current
keys.
param1: ht - the hash table
param2: size - the new capacity
pre: ht is not empty
pre: size is > 0
post: memory for a new hash table has been created
post: new hash table has cap size
post: all keys have been re-hashed and inserted into new hash table
post: all the old hash links have been freed
post: previous array has been freed
HINT - use addHash to re-hash the keys from old to new
*/
void reHash(struct hashTable *ht, int size) {
    printf("--------------------re-sizing table------------------------ \n");
    struct hashLink **temp = ht->table;
    int tempSize = ht->cap;
    struct hashLink *curr, *del;
    ht->table = malloc(sizeof(struct hashLink*)*size);
    initHash(ht, size);
    /* FIX ME */

}

/*
printHash: prints the contents of the hash map
param1: ht - the hash table
pre: ht is not NULL
return: none
post: No changes to the hash table
post: Map has been printed to standard output
*/
void printHash(struct hashTable *ht) {
    /* FIX ME */

}


int main() {
    printf("testing table... \n");
    struct hashTable *myTable;
    myTable = malloc(sizeof(struct hashTable));
    initHash(myTable, 10);
    addHash(myTable, "ken", 20);
    addHash(myTable, "dave", 24);
    addHash(myTable, "nora", 18);
    addHash(myTable, "gill", 22);
    addHash(myTable, "teddy", 33);
    addHash(myTable, "greg", 40);
    addHash(myTable, "janice", 19);
    addHash(myTable, "carl", 28);
    addHash(myTable, "carla", 36);
    addHash(myTable, "carlton", 17);
    printHash(myTable);
    return 0;
}
