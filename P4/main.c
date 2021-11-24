#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1600

typedef int ** matrix;
typedef struct {
    int x, y, weight;
} edge;

typedef edge element_type;
typedef struct {
    int front_index, rear_index, size;
    element_type vector[MAX_SIZE];
} queue;

void create_queue(queue *);
int empty_queue(queue);
void enqueue(element_type, queue *);
element_type dequeue(queue *);
element_type front(queue);
void show_queue(queue);

void prim(matrix m, int nodes, queue *edges) {
/* calculate the minimum spanning tree returning
the edges of the tree in the ’edges’ queue */
    int min, i, j, k=0;
    edge a;
    int *closest = (int *) malloc(nodes*sizeof(int));
    int *minDistance = (int *) malloc(nodes*sizeof(int));
    create_queue(edges);
    minDistance[0] = -1;
    for(i = 1; i < nodes; i++) {
        closest[i] = 0;
        minDistance[i] = m[i][0];
    }
/*
...
*/
    free(closest);
    free(minDistance);
}

matrix create_matrix(int n) {
    int i;
    matrix aux;
    if ((aux = malloc(n*sizeof(int *))) == NULL)
        return NULL;
    for (i=0; i<n; i++)
        if ((aux[i] = malloc(n*sizeof(int))) == NULL)
            return NULL;
    return aux;
}
void init_matrix(matrix m, int n) {
/* Creates an undirected complete graph with random values between 1 y n */
    int i, j;
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
            m[i][j] = rand() % n + 1;
    for (i=0; i<n; i++)
        for (j=0; j<=i; j++)
            if (i==j)
                m[i][j] = 0;
            else
                m[i][j] = m[j][i];
}
void free_matrix(matrix m, int n) {
    int i;
    for (i=0; i<n; i++)
        free(m[i]);
    free(m);
}


int main() {
    return 0;
}
