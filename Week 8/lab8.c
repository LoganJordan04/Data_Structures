/*
Logan Jordan - 11/12/24
lab8.c: Max Heap-based priority queue implementation using a dynamic array and testing
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define TYPE int

struct DynArr {
    TYPE *data; /* pointer to the data array */
    int size; /* number of elements in the array */
    int capacity; /* capacity of the array */
};

struct Heap {
    struct DynArr *d;
};

void percolateUp(struct Heap *h, int pos);
void percolateDown(struct Heap *h, int pos);


/*
initDynArr: Initialize (including allocation of data array) dynamic array.
param1: d - pointer to the dynamic array
param2 : capacity - capacity of the dynamic array
pre: d is not null
post: internal data array can hold cap elements
post: d->data is not null
*/
void initDynArr(struct DynArr *d, int capacity) {
    assert(capacity > 0);
    assert(d != NULL);
    d->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
    assert(d->data != NULL);
    d->size = 0;
    d->capacity = capacity;
}

/*
createDynArr: Allocate and initialize dynamic array.
param: cap desired capacity for the dynamic array
pre: none
post: none
ret: a pointer to an empty dynArr of cap capacity
*/
struct DynArr *createDynArr(int cap) {
    assert(cap > 0);
    struct DynArr *dyn;
    dyn = malloc(sizeof(struct DynArr));
    if(!dyn) {
        printf("Failed to allocate memory \n");
    }
    initDynArr(dyn,cap);
    return dyn;
}

/*
addDynArr: Adds an element to the end of the dynamic array
param: d pointer to the dynamic array
param: val the value to add to the end of the dynamic array
pre: the dynArray is not null
post: size increases by 1
post: if reached capacity, capacity is doubled
post: val is in the last utilized position in the array
*/
void addDynArr(struct DynArr *d, TYPE val) {
    assert(d != NULL);
    /* If full, then re-size */
    if(d->size >= d->capacity) {
        d->capacity *= 2;
        d->data = realloc(d->data, d->capacity);
    }
    d->data[d->size] = val;
    d->size++;
}

/*
putDynArr: Put an item into the dynamic array at the specified location,
overwriting the element that was there
param1: d - pointer to the dynamic array
param2: pos - the index to put the value into
param3: val - the value to insert
pre: d is not null
pre: pos >= 0 and pos
pre: pos < capacity
post: index (pos) contains new value (val)
*/
void putDynArr(struct DynArr *d, int pos, TYPE val) {
    assert(d != NULL);
    assert(pos >= 0);
    assert(pos < d->capacity);
    d->data[pos] = val;
}

/*
swapDynArr: Swap two specified elements in the dynamic array
param1: d - pointer to the dynamic array
param2: i - one of the elements to be swapped
param3: j - one of the elements to be swapped
pre: d is not null
pre: d is not empty
pre: i >= to 0
pre: j >= to 0
pre: i < size of the dynamic array
pre: j < size of the dynamic array
post: index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(struct DynArr *d, int i, int j) {
    TYPE temp;
    assert(d != NULL);
    assert(i < d->size);
    assert(j < d->size);
    assert(i >= 0);
    assert(j >= 0);
    temp = d->data[i];
    d->data[i] = d->data[j];
    d->data[j] = temp;
}

/*
getValDynArr: Return the value from the specified index position from a
dynamic array
param1: d - pointer to the dynamic array
param2: pos - location of element to remove
return: value at the specified index position
pre: d is not null
pre: d is not empty
pre: pos >= 0
pre: pos < size
post: no changes to the dynamic array
*/
TYPE getValDynArr(struct DynArr *d, int pos) {
    assert(d != NULL);
    assert(pos < d->size);
    assert(pos >= 0);
    return d->data[pos];
}

/*
removeAtDynArr: Remove the element at the specified location from the array,
shifts other elements back one to fill the gap
param1: d - pointer to the dynamic array
param2: pos - location of element to remove
pre: d is not null
pre: d is not empty
pre: pos >= 0
pre: pos < size
post: the element at pos is removed
post: the elements past pos are shifted back one
*/
void removeAtDynArr(struct DynArr *d, int pos) {
    int i;
    assert(d != NULL);
    assert(pos < d->size);
    assert(pos >= 0);
    /* Shift all elements up */
    for(i = pos; i < d->size-1; i++){
        d->data[i] = d->data[i+1];
    }
    d->size--;
}

/*
printHeap: Populate
param: heap - the dynamic array
pre: dynamic array is not NULL
post: the values are printed from the first to last positions in the array
post: no changes to the dynamic array
*/
void printDynArr(struct DynArr *d) {
    int i = 0;
    while(i < d->size) {
        printf("%d ", d->data[i]);
        i++;
    }
    printf("\n");
}

