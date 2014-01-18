#include <stdio.h>

typedef struct cacheNode {
	int value;
	struct cacheNode *next, *prev;
} cnode;

typedef struct hashTable {
	int hashSize;
	cnode **ptr;
} hTable;

// This is the doubly linked list queue
typedef struct Queue {
	int maxPages;
	int count;
	cnode *tail, *head;
} freeList;
