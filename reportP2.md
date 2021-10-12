Algorithms - Practical 2

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Authors:

David García Ramallal (david.ramallal@udc.es)
Alfredo Javier Freire Bouzas (javier.freire.bouzas@udc.es)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Introduction:

In this practical we are working with two kinds of sorting algorithms :
	-Selection Sort
	-Shell Sort
Our goal is to make them work with three different initializations : 
	-A random one
	-An ascending one
	-A descending one
In addition, we have to study empirically the complexity of the algorithms,
at the same time that we search for the tight, the underestimated and the 
overestimated bounds and the constant (in the case of the tight bound).

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Information of the machine where the program was compiled and executed:

Computer	: Acer Nitro AN515-55 V2.06
Model name	: Intel(R) Core(TM) i7-10750H CPU @ 2.60GHz
Kernel		: Linux 5.11.0-34-generic
Operating Sys	: Ubuntu 20.04.3 LTS
VGA compatible controller: Intel Corporation UHD Graphics (rev 05)
VGA compatible controller: NVIDIA Corporation Device 1f99 (rev a1)
MemTotal	: 16220036 kB
SwapTotal	: 2097148 kB

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time unit: microseconds

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Selection sort with random initialization
    n              t(n)          t(n)/n^1.8          t(n)/n^2            t(n)/n^2.2
  500           400.489            0.007042          0.002004              0.000460
 1000          1282.000            0.005116          0.001424              0.000391
 2000          6630.000            0.006481          0.001744              0.000286
 4000         21418.000            0.007342          0.001557              0.000309
 8000        104024.000            0.009039          0.001535              0.000237
16000        386646.000            0.010077          0.001510              0.000210
32000       1239461.000            0.009544          0.001355              0.000186

Selection sort with ascending initialization
    n              t(n)          t(n)/n^1.8          t(n)/n^2            t(n)/n^2.2
  500           304.363            0.004198          0.001214              0.000352   (*)
 1000          1112.000            0.004590          0.001113              0.000292
 2000          4810.000            0.005384          0.001161              0.000260
 4000         18954.000            0.006700          0.001227              0.000249
 8000         76563.000            0.007274          0.001176              0.000197
16000        375151.000            0.009319          0.001189              0.000173
32000       1221532.000            0.009487          0.001214              0.000164

Selection sort with descending initialization
    n              t(n)          t(n)/n^1.8          t(n)/n^2            t(n)/n^2.2
  500           323.598            0.004461          0.001289              0.000373   (*)
 1000          1256.000            0.005096          0.001189              0.000298
 2000          5140.000            0.005616          0.001342              0.000273
 4000         20361.000            0.006927          0.001238              0.000255
 8000         81253.000            0.007630          0.001266              0.000210
16000        320632.000            0.008709          0.001258              0.000182
32000       1299468.000            0.010117          0.001261              0.000159

Shell sort with random initialization
    n              t(n)              t(n)/n    t(n)/n*(log n)            t(n)/n^1.5
  500            53.377            0.105234          0.017228              0.000010   (*)
 1000           126.635            0.123861          0.018152              0.000004   (*)
 2000           289.078            0.144453          0.019114              0.000002   (*)
 4000           614.000            0.153250          0.020677              0.000001
 8000          1487.000            0.175500          0.020710              0.000000
16000          4674.000            0.295438          0.021616              0.000000
32000          7858.000            0.286031          0.028790              0.000000

Shell sort with ascending initialization
    n              t(n)              t(n)/n    t(n)/n*(log n)            t(n)/n^1.5
  500            15.294            0.028958          0.004628              0.000003   (*)
 1000            32.288            0.035452          0.004758              0.000001   (*)
 2000            81.398            0.039146          0.005032              0.000000   (*)
 4000           172.493            0.043276          0.005310              0.000000   (*)
 8000           486.781            0.060690          0.006996              0.000000
16000          1292.000            0.060187          0.005520              0.000000
32000          2524.000            0.093219          0.005657              0.000000

Shell sort with descending initialization
    n              t(n)              t(n)/n    t(n)/n*(log n)            t(n)/n^1.5
  500            24.401            0.054548          0.009140              0.000006   (*)
 1000            60.047            0.055969          0.008662              0.000002   (*)
 2000           129.379            0.068801          0.008769              0.000001   (*)
 4000           244.467            0.061104          0.007300              0.000000   (*)
 8000           576.000            0.072500          0.007443              0.000000
16000          1114.000            0.084062          0.008122              0.000000
32000          2384.000            0.089906          0.009152              0.000000

(*) means that measurement corresponds to an average time over K(1000 in this case) executions of the algorithm

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bounds and constants information

-Selection Sort: 
t(n)/n^1.8 is an understimated bound, which tends to infinity.
t(n)/n^2 is a tight bound, with constant values:
	random initialization's constant = 0.001589
	ascending initialization's constant = 0.001185
	descending initialization's constant = 0.001263
t(n)/n^2.2 is an overstimated bound, which tends to zero.

-Shell Sort:
t(n)/n is an understimated bound, which tends to infinity.
t(n)/n*(log n) is a tight bound, with constant values:
	random initialization's constant = 0.020898
	ascending initialization's constant = 0.005414
	descending initialization's constant = 0.008369
t(n)/n^1.5 is an overstimated bound, which tends to zero.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Conclusion: 

After studying both algorithms, we would say that there are measurable differences between them.
The most evident one is that the Shell Short algorithm does the procesure so much faster than
the Selection Sort. This can be seen with n = 32000. While Selection Sort lasts around one million
microseconds, Shell Sort does not surpass eight thousand microseconds.
In the other hand, if we analize the values obtained with the tight bound, we would reach to the
conclusion that Selection Sort has more stability (the values are more similar between them, which
means that the error is smaller).
In our opinion, it is more efficient the Shell Sort algorithm, which is constatable from the
measures and the results of the compilation.
