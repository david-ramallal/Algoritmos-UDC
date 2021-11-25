#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void CreateQueue(queue *Q) {
    Q->size = 0;
    Q->front_index = 0;
    Q->rear_index = -1;
}

int EmptyQueue (queue Q) {
    return (Q.size == 0);
}

void Increment(int *x) { /* private */
    if (++(*x ) == MAX_SIZE)
    *x = 0;
}

void Enqueue (element_type x, queue *Q) {
    if (Q->size == MAX_SIZE) {
        printf("error: Full Queue: %d\n", Q->size) ;
        exit( EXIT_FAILURE);
    }
    Q->size++;
    Increment(&(Q->rear_index));
    Q->vector[Q->rear_index] = x;
}

element_type Front(queue Q) {
    if (EmptyQueue(Q)) {
        printf("error: Empty Queue\n");
        exit(EXIT_FAILURE);
    }
    return(Q.vector[Q.front_index]);
}

element_type Dequeue(queue *Q) {
    element_type x;
    if(EmptyQueue (*Q)) {
        printf("error: EmptyQueue\n");
        exit(EXIT_FAILURE);
    }
    Q->size--;
    x = Q->vector[Q->front_index];
    Increment(&(Q->front_index));
    return x;
}

void show_queue(queue Q){
    //hay que hacerla
}