/*
Logan Jordan - 12/2/24
hashLab.c: Map and concordance implementation using a hash table with buckets
*/

#include "hash.h"

/*
hashFunction1: The first hash function you will use - the sum of the ASCII values is computed
param1: str - the string to hash
pre: str is not NULL
return: the sum of the ASCII values of the string is returned
post: none
*/
int hashFunction1(char *str) {
	assert(str != NULL);

    int sum = 0;
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
	return abs(sum);
}

/*
hashFunction2: The second hash function you will use - not easy to explain how it is hashed
param1: str - the string to hash
pre: str is not NULL
return: the hash is returned
post: none
*/
int hashFunction2(char *str) {
	assert(str != NULL);

	int i;
	int h = 0;
	for(i = 0; str[i] != '\0'; i++) {
		h += (i+1) * str[i];
	}
	return abs(h);
}

/*
hashValue: returns the hash of the val - hash algorithm is specified
param1: val - the string to hash
param2: hashNum - the number of the hashing function (1 or 2 in this program)
pre: val is not NULL
return: the hashed value is returned
post: none
*/
int _hashValue(char *val, int hashNum) {
	if(hashNum == 1) {
		return hashFunction1(val);
	} else {
		return hashFunction2(val);
	}
}

/*
initMap: Initialize the hash table
param1: h - the hash map to initialize
param2: tableSize - the size of the hash map
pre: h is not NULL
pre: tableSize is greater than 0
post: tableSize has been set to tableSize
post: count is set to 0
post: hashID is set to ID
post: memory for array has been allocated
post: all hash links (buckets) are initialized to NULL
*/
void _initMap(struct hashTable *h, int tableSize, int ID) {
	h->tableSize = tableSize;
	h->count = 0;
	h->hashID = ID;
	h->table = malloc(sizeof(struct hashLink*)*tableSize);

	int i = 0;
	while(i < tableSize) {
        h->table[i] = NULL;
        i++;
	}
}

/*
createMap: allocate memory and initialize a hash table
param1: tableSize - the capacity of the table
pre: tableSize > 0
return: newly created hash map of size, tableSize
post: memory for the hash map has been created
post: hash table of size tableSize has been initialized
*/
struct hashTable *createMap(int tableSize, int ID) {
	assert(tableSize > 0);

	struct hashTable *h;
	h = malloc(sizeof(struct hashTable));
	assert(h != 0); /* Ensure that memory was successfully allocated */

	_initMap(h, tableSize, ID);
	return h;
}

/*
insertMap: insert the key/value into a hash map - no duplicate keys are permitted
param1: h - the hash map
param2: k - the key to insert - in this case, the word
param3: v - the value to insert - in this case, the number of occurrences - it is just a "1" in pt 1
pre: h is not NULL
post: map contains the key/value
post: count has been incremented
*/
void insertMap(struct hashTable *h, KeyType k, ValueType v) {
    assert(h != NULL);

	/* Hash the key */
	int hash = _hashValue(k, h->hashID);
	hash = hash % h->tableSize;

    /* Debugging information */
	printf("KEY: %s HASH: %d val:%d \n", k, hash, v);

	/* Empty bucket insert */
    if(h->table[hash] == NULL) {
        struct hashLink *temp = malloc(sizeof(struct hashLink));
        temp->key = k;
        temp->value = v;
        temp->next = NULL;
        h->table[hash] = temp;
        h->count++;
    }
    /* Collision insert */
    else {
        struct hashLink *curr = h->table[hash];
        while(curr->next != NULL && strcmp(curr->key, k) != 0) {
            curr = curr->next;
        }
        /* Duplicate value */
        if(strcmp(curr->key, k) == 0) {
            curr->value = v;
        } else {
            struct hashLink *temp = malloc(sizeof(struct hashLink));
            temp->key = k;
            temp->value = v;
            temp->next = NULL;
            curr->next = temp;
            h->count++;
        }
    }

    /* Resize table if necessary */
	if(tableLoad(h) > LOAD_FACTOR_THRESHOLD) {
        _reSizeTable(h, h->tableSize*2);
	}
}

/*
_reSizeTable: Resizes the hash map to the size, newCap. Rehashes all the current keys.
param1: hashTable - the map
param2: newCap - the new capacity
pre: h is not NULL
pre: newCap is > 0
post: memory for a new hash table has been created
post: new hash table has cap newCap
post: all keys have been re-hashed and inserted into new hash table
post: all the old hash links have been freed
*/
void _reSizeTable(struct hashTable *h, int newCap) {
	printf("*********************** RESIZE ***********************\n");
    assert(h != NULL);
    assert(newCap > 0);

	struct hashLink **temp = h->table; /* Pointer to the old table */
	int tempSize = h->tableSize; /* Size of the old table */
	struct hashLink *curr, *del; /* Used to free the old hash links and iterate through them */

	h->table = malloc(sizeof(struct hashLink*)*newCap); /* New larger table */
	_initMap(h, newCap, h->hashID);

	/* Re-hash links in new table */
    int i;
    for(i = 0; i < tempSize; i++) {
        curr = temp[i];
        while(curr != NULL) {
            insertMap(h, curr->key, curr->value);
            del = curr;
            curr = curr->next;
            free(del);
            del = 0;
        }
    }
    free(temp);
    temp = 0;
}

/*
containsKey: determines whether the key is contained in the map
param1: h - the map
param2: k - the key to search for
pre: h is not null
post: none
return: return 0 is not found, otherwise return 1
*/
int containsKey(struct hashTable *h, KeyType k) {
	assert(h != NULL);

    int hash = _hashValue(k, h->hashID);
    hash = hash % h->tableSize;

    struct hashLink *curr = h->table[hash];
    while(curr != NULL) {
        if (strcmp(curr->key, k) == 0) {
            return 1;
        }
        curr = curr->next;
    }
	return 0;
}

