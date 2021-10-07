#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>


#define TESTMAX 17

void sel_sort(int v[], int n)
{
    int i, j, minj, minx;
    for(i = 0; i < n - 1; i++){
        minj = i;
        minx = v[i];
        for(j = i + 1; j < n; j++ ){
            if(v[j] < minx){
                minj = j;
                minx = v[j];
            }
        }
        v[minj] = v[i];
        v[i] = minx;
    }
}

void shell_sort(int v[], int n)
{
    int i, j, tmp, increment = n;
    bool keepgoing;
    do {
        increment = increment / 2;
        for(i = increment + 1; i < n; i++){
            tmp = v[i];
            j = i;
            keepgoing = true;
            while((j - increment > 0) && keepgoing){
                if(tmp < v[j - increment]){
                    v[j] = v[j - increment];
                    j = j - increment;
                }else
                    keepgoing = false;
            }
            v[j] = tmp;
        }
    }while (increment != 1);
}

void init_seed() {
    /* set the seed of a new sequence of pseudo-random integers */
    srand(time(NULL));
}
void random_init(int v [], int n) {
    /* generate pseudo-random numbers between -n and +n */
    int i, m=2*n+1;
    for (i = 0; i < n; i++)
        v[i] = (rand() % m) - n;
}

void ascending_init(int v [], int n) {
    int i;
    for (i=0; i < n; i++)
        v[i] = i;
}

void descending_init(int v [], int n) {
    int i, j = 0;
    for (i = n; i > 0; i--){
        v[j] = i;
        j++;
    }
}

bool isSorted (int v [], int n) {
    int i;

    for(i = 1; i < n; i++) {
        if(v[i-1] > v[i])
            return false;
    }
    return true;
}

void print_array(int v[], int n){
    int i;
    for(i = 0; i < n -1; i++) {
        printf("%3d, ",v[i]);
    }
    printf("%3d\n",v[i]);
    if(isSorted(v,n))
        printf("sorted? 1\n");
    else
        printf("sorted? 0\n");
}

void test1() {
    int v[TESTMAX];
    init_seed();
    random_init(v, TESTMAX);
    printf("Random initialization\n");
    print_array(v, TESTMAX);
    printf("Selection sort\n");
    sel_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");

    random_init(v, TESTMAX);
    printf("Random initialization\n");
    print_array(v, TESTMAX);
    printf("Shell sort\n");
    shell_sort(v,TESTMAX);
    print_array(v, TESTMAX);
}

void test2() {
    int v[10];
    descending_init(v,10);
    printf("Descending initialization\n");
    print_array(v, 10);
    printf("Selection sort\n");
    sel_sort(v,10);
    print_array(v, 10);
    printf("\n");

    descending_init(v,10);
    printf("Descending initialization\n");
    print_array(v, 10);
    printf("Shell sort\n");
    shell_sort(v, 10);
    print_array(v, 10);
}

int main() {
    test1();
    test2();
}
