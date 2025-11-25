#include "ready-queue.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(queue *q) {
	q->tail = NULL;
	q->head = NULL;
}

void free_queue(queue *q) {
	node *tmp;
	while (q->head != NULL) {
		tmp = q->head;
		q->head = q->head->next;
		free(tmp);
	}
	q->tail = NULL;
}

int enqueue(queue *q, process p) {
	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = p;
	new_node->next = NULL;

	if (q->tail == NULL) {
		q->head = q->tail = new_node;
		return -1;
	}

	q->tail->next = new_node;
	q->tail = new_node;
	return 0;
}

int dequeue(queue *q, process *p) {
	if (q->tail == NULL) {
		printf("The Ready Queue is empty\n");
		return -1;
	}

	*p = q->tail->data;
	node *tmp = q->head;
	q->head = q->head->next;
	if (q->head == NULL) {
		q->tail = NULL;
	}
	free(tmp);
	return 0;
}

void display_queue(queue *q) {
	node *tmp = q->head;
	while (tmp != NULL) {
		printf("P%u ", tmp->data.pid);
		tmp = tmp->next;
	}
	printf("\n");
}
