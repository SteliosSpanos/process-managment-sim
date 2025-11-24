#pragma once
#include "process.h"

typedef struct node {
	process data;
	struct node *next;
} node;

typedef struct queue {
	node *tail;
	node *head;
} queue;

void init_queue(queue *q);

int is_empty(queue *q);

int enqueue(queue *q, process p);

int dequeue(queue *q);

void display_queue(queue *q);