/* ------------------ Heap-based priority queue implementation ------------------ */

/*
initHeap: initialize max-heap
param1: h - pointer to the max-heap
param2: cap - the capacity of the underlying dynamic array
pre: heap is not null
pre: cap > 0
post: memory is allocated to the dynamic array - use createDynArr()
*/
void initHeap(struct Heap *h, int cap) {
    assert(h != NULL);
    assert(cap > 0);
    h->d = createDynArr(cap);
}

/*
pushHeap: add a value to the max-heap
param1: heap - pointer to the max-heap
param2: node - node to be added to the max-heap
pre: heap is not null
post: node is added to the heap
post: heap properties are maintained
post: heap size is incremented
*/
void pushHeap(struct Heap *h, TYPE val) {
    printf("adding %d\n", val);
    assert(h != NULL);

    addDynArr(h->d, val);
    percolateUp(h, h->d->size-1);
}

/*
percolateUp: swap a value up into place in a max-heap
param1: heap - pointer to the max-heap
param2: pos - the index position of the node to be swapped up
pre: heap is not null
pre: pos >= 0
pre: pos < heap size
post: heap properties are maintained
*/
void percolateUp(struct Heap *h, int pos) {
    assert(h != NULL);
    assert(pos >= 0 && pos < h->d->size);

    int parent = (pos-1)/2;
    while(pos > 0) {
        if(h->d->data[pos] > h->d->data[parent]) {
            swapDynArr(h->d, pos, parent);
            pos = parent;
            parent = (pos-1)/2;
        } else {
            return;
        }
    }
}

/*
popHeap: remove a value to the max-heap
param1: heap - pointer to the max-heap
pre: heap is not null
pre: heap is not empty
post: heap properties are maintained
post: heap size is decremented
*/
void popHeap(struct Heap *h) {
    printf("popping %d\n", getValDynArr(h->d, 0));
    assert(h != NULL);
    assert(h->d->size > 0);

    swapDynArr(h->d, 0, h->d->size-1);
    removeAtDynArr(h->d, h->d->size-1);
    percolateDown(h, 0);
}

/*
percolateDown: swap the root down into place in a max-heap
param1: heap - pointer to the max-heap
pre: heap is not null
pre: pos >= 0
pre: pos < heap size
post: heap properties are maintained
*/
void percolateDown(struct Heap *h, int pos) {
    assert(h != NULL);
    assert(pos >= 0 && pos < h->d->size);

    int lChild = 0;
    int rChild = 0;
    int larger = 0;

    while((pos*2)-1 < h->d->size) {
        lChild = (pos*2)+1;
        rChild = (pos*2)+2;

        /* figure out where the larger child is */
        if(rChild >= h->d->size) {
            larger = lChild;
        } else if(h->d->data[rChild] > h->d->data[lChild]) {
            larger = rChild;
        } else {
            larger = lChild;
        }

        if(h->d->data[pos] < h->d->data[larger]) {
            swapDynArr(h->d, pos, larger);
            pos = larger;
        } else {
            return;
        }
    }
}

/*
getMinHeap: Get the top value from first node in the max-heap
param: heap - pointer to the heap
pre: heap is not empty
return: value of first node's value
*/
TYPE getHeapMax(struct Heap *h) {
    assert(h->d->size > 0);

    return h->d->data[0];
}

/*
freeHeap: Free the memory for the heap and the underlying dynArr
param: heap - pointer to the heap
pre: none
return: memory has been freed for dynArr, dynArr->data and heap
*/
void freeHeap(struct Heap *h) {
    free(h->d->data);
    h->d->data = 0;
    free(h->d);
    h->d = 0;
    free(h);
    h = 0;
}


int main() {
    struct Heap *heap = malloc(sizeof(struct Heap));
    initHeap(heap, 16);

    printf("-------------TESTING PUSH-------------\n");
    pushHeap(heap, 7);
    pushHeap(heap, 12);
    pushHeap(heap, 3);
    pushHeap(heap, 5);
    pushHeap(heap, 4);
    pushHeap(heap, 11);
    pushHeap(heap, 6);
    printf("Should print: 12 7 11 5 4 3 6\n");
    printDynArr(heap->d);

    printf("-------------TESTING POP-------------\n");
    popHeap(heap);
    printf("Should print: 11 7 6 5 4 3 \n");
    printDynArr(heap->d);
    popHeap(heap);
    printf("Should print: 7 5 6 3 4 \n");
    printDynArr(heap->d);
    freeHeap(heap);

    heap = 0;
    return 0;
}
