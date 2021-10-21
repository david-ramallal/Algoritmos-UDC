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
    n              t(n)            t(n)/n^1.8            t(n)/n^2              t(n)/n^2.2
  500           302.430            0.00426244          0.00264000              0.00159389
 1000          1155.000            0.00460212          0.00115700              0.00029037
 2000          4636.000            0.00580320          0.00114625              0.00026410
 4000         17967.000            0.00591691          0.00112513              0.00022463
 8000         71361.000            0.00672773          0.00111372              0.00018431
16000        273823.000            0.00740070          0.00109271              0.00015843
32000        996540.000            0.00772414          0.00097235              0.00012198

Selection sort with ascending initialization
    n              t(n)            t(n)/n^1.8            t(n)/n^2              t(n)/n^2.2
  500           247.035            0.00355165          0.00098468              0.00028987   (*)
 1000           956.000            0.00416420          0.00095500              0.00023989
 2000          3942.000            0.00495490          0.00095075              0.00023125
 4000         15296.000            0.00533907          0.00097306              0.00018952
 8000         61281.000            0.00588162          0.00096445              0.00016247
16000        247071.000            0.00673945          0.00097216              0.00014065
32000        990445.000            0.00773591          0.00097681              0.00012144

Selection sort with descending initialization
    n              t(n)            t(n)/n^1.8            t(n)/n^2              t(n)/n^2.2
  500           265.506            0.00368121          0.00105382              0.00030312   (*)
 1000          1018.000            0.00442695          0.00108100              0.00026224
 2000          4372.000            0.00585236          0.00102225              0.00024819
 4000         16748.000            0.00551998          0.00109687              0.00021655
 8000         65373.000            0.00619418          0.00105900              0.00017068
16000        268388.000            0.00724052          0.00104752              0.00014940
32000       1075095.000            0.00835072          0.00104113              0.00013003

Shell sort with random initialization
    n              t(n)                t(n)/n      t(n)/n*(log n)             t(n)/n^1.01
  500            47.151            0.08872000          0.01427701              0.00017070   (*)
 1000           102.910            0.10129300          0.01508131              0.00009533   (*)
 2000           233.216            0.11804950          0.01543613              0.00005541   (*)
 4000           516.000            0.12950000          0.01555332              0.00002963
 8000          1187.000            0.14875000          0.01653741              0.00001870
16000          2714.000            0.21712500          0.01900759              0.00000994
32000          6460.000            0.19903125          0.01888829              0.00000657

Shell sort with ascending initialization
    n              t(n)                t(n)/n      t(n)/n*(log n)             t(n)/n^1.01
  500            12.448            0.02490200          0.00408811              0.00004940   (*)
 1000            28.737            0.02784400          0.00410568              0.00003229   (*)
 2000            62.604            0.03121800          0.00419299              0.00001458   (*)
 4000           142.235            0.03518525          0.00424386              0.00000813   (*)
 8000           306.861            0.03868062          0.00432355              0.00000438   (*)
16000           663.000            0.04675000          0.00428058              0.00000265
32000          1471.000            0.04490625          0.00432593              0.00000126

Shell sort with descending initialization
    n              t(n)                t(n)/n      t(n)/n*(log n)             t(n)/n^1.01
  500            17.657            0.03532400          0.00582145              0.00007071   (*)
 1000            41.230            0.04191800          0.00588353              0.00003742   (*)
 2000            89.620            0.04491800          0.00592844              0.00002077   (*)
 4000           198.504            0.04983925          0.00594037              0.00001147   (*)
 8000           435.306            0.05445225          0.00603426              0.00000617   (*)
16000           930.000            0.05812500          0.00599798              0.00000330
32000          2686.000            0.09156250          0.00612438              0.00000177

(*) means that measurement corresponds to an average time over K(1000 in this case) executions of the algorithm

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bounds and constants information

-Selection Sort: 
t(n)/n^1.8 is an understimated bound, which tends to infinity.
t(n)/n^2 is a tight bound, with constant values:
	random initialization's constant = 0.00132102
	ascending initialization's constant = 0.00096813
	descending initialization's constant = 0.00105737
t(n)/n^2.2 is an overstimated bound, which tends to zero.

-Shell Sort:
t(n)/n is an understimated bound, which tends to infinity.
t(n)/n*(log n) is a tight bound, with constant values:
	random initialization's constant = 0.01639729
	ascending initialization's constant = 0.00422296
	descending initialization's constant = 0.00596144
t(n)/n^1.01 is an overstimated bound, which tends to zero.

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

