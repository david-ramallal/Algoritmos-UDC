#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TESTMAX 17

void ins_sort (int v[], int n)
{
    int i, x, j;
    for(i = 1; i < n; i++){
        x = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = x;
    }
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

bool isSorted (const int v[], int n) {
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
        printf("sorted\n");
    else
        printf("sorted? 0\n");
}

double exeRandomIns (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    init_seed();
    random_init(v, n);
    ta = microseconds();
    ins_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            random_init(v, n);
            ins_sort(v,n);
        }
        tb = microseconds();
        t1 = tb - ta;
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            random_init(v, n);
        }
        tb = microseconds();
        t2 = tb - ta;
        t = (t1 - t2) / 1000;
    }
    return t;
}

double exeAscIns (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    ascending_init(v,n);
    ta = microseconds();
    ins_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            ascending_init(v,n);
            ins_sort(v,n);
        }
        tb = microseconds();
        t1 = tb - ta;
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            ascending_init(v,n);
        }
        tb = microseconds();
        t2 = tb - ta;
        t = (t1 - t2) / 1000;
    }
    return t;
}

double exeDesIns (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    descending_init(v,n);
    ta = microseconds();
    ins_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            descending_init(v,n);
            ins_sort(v,n);
        }
        tb = microseconds();
        t1 = tb - ta;
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            descending_init(v,n);
        }
        tb = microseconds();
        t2 = tb - ta;
        t = (t1 - t2) / 1000;
    }
    return t;
}

void testInsert()
{
    int v[TESTMAX];
    init_seed();
    random_init(v, TESTMAX);
    printf("Insertion sort with random initialization\n");
    print_array(v, TESTMAX);
    printf("sorting...\n");
    ins_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");

    descending_init(v, TESTMAX);
    printf("Insertion sort with descending initialization\n");
    print_array(v, TESTMAX);
    printf("sorting...\n");
    ins_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");

    ascending_init(v, TESTMAX);
    printf("Insertion sort with ascending initialization\n");
    print_array(v, TESTMAX);
    printf("sorting...\n");
    ins_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");
}

void printFunctionIns (double function())
{
    int i;
    printf("%4sn%14st(n)%12st(n)/n^1.8%12st(n)/n^2%14st(n)/n^2.2%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(function(i) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",function(i),"",
                   function(i)/pow(i,1.8),"",
                   function(i)/pow(i,2),"",
                   function(i)/pow(i,2.2),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f\n"
                    , i,"",function(i),"",
                   function(i)/pow(i,1.8),"",
                   function(i)/pow(i,2),"",
                   function(i)/pow(i,2.2));
        }
    }
}

void printFunctionInsBestCase (double function())
{
    int i;
    printf("%4sn%14st(n)%12st(n)/n^0.8%14st(n)/n%14st(n)/n^1.2%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(function(i) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",function(i),"",
                   function(i)/pow(i,0.8),"",
                   function(i)/i,"",
                   function(i)/pow(i,1.2),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s\n"
                    , i,"",function(i),"",
                   function(i)/pow(i,0.8),"",
                   function(i)/i,"",
                   function(i)/pow(i,1.2),"");
        }
    }
}

int main() {
    testInsert();
    printf("\n");

    printf("\nInsertion sort with random initialization\n");
    printFunctionIns(exeRandomIns);
    printf("\nInsertion sort with ascending initialization\n");
    printFunctionInsBestCase(exeAscIns);
    printf("\nInsertion sort with descending initialization\n");
    printFunctionIns(exeDesIns);


    printf("\n(*) means that measurement corresponds to "
           "an average time over K(1000 in this case) "
           "executions of the algorithm\n");
    return 0;
}
