#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int maxSubSum1(int v[], int n) {
    int i, j;
    long thisSum, maxSum = 0;
    for (i = 0; i < n; i++) {
        thisSum = 0;
        for (j = i; j < n; j++) {
            thisSum += v[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}
int maxSubSum2(int v[], int n) {
    int j;
    long thisSum = 0, maxSum = 0;
    for(j = 0; j < n; j++) {
        thisSum += v[j];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
        else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}
double microseconds() {
    /* obtains the system time in microseconds */
    struct timeval t;
    if (gettimeofday(&t, NULL) < 0 )
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
void print_array(int v[], int n){
    int i;
    printf("[");
    for(i = 0; i < n-1; i++) {
        printf("%2d\t",v[i]);
    }
    printf("%2d",v[n-1]);
    printf("]");
}
void test1() {
    int i, a, b;
    int v[6][5] = {{-9,2,-5,-4,6},
                   {4,0,9,2,5},
                   {-2,-1,-9,-7,-1},
                   {9,-2,1,-7,-8},
                   {15,-2,-5,-4,16},
                   {7,-5,6,7,-7}
    };
    printf("test1\n");
    printf("%23s%32s%15s\n", "", "maxSubSum1", "maxSubSum2");
    for (i = 0; i < 6; i++) {
        print_array(v[i], 5);
        a = maxSubSum1(v[i], 5);
        b = maxSubSum2(v[i], 5);
        printf("%15d%15d\n", a, b);
    }
    printf("\n");
}
void test2() {
    int i, a, b;
    int v[9];
    printf("test2\n");
    printf("%39s%47s%15s\n", "", "maxSubSum1", "maxSubSum2");
    for (i = 0; i < 10; i++) {
        random_init(v, 9);
        print_array(v, 9);
        a = maxSubSum1(v, 9);
        b = maxSubSum2(v, 9);
        printf("%15d%15d\n", a, b);
    }
}
double executionTime1 (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    random_init(v, n);
    ta = microseconds();
    maxSubSum1(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < n) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            random_init(v, n);
            maxSubSum1(v,n);
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
double executionTime2 (int n){
    double t, ta, tb, t1, t2;
    int v[n], i;
    random_init(v, n);
    ta = microseconds();
    maxSubSum2(v,n);
    tb = microseconds();
    t = tb - ta;
    if (t < n) {
        ta = microseconds();
        for (i = 0; i < 1000; i++){
            random_init(v, n);
            maxSubSum2(v,n);
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
int main() {
    init_seed();
    test1();
    test2();
    int i;
    printf("\nMaxSubSum 1\n"
           "%4sn%14st(n)%10st(n)/n^1.8%10st(n)/n^2%12st(n)/n^2.2%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2){
        if(executionTime1(i) < 500){
            printf("%5d%7s%11.3f%12s%.6f%10s%.6f%14s%.6f%3s(*)\n"
                    , i,"",executionTime1(i),"",
                   executionTime1(i)/pow(i,1.8),"",
                   executionTime1(i)/pow(i,2),"",
                   executionTime1(i)/pow(i,2.2),"");
        } else {
            printf("%5d%7s%11.3f%12s%.6f%10s%.6f%14s%.6f\n"
                    , i,"",executionTime1(i),"",
                   executionTime1(i)/pow(i,1.8),"",
                   executionTime1(i)/pow(i,2),"",
                   executionTime1(i)/pow(i,2.2));
        }
    }
    printf("\nMaxSubSum 2\n"
           "%4sn%14st(n)%10st(n)/n^0.8%12st(n)/n%12st(n)/n^1.2%s\n"
            ,"","","","","","");
    for(i = 500; i <= 32000; i = i*2) {
        if (executionTime2(i) < 500) {
            printf("%5d%7s%11.3f%12s%.6f%10s%.6f%14s%.6f%3s(*)\n"
                    , i, "", executionTime2(i), "",
                   executionTime2(i) / pow(i, 0.8), "",
                   executionTime2(i) / i, "",
                   executionTime2(i) / pow(i, 1.2), "");
        } else {
            printf("%5d%7s%11.3f%12s%.6f%10s%.6f%14s%.6f\n"
                    , i, "", executionTime2(i), "",
                   executionTime2(i) / pow(i, 0.8), "",
                   executionTime2(i) / i, "",
                   executionTime2(i) / pow(i, 1.2));
        }
    }
    printf("\n(*) means that measurement corresponds to "
           "an average time over K(1000 in this case) "
           "executions of the algorithm\n");
    return 0;
}

