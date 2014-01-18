#include "LRU.h"
#include <stdlib.h>

hTable* createHash(int max_pos) {
	int i;
	hTable *table = (hTable *) malloc(sizeof(hTable));
	table->hashSize = max_pos;

	table->ptr = (cnode **) malloc(max_pos * sizeof(cnode *));
	for (i = 0; i < max_pos; i++) {
		table->ptr[i] = NULL;
	}
}

freeList* createQueue(int max_size) {
	freeList *queue = (freeList *) malloc(sizeof(freeList));
	queue->maxPages = max_size;

	queue->head = queue->tail = NULL;
	queue->count = 0;

	return queue;
}

void dequeue(freeList *queue, hTable *htable, unsigned int pageNumber) {
	int position = pageNumber % htable->hashSize;

	//empty hash entry
        htable->ptr[position] = NULL;

	// remove the element at queue tail

	// If this is the only node in list, then change front
    	if (queue->head == queue->tail)
        	queue->head = NULL;
 
    	// Change rear and remove the previous rear
    	cnode* temp = queue->tail;
    	queue->tail = queue->tail->prev;
 
    	if (queue->tail)
        	queue->tail->next = NULL;
 
	free(temp);
 
    	// decrement the number of full frames by 1
    	queue->count--;
}

// Get the page to cache
void enqueue(freeList *queue, hTable *htable, unsigned int pageNumber) {
	int position = pageNumber % htable->hashSize;
	cnode *newnode = (cnode *) malloc(sizeof(cnode));

	// If cache is full, remove a page from the queue tail.
	if (queue->count == queue->maxPages) {
		dequeue(queue, htable, pageNumber);
	}
	
	// Insert node at the head of queue.
	newnode->value = pageNumber;
	if (queue == NULL) {
		newnode->next = newnode->prev = NULL;
		queue->tail = newnode;	
	} else {
		newnode->next = queue->head;
		queue->head->prev = newnode;
		newnode->prev = queue->head;
	} 
	queue->head = newnode;

	// update hash table
	htable->ptr[position] = newnode;	

	// increment queue count
	queue->count++;
}

void referencePage(freeList *queue, hTable *htable, unsigned int pageNumber) {
	int position = pageNumber % htable->hashSize;
	cnode *page;
	if (htable->ptr[position] != NULL) {
		page = htable->ptr[position];
	} else {
		page = NULL;
	}
	
	// If page not at position, get it into cache. Here call enqueue.
	// If page is already in cache, move it to the head of queue and return. 
	
	if (page == NULL) {
		enqueue(queue, htable, pageNumber);
	} else if (page != queue->head) {
		// move the queue to head
		page->prev->next = page->next;

		if (page == queue->tail) {
			queue->tail = page->prev;
		} else {
			page->next->prev = page->prev;
		}		
		// put page in front	
		page->next = queue->head;
		page->prev = NULL;
		
		// make current head's prev point to page
		page->next->prev = page;
		// head now points to page.
		queue->head = page;
	}
}

int main() {
	freeList *q = createQueue(10);
	hTable *hash = createHash(20);

	referencePage( q, hash, 1);
    	referencePage( q, hash, 2);
    	referencePage( q, hash, 3);
    	referencePage( q, hash, 1);
    	referencePage( q, hash, 4);
    	referencePage( q, hash, 5);

	cnode *tmp  = q->head;
	while (tmp != NULL) {
		printf("%d\n",tmp->value);
		tmp = tmp->next;
	}
}
