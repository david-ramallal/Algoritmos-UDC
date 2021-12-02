#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void create_queue(queue *Q) {
    Q->size = 0;
    Q->front_index = 0;
    Q->rear_index = -1;
}

int empty_queue(queue Q) {
    return (Q.size == 0);
}

void Increment(int *x) { /* private */
    if (++(*x ) == MAX_SIZE)
    *x = 0;
}

void enqueue(element_type x, queue *Q) {
    if (Q->size == MAX_SIZE) {
        printf("error: Full Queue: %d\n", Q->size) ;
        exit( EXIT_FAILURE);
    }
    Q->size++;
    Increment(&(Q->rear_index));
    Q->vector[Q->rear_index] = x;
}

element_type front(queue Q) {
    if (empty_queue(Q)) {
        printf("error: Empty Queue\n");
        exit(EXIT_FAILURE);
    }
    return(Q.vector[Q.front_index]);
}

element_type dequeue(queue *Q) {
    element_type x;
    if(empty_queue(*Q)) {
        printf("error: EmptyQueue\n");
        exit(EXIT_FAILURE);
    }
    Q->size--;
    x = Q->vector[Q->front_index];
    Increment(&(Q->front_index));
    return x;
}

void show_queue(queue Q){
    int i, weight = 0;

    printf("Edges: ");
    for(i=0; i<Q.size - 1  ;i++){
        printf("(%d,%d), ", Q.vector[i].x, Q.vector[i].y);
        weight += Q.vector[i].weight;
    }
    printf("(%d,%d)\n", Q.vector[i].x, Q.vector[i].y);
    weight += Q.vector[i].weight;
    printf("Weight: %d\n", weight);
}