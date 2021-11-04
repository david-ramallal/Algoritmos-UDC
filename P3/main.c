#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define TESTMAX 17
#define THRESHOLD 1


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

void swap(int v[], int i, int j)
{
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void median3 (int v[], int i, int j)
{
    int k;
    k = (i + j) / 2;                     /* precondition: i < j */
    if (v[k] > v[j]){
        swap( v, i, j);
    }
    if(v[k] > v[i]){
        swap( v, k, i);
    }
    if(v[i] > v[j]){
        swap( v, i, j);
    }
}

void sort_aux(int v[], int left, int right)
{
    int pivot, i, j;
    if(left + THRESHOLD <= right){
        median3( v, left, right);
        pivot = v[left];
        i = left;
        j = right;
        do{
            do{
                i = i + 1;
            }while(v[i] < pivot);
            do{
                j = j - 1;
            }while(v[j] > pivot);
            swap( v, i, j);
        }while(j > i);
        swap( v, i, j);
        swap( v, left, j);
        sort_aux(v, left, j-1);
        sort_aux(v, j+1, right);
    }
}

void quick_sort(int v [], int n) {
    sort_aux(v, 0, n-1);
    if (THRESHOLD > 1)
        ins_sort(v, n);
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

double exeFunction (int n, void functionInit(), void functionSort()){
    double t, ta, tb, t1, t2;
    int v[n], i;
    functionInit(v,n);
    ta = microseconds();
    functionSort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            functionInit(v,n);
            functionSort(v,n);
        }
        tb = microseconds();
        t1 = tb - ta;
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            functionInit(v,n);
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

void testQuick()
{
    int v[TESTMAX];
    init_seed();
    random_init(v, TESTMAX);
    printf("Quicksort with random initialization\n");
    print_array(v, TESTMAX);
    printf("sorting...\n");
    quick_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");

    descending_init(v, TESTMAX);
    printf("Quicksort with descending initialization\n");
    print_array(v, TESTMAX);
    printf("sorting...\n");
    quick_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");

    ascending_init(v, TESTMAX);
    printf("Quicksort with ascending initialization\n");
    print_array(v, TESTMAX);
    printf("sorting...\n");
    quick_sort(v,TESTMAX);
    print_array(v, TESTMAX);
    printf("\n");
}

void printFunctionIns (void function())
{
    int i;
    printf("%4sn%14st(n)%12st(n)/n^1.8%12st(n)/n^2%14st(n)/n^2.2%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(exeFunction(i, function, ins_sort) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",exeFunction(i, function, ins_sort),"",
                   exeFunction(i, function, ins_sort)/pow(i,1.8),"",
                   exeFunction(i, function, ins_sort)/pow(i,2),"",
                   exeFunction(i, function, ins_sort)/pow(i,2.2),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f\n"
                    , i,"",exeFunction(i, function, ins_sort),"",
                   exeFunction(i, function, ins_sort)/pow(i,1.8),"",
                   exeFunction(i, function, ins_sort)/pow(i,2),"",
                   exeFunction(i, function, ins_sort)/pow(i,2.2));
        }
    }
}

void printFunctionInsBestCase (void function())
{
    int i;
    printf("%4sn%14st(n)%12st(n)/n^0.8%14st(n)/n%14st(n)/n^1.2%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(exeFunction(i, function, ins_sort) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",exeFunction(i, function, ins_sort),"",
                   exeFunction(i, function, ins_sort)/pow(i,0.8),"",
                   exeFunction(i, function, ins_sort)/i,"",
                   exeFunction(i, function, ins_sort)/pow(i,1.2),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s\n"
                    , i,"",exeFunction(i, function, ins_sort),"",
                   exeFunction(i, function, ins_sort)/pow(i,0.8),"",
                   exeFunction(i, function, ins_sort)/i,"",
                   exeFunction(i, function, ins_sort)/pow(i,1.2),"");
        }
    }
}

void printFunctionQuick (void function())
{
    int i;
    printf("%4sn%14st(n)%16st(n)/n%6st(n)/n*(log n)%13st(n)/n^1.5%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(exeFunction(i, function, quick_sort) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",exeFunction(i, function, quick_sort),"",
                   exeFunction(i, function, quick_sort)/(i),"",
                   exeFunction(i, function, quick_sort)/(i*log(i)),"",
                   exeFunction(i, function, quick_sort)/pow(i,1.5),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f\n"
                    , i,"",exeFunction(i, function, quick_sort),"",
                   exeFunction(i, function, quick_sort)/(i),"",
                   exeFunction(i, function, quick_sort)/(i*log(i)),"",
                   exeFunction(i, function, quick_sort)/pow(i,1.5));
        }
    }
}

int main() {
    testInsert();
    testQuick();

    printf("\nInsertion sort with random initialization\n");
    printFunctionIns(random_init);
    printf("\nInsertion sort with ascending initialization\n");
    printFunctionInsBestCase(ascending_init);
    printf("\nInsertion sort with descending initialization\n");
    printFunctionIns(descending_init);

    printf("\nQuicksort with random initialization\n");
    printFunctionQuick(random_init);
    printf("\nQuicksort with ascending initialization\n");
    printFunctionQuick(ascending_init);
    printf("\nQuicksort with descending initialization\n");
    printFunctionQuick(descending_init);


    printf("\n(*) means that measurement corresponds to "
           "an average time over K(1000 in this case) "
           "executions of the algorithm\n");
    return 0;
}