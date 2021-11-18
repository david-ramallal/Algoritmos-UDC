Algorithms - Practical 1

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Authors:

David García Ramallal (david.ramallal@udc.es)
Alfredo Javier Freire Bouzas (javier.freire.bouzas@udc.es)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Introduction:

Maximum Subsequence Sum: We are going to test two different algorithms, which solve the same problem. The first algorithm with complexity O(n²) and the second one with complexity O(n).

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

MaxSubSum 1
    n              t(n)          t(n)/n^1.8          t(n)/n^2            t(n)/n^2.2
  500           275.171            0.003813          0.001100              0.000317   (*)
 1000          1094.000            0.004331          0.001099              0.000273
 2000          4399.000            0.004983          0.001087              0.000238
 4000         17315.000            0.005707          0.001083              0.000207
 8000         69352.000            0.006536          0.001083              0.000179
16000        277945.000            0.007528          0.001107              0.000160
32000       1145864.000            0.008978          0.001135              0.000139

MaxSubSum 2
    n              t(n)          t(n)/n^0.8            t(n)/n            t(n)/n^1.2
  500             1.785            0.013246          0.003960              0.001122   (*)
 1000             3.056            0.012083          0.003369              0.000786   (*)
 2000             5.517            0.014545          0.002805              0.000616   (*)
 4000             9.701            0.013814          0.002897              0.000543   (*)
 8000            19.911            0.014942          0.002474              0.000378   (*)
16000            37.569            0.016571          0.002405              0.000342   (*)
32000            74.541            0.018006          0.002256              0.000294   (*)

(*) means that measurement corresponds to an average time over K(1000 in this case) executions of the algorithm

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Bounds and constants information

t(n)/n^1.8 and t(n)/n^0.8 are understimated bounds, which tend to infinity.
t(n)/n^2 and t(n)/n are tight bounds, with constant values:
	C1 = 0.001099
	C2 = 0.002880
t(n)/n^2.2 and t(n)/n^1.2 are overstimated bounds, which tend to zero.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Conclusion: 

As a conclusion, the second algorithm is much faster than the first one (which can be seen clearly when n grows). However, Algorithm 1 is more constant and predictable.

