#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

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
        for(i = increment; i < n; i++){
            tmp = v[i];
            j = i;
            keepgoing = true;
            while((j - increment >= 0) && keepgoing){
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
    descending_init(v,10);
    printf("Shell sort\n");
    shell_sort(v, 10);
    print_array(v, 10);
}

double exeRandomSel (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    init_seed();
    random_init(v, n);
    ta = microseconds();
    sel_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            random_init(v, n);
            sel_sort(v,n);
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

double exeAscSel (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    ascending_init(v,n);
    ta = microseconds();
    sel_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            ascending_init(v,n);
            sel_sort(v,n);
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

double exeDesSel (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    descending_init(v,n);
    ta = microseconds();
    sel_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            descending_init(v,n);
            sel_sort(v,n);
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

double exeRandomShell (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    init_seed();
    random_init(v, n);
    ta = microseconds();
    shell_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            random_init(v, n);
            shell_sort(v,n);
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

double exeAscShell (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    ascending_init(v,n);
    ta = microseconds();
    shell_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            ascending_init(v,n);
            shell_sort(v,n);
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

double exeDesShell (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    descending_init(v,n);
    ta = microseconds();
    shell_sort(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < 500) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            descending_init(v,n);
            shell_sort(v,n);
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

void printFunctionSel (double function())
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

void printFunctionShell (double function())
{
    int i;
    printf("%4sn%14st(n)%16st(n)/n%6st(n)/n*(log n)%13st(n)/n^1.01%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(function(i) < 500){
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f%3s(*)\n"
                    , i,"",function(i),"",
                   function(i)/(i),"",
                   function(i)/(i*log(i)),"",
                   function(i)/(i*pow(i,1.01)),"");
        } else {
            printf("%5d%7s%11.3f%12s%.8f%10s%.8f%14s%.8f\n"
                    , i,"",function(i),"",
                   function(i)/(i),"",
                   function(i)/(i*log(i)),"",
                   function(i)/(i*pow(i,1.01)));
        }
    }
}

int main() {
    test1();
    printf("\n");
    test2();

    printf("\nSelection sort with random initialization\n");
    printFunctionSel(exeRandomSel);
    printf("\nSelection sort with ascending initialization\n");
    printFunctionSel(exeAscSel);
    printf("\nSelection sort with descending initialization\n");
    printFunctionSel(exeDesSel);

    printf("\nShell sort with random initialization\n");
    printFunctionShell(exeRandomShell);
    printf("\nShell sort with ascending initialization\n");
    printFunctionShell(exeAscShell);
    printf("\nShell sort with descending initialization\n");
    printFunctionShell(exeDesShell);

    printf("\n(*) means that measurement corresponds to "
           "an average time over K(1000 in this case) "
           "executions of the algorithm\n");
    return 0;
}