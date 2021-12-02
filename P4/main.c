#include <stdio.h>
#include <sys/time.h>
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
        a.x = closest[k];
        a.y = k;
        a.weight = m[closest[k]][k];
        enqueue(a, edges);

        minDistance[k] = -1;
        for(j=1; j < nodes; j++)
        {
            if(m[j][k] < minDistance[j])
            {
                minDistance[j] = m[j][k];
                closest[j] = k;
            }
        }
        i++;
    }
    //show_queue(*edges);
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

void printMatrix(matrix m, int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++)
            printf("%3d", m[i][j]);
        printf("\n");
    }
}

double exeFunction (int n){
    double t, ta, tb, t1, t2;
    matrix m = create_matrix(n);
    queue edges;
    int i;
    init_matrix(m,n);
    ta = microseconds();
    prim(m,n,&edges);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            init_matrix(m,n);
            prim(m,n,&edges);
        }
        tb = microseconds();
        t1 = tb - ta;
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            init_matrix(m,n);
        }
        tb = microseconds();
        t2 = tb - ta;
        t = (t1 - t2) / 1000;
    }
    return t;
}

void test1(){
    matrix m = create_matrix(5);
    m[0][0] = 0, m[0][1] = 1, m[0][2] = 8, m[0][3] = 4, m[0][4] = 7;
    m[1][0] = 1, m[1][1] = 0, m[1][2] = 2, m[1][3] = 6, m[1][4] = 5;
    m[2][0] = 8, m[2][1] = 2, m[2][2] = 0, m[2][3] = 9, m[2][4] = 5;
    m[3][0] = 4, m[3][1] = 6, m[3][2] = 9, m[3][3] = 0, m[3][4] = 3;
    m[4][0] = 7, m[4][1] = 5, m[4][2] = 5, m[4][3] = 3, m[4][4] = 0;
    printf("Matrix: Test1\n");
    printMatrix(m,5);

    queue edges;
    prim(m,5, &edges);
    free_matrix(m,5);
}

void test2(){
    matrix m = create_matrix(4);
    m[0][0] = 0, m[0][1] = 1, m[0][2] = 4, m[0][3] = 7;
    m[1][0] = 1, m[1][1] = 0, m[1][2] = 2, m[1][3] = 8;
    m[2][0] = 4, m[2][1] = 2, m[2][2] = 0, m[2][3] = 3;
    m[3][0] = 7, m[3][1] = 8, m[3][2] = 3, m[3][3] = 0;
    printf("Matrix: Test2\n");
    printMatrix(m,4);

    queue edges;
    prim(m,4, &edges);
    free_matrix(m,4);
}

void test3(){
    matrix m = create_matrix(7);
    m[0][0] = 0,  m[0][1] = 7,  m[0][2] = 99, m[0][3] = 5,  m[0][4] = 99, m[0][5] = 99, m[0][6] = 99;
    m[1][0] = 7,  m[1][1] = 0,  m[1][2] = 8,  m[1][3] = 9,  m[1][4] = 7,  m[1][5] = 99, m[1][6] = 99;
    m[2][0] = 99, m[2][1] = 8,  m[2][2] = 0,  m[2][3] = 99, m[2][4] = 5,  m[2][5] = 99, m[2][6] = 99;
    m[3][0] = 5,  m[3][1] = 9,  m[3][2] = 99, m[3][3] = 0,  m[3][4] = 15, m[3][5] = 6,  m[3][6] = 99;
    m[4][0] = 99, m[4][1] = 7,  m[4][2] = 5,  m[4][3] = 15, m[4][4] = 0,  m[4][5] = 8,  m[4][6] = 9;
    m[5][0] = 99, m[5][1] = 99, m[5][2] = 99, m[5][3] = 6,  m[5][4] = 8,  m[5][5] = 0,  m[5][6] = 11;
    m[6][0] = 99, m[6][1] = 99, m[6][2] = 99, m[6][3] = 99, m[6][4] = 9,  m[6][5] = 11, m[6][6] = 0;
    printf("Matrix: Test3\n");
    printMatrix(m,7);

    queue edges;
    prim(m,7, &edges);
    free_matrix(m,7);

}

void printFunction(double function())
{
    int i;
    printf("%4sn%14st(n)%12st(n)/n^1.8%12st(n)/n^2%14st(n)/n^2.2%s\n"
            ,"","","","","","");
    for(i = 25; i <= 1600; i = i*2){
        if(function(i) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",function(i),"",
                   function(i)/(pow(i,1.8)),"",
                   function(i)/(pow(i,2)),"",
                   function(i)/(pow(i,2.2)),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f\n"
                    , i,"",function(i),"",
                   function(i)/(pow(i,1.8)),"",
                   function(i)/(pow(i,2)),"",
                   function(i)/(pow(i,2.2)));
        }
    }
}

int main() {
    test1();
    test2();
    test3();

    printf("\nPrim's Algorithm with random adjacency matrix:\n");
    printFunction(exeFunction);

    printf("\n(*) means that measurement corresponds to "
           "an average time over K(1000 in this case) "
           "executions of the algorithm\n");
    return 0;
}