/*
removeKey: find the hash link for the key and remove it
param1: h - the map
param2: k - the key to remove
pre: h is not NULL
post: key has been removed from the table
post: if unable to find the key, then print an appropriate message
post: count has been decremented
post: memory for the hash link has been freed
 */
void removeKey(struct hashTable *h, KeyType k) {
    assert(h != NULL);

    int hash = _hashValue(k, h->hashID);
    hash = hash % h->tableSize;

    struct hashLink *curr = h->table[hash];
    struct hashLink *prev = NULL;

    while(curr != NULL) {
        if(strcmp(curr->key, k) == 0) {
            if (prev == NULL) {
                h->table[hash] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            curr = 0;
            h->count--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Key not found: %s\n", k);
}

/*
valAtKey: return the value stored at the key
param1: h - the map
param2: k - the key to search for
return: return the value found at the key - return 0 if not found
pre: h is not null
pre: k is in the hash table
post: none
*/
ValueType valAtKey(struct hashTable *h, KeyType k) {
    assert(h != NULL);
    assert(containsKey(h, k) == 1);

    int hash = _hashValue(k, h->hashID);
    hash = hash % h->tableSize;

    struct hashLink *curr = h->table[hash];
    while(curr != NULL) {
        if (strcmp(curr->key, k) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
	return 0;
}

/*
getEmptyBuckets: returns the number of empty buckets in the table, these are buckets which have no hashLinks in them
param1: h - the hash table
pre: h is not null
post: no changes to the table
return: the number of empty buckets in the table
*/
int getEmptyBuckets(struct hashTable *h) {
    assert(h != NULL);

    int emptyCount = 0;
    int i;
    for(i = 0; i < h->tableSize; i++) {
        if (h->table[i] == NULL) {
            emptyCount++;
        }
    }
	return emptyCount;
}

/*
getFullBuckets: returns the number of hashLinks in the map
param1: h - the map
pre: h is not NULL
return: the bucketCount of the hash table
post: none
*/
int getFullBuckets(struct hashTable *h) {
    assert(h != NULL);

    int fullCount = 0;
    int i;
    for(i = 0; i < h->tableSize; i++) {
        if (h->table[i] != NULL) {
            fullCount++;
        }
    }
    return fullCount;
}

/*
getLinkCount: returns the number of hashLinks in the map
param1: h - the map
pre: h is not NULL
return: the number of hash links in the table
post: none
*/
int getLinkCount(struct hashTable *h) {
    assert(h != NULL);

    int linkCount = 0;
    int i;
    for(i = 0; i < h->tableSize; i++) {
        struct hashLink *curr = h->table[i];
        while (curr != NULL) {
            linkCount++;
            curr = curr->next;
        }
    }
    return linkCount;
}

/*
getMapSize: returns the size of the map
param1: h - the hash map
pre: - h is not null
return: return the tableSize
post: no changes to the map
*/
int getMapSize(struct hashTable *h) {
    assert(h != NULL);
	return h->tableSize;
}

/*
tableLoad: determine the load of the table
there are a couple ways you can calculate this - we want full buckets / total buckets
we are not concerned with the number of hash links - we are assuming a reasonable hash
param1: h - the hash table
pre: h is not null
post: no changes to the table
return: returns the ratio of: full buckets / table size
*/
float tableLoad(struct hashTable *h) {
    assert(h != NULL);
	return (float)getFullBuckets(h) / getMapSize(h);
}

/*
printMap: prints the contents of the hash map
param1: h - the map
pre: h is not NULL
return: contents of the hash map are displayed via standard output - see format below
post: map has been printed to standard output
bucket x: key (value), key (value, ....
Ex. Bucket 1: cat (1), dog (1), the (5)...
*/
void printMap(struct hashTable *h) {
    assert(h != NULL);

    struct hashLink *curr = NULL;
    int i;
    for(i = 0; i < h->tableSize; i++) {
        printf("Bucket %d: ", i);
        curr = h->table[i];
        while(curr != NULL) {
            printf("%s (%d)", curr->key, curr->value);
            if(curr->next != NULL) {
                printf(", ");
            }
            curr = curr->next;
        }
        printf("\n");
    }
}

/*
deleteMap: deallocate buckets and the hash map
param1: h - the hash map
pre: - h is not null
post: memory used by the hash links has been freed - use _freeMap
post: memory used by the hash table has been freed
*/
void deleteMap(struct hashTable *h) {
	assert(h != NULL);

	_freeMap(h); /* Free all memory used by the buckets */
	free(h->table); /* Free the array of hash link pointers */
}

/*
freeMap: free all memory used by the buckets
param1: h - the hash map
pre: - h is not null
post: memory used by the hash buckets has been freed
*/
void _freeMap (struct hashTable *h) {
    assert(h != NULL);

    struct hashLink *curr, *temp;
    int i;
    for(i = 0; i < h->tableSize; i++) {
        curr = h->table[i];
        while(curr != NULL) {
            temp = curr;
            curr = curr->next;
            free(temp);
            temp = 0;
        }
    }
}

/*
concordance: create a hash table which contains word frequencies
param1: h - the hash table
param2: word - the current word to hash
pre: h is not NULL
post: key and value is now updated
if the key already exists, add 1 to the value
*/
void concordance(struct hashTable *h, char *word) {
    assert(h != NULL);

    if (containsKey(h, word)) {
        int currentVal = valAtKey(h, word);
        insertMap(h, word, currentVal + 1);
    } else {
        insertMap(h, word, 1);
    }
}
