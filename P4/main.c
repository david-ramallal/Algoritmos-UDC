#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "Queue.h"

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
    i=0;
    while(i < nodes -1 )
    {
        min = 99;
        for(j = 1; j < nodes; j++)
        {
            if(0 <= minDistance[j] && minDistance[j] < min)
            {
                min = minDistance[j];
                k = j;
            }
        }
        //hay que meter la T del conjunto
        a.x = closest[k];
        a.y = k;
        a.weight = *m[closest[k] , k];
        enqueue(a, edges);

        minDistance[k] = -1;
        for(j=1; j < nodes; j++)
        {
            if(*m[j,k] < minDistance[j])
            {
                minDistance[j] = *m[j,k];
                closest[j] = k;
            }
        }
        i++;
    }
    // return T
    show_queue(*edges);   // <-   <-   <-   <-
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

double microseconds() {
    /* obtains the system time in microseconds */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

void init_seed() {
    /* set the seed of a new sequence of pseudo-random integers */
    srand(time(NULL));
}

void test1(){
    matrix m = create_matrix(5);
    m[0][0] = 0, m[0][1] = 1, m[0][2] = 8, m[0][3] = 4, m[0][4] = 7;
    m[1][0] = 1, m[1][1] = 0, m[1][2] = 2, m[1][3] = 6, m[1][4] = 5;
    m[2][0] = 8, m[2][1] = 2, m[2][2] = 0, m[2][3] = 9, m[2][4] = 5;
    m[3][0] = 4, m[3][1] = 6, m[3][2] = 9, m[3][3] = 0, m[3][4] = 3;
    m[4][0] = 7, m[4][1] = 5, m[4][2] = 5, m[4][3] = 3, m[4][4] = 0;

    queue edges;
    prim(m,5, &edges);
    free_matrix(m,5);
}

int main() {
    test1();


    return 0;
}
