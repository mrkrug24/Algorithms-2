## Report on task №1
### **"Sorting methods"** 

# <a name="_page2_x78.00_y75.98"></a>**Problem statement**
In the process of work , the following tasks were performed: 

- Implementation in a programming language With two functions that solve the problem of ordering an array of elements of type long long int by non-growth of modules.  One function is based on the simple selection method, the other is based on the Shell method. 
- Implementation of array generation functions for sorting, creating an array in which: 
- elements are already ordered by non-growth of modules (direct order) 
- elements are ordered by non-decreasing modules (reverse order) 
- the arrangement of elements is random 
- Experimental comparison of two sorting methods: comparison of the number of moves and comparisons of array elements with different sorts. 
- Carrying out a theoretical assessment of each of the methods. 
- Analysis of errors made during operation. 
# <a name="_page3_x78.00_y75.98"></a>**Experimental results** 
# **Simple selection method**
# : ,
# .                                            
# `              `,              .            .
- Number of element comparisons ([1] 16-17) 

A remarkable property of this method is to shorten the list from view to view. At each subsequent scan, one less comparison is performed, so that (n - 1), (n - 2), (n - 3), ..., 2, 1 comparisons are performed sequentially.  The total number of comparisons is equal to the product of the average number of comparisons per view by the number 

views, i.e. ( -1) and is completely independent of the state of the data.   ![](Aspose.Words.79ab8fb6-423a-4f62-9aad-99dea8c46ca8.001.png)

2

- Hence the complexity of the algorithm – (2) 
- The number of permutations of elements: 
- The best case (the array is initially ordered) is 0, since all the elements are in the right order 
- Worst case (the array is initially ordered in reverse order) – , since each pair of elements is in the wrong order 

2

in order, and when exchanged for the right places, both elements will get up 

- The average value is (ln( ) + ), where ≈ 0.58 is the Euler constant ([1] 100-101) 



<table><tr><th colspan="1" rowspan="2" valign="top"><b>n</b></th><th colspan="1" rowspan="2" valign="top"><b>Parameter</b></th><th colspan="4" valign="top"><b>The number of the generated array</b> </th><th colspan="1" rowspan="1" valign="top"><b>Average value</b> </th></tr>
<tr><td colspan="1" valign="top">1</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">4</td></tr>
<tr><td colspan="1" rowspan="2" valign="top">10 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">45 </td><td colspan="1">45 </td><td colspan="1">45 </td><td colspan="1">45 </td><td colspan="1">45.00 </td></tr>
<tr><td colspan="1" valign="top">Moves</td><td colspan="1">0 </td><td colspan="1">5 </td><td colspan="1">8 </td><td colspan="1">7 </td><td colspan="1">4.33 </td></tr>
<tr><td colspan="1" rowspan="2" valign="top">100 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">4950 </td><td colspan="1">4950 </td><td colspan="1">4950 </td><td colspan="1">4950 </td><td colspan="1">4950,00 </td></tr>
<tr><td colspan="1" valign="top">Movements</td><td colspan="1">0 </td><td colspan="1">50 </td><td colspan="1">95 </td><td colspan="1">93 </td><td colspan="1">48.33 </td></tr>
<tr><td colspan="1" rowspan="2" valign="top">1000 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">499500 </td><td colspan="1">499500 </td><td colspan="1">499500 </td><td colspan="1">499500 </td><td colspan="1">499500.00 </td></tr>
<tr><td colspan="1" valign="top">Movements</td><td colspan="1">0 </td><td colspan="1">500 </td><td colspan="1">992 </td><td colspan="1">993 </td><td colspan="1">497.33 </td></tr>
<tr><td colspan="1" rowspan="2" valign="top">10000 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">49995000 </td><td colspan="1">49995000 </td><td colspan="1">49995000 </td><td colspan="1">49995000 </td><td colspan="1">49995000,00</td></tr>
<tr><td colspan="1" valign="top">Movements</td><td colspan="1">0 </td><td colspan="1">5000 </td><td colspan="1">9992 </td><td colspan="1">9988 </td><td colspan="1">4997.33 </td></tr>
</table>

Table 1: Results of simple selection sorting 
# **Shell Method**   
` `The implementation of simple choice sorting in the conditions of this problem is as follows: let k be an integer from 1 to n/2.  The subsequences of elements separated by k positions are ordered independently of each other: Xi, Xi + k, Xi + 2k, Xi + 3k, ... (i = 1, 2, ..., k) Then k decreases and the process repeats again. The last step must be performed at k = 1. The value of k can be changed in different ways, one of them is as follows: first k is equal to (the integer part of) n/2, and then k is halved each time. 

- Algorithm complexity (number of element comparisons) ([2] 108-110) 
- Best case – ( 2 ) 
- The worst case is (2), since the number of elements in the subsequence Xi depends linearly on n. And in turn k 

takes values from ![](Aspose.Words.79ab8fb6-423a-4f62-9aad-99dea8c46ca8.002.png) up to 1, which means the number of considered 

2

the subsequences also depend on n. Therefore, the worst complexity is (2).
#1\.5+2 = 1
- Average value – , where ![](Aspose.Words.79ab8fb6-423a-4f62-9aad-99dea8c46ca8.003.png)![](Aspose.Words.79ab8fb6-423a-4f62-9aad-99dea8c46ca8.004.png)
# 2 −1
- The number of element movements ([2] 105-108) 
- The best case (the array is initially ordered) is 0  
- The worst case is 1 2 8![](Aspose.Words.79ab8fb6-423a-4f62-9aad-99dea8c46ca8.005.png)
- Mean value – ( ,ℎ), where h is an ordered permutation, 

=![](Aspose.Words.79ab8fb6-423a-4f62-9aad-99dea8c46ca8.006.png) and = ℎ 

ℎ

22−1 ! ! ℎ ℎ −

( ,ℎ) = ( ( + 1) + ( + 1) − 1/2 ) 

(2 + 1)! 2 2 2



<table><tr><th colspan="1" rowspan="2" valign="top"><b>n</b></th><th colspan="1" rowspan="2" valign="top"><b>Parameter</b></th><th colspan="4" valign="top"><b>The number of the generated array</b> </th><th colspan="1" rowspan="1" valign="top"><b>Average value</b> </th></tr>
<tr><td colspan="1" valign="top">1</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">4</td></tr>
<tr><td colspan="1" rowspan="2" valign="top">10 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">22 </td><td colspan="1">27 </td><td colspan="1">29 </td><td colspan="1">25 </td><td colspan="1">26.00 </td></tr>
<tr><td colspan="1" valign="top">Moves</td><td colspan="1">0 </td><td colspan="1">13 </td><td colspan="1">12 </td><td colspan="1">7 </td><td colspan="1">8,33 </td></tr>
<tr><td colspan="1" rowspan="2" valign="top">100 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">503 </td><td colspan="1">668 </td><td colspan="1">912 </td><td colspan="1">917 </td><td colspan="1">694.33 </td></tr>
<tr><td colspan="1" valign="top">Movements</td><td colspan="1">0 </td><td colspan="1">260 </td><td colspan="1">457 </td><td colspan="1">467 </td><td colspan="1">239.00 </td></tr>
<tr><td colspan="1" rowspan="2" valign="top">1000 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">8006 </td><td colspan="1">11716 </td><td colspan="1">15086 </td><td colspan="1">15092 </td><td colspan="1">11602.67 </td></tr>
<tr><td colspan="1" valign="top">Moves</td><td colspan="1">0 </td><td colspan="1">4700 </td><td colspan="1">7582 </td><td colspan="1">7609 </td><td colspan="1">4094.00 </td></tr>
<tr><td colspan="1" rowspan="2" valign="top">10000 </td><td colspan="1" valign="top">Comparisons</td><td colspan="1">120005 </td><td colspan="1">172578 </td><td colspan="1">276437 </td><td colspan="1">259365 </td><td colspan="1">189673.33 </td></tr>
<tr><td colspan="1" valign="top">Movements</td><td colspan="1">0 </td><td colspan="1">62560 </td><td colspan="1">161425 </td><td colspan="1">144450 </td><td colspan="1">74661.67 </td></tr>
</table>


Table 2: Results of Shell sorting 

**Output**  

` `The experiment showed that the complexity of sorting by the Shell method is less than the complexity of sorting by the simple selection method, the values match only in the worst case for sorting by the Shell method.  As for the number of element movements, everything is not so clear, but the average value is still less for sorting by simple selection. But despite this, sorting by the Shell method is more efficient. 
# <a name="_page6_x78.00_y75.98"></a>**Program structure and function specification**
**Global variables** 

- **static int cnt\_selection\_sort\_cmp** – the number of comparisons of elements when sorting by the simple selection method 
- **static int cnt\_selection\_sort\_swap** – the number of moves of elements when sorting by the simple selection method 
- **static int cnt\_shell\_sort\_cmp** – the number of comparisons of elements when sorting by the Shell method 
- **static int cnt\_shell\_sort\_swap** – number of element moves 

when sorting by the Shell method 

**Functions**   

- **void swap(long long \*a, long long \*b)** is a function that implements the exchange of values of two variables. Accepts two pointers to the numbers a and b as input, has no return value. 
- **void  selection\_sort(long  long  \*arr,  int  n)** is a function that implements sorting by simple selection by non–growth of modules. Accepts as input a pointer to the beginning of the sorted array arr and the number of elements of this array n, has no return value. 
- **void shell\_sort(long long\* arr, int n)** is a function that implements sorting by the Shell method by non–growing modules. Accepts as input a pointer to the beginning of the sorted array arr and the number of elements of this array n, has no return value. 
- **int straight\_ordered\_compare(const void\* a, const void\* b)** is a function that implements a comparison by non–expansion of modules (in direct order) for the qsort sorting function from the standard C library. It is necessary to generate an array whose elements are ordered according to the condition of the problem.  The function takes two pointers to the numbers a and b as input. Returns:  
- value 1 if the modulus of number a is less than the modulus of number b 
- the value is 0 if the modules of numbers a and b are equal 
- value -1 if the modulus of number a is greater than the modulus of number b 
- **int reverse\_ordered\_compare(const void\* a, const void\* b)** is a function that implements a non–decreasing comparison of modules (in reverse order) for the qsort sorting function from the C standard library. It is necessary to generate an array whose elements are ordered in reverse order according to the condition of the problem. The function takes two inputs 

a pointer to the numbers a and b. Returns:  

- the value is 1 if the module of number a is greater than the module of number b 
- the value is 0 if the modules of numbers a and b are equal 
- value -1 if the module of number a is less than the module of number b 
- **void straight\_ordered\_array\_generating(long long\* arr, int n)** is a function that generates an array whose elements are ordered by non–growing modules (in direct order). Accepts as input a pointer to the beginning of the generated array arr and the number of elements of this array n, has no return value. 
- **void reverse\_ordered\_array\_generating(long long\* arr, int n)** a function that generates an array whose elements are ordered by non-decreasing modules (in reverse order). Accepts as input a pointer to the beginning of the generated array arr and the number of elements of this array n, has no return value. 
- **void random\_array\_generating(long long\* arr, int n)** is a function that generates an array whose elements are unordered.  Accepts as input a pointer to the beginning of the generated array arr and the number of elements of this array n, has no return value. 
- **void  print\_array(long  long\*  arr,  int  n)** – function for output of array values.  Takes as input a pointer to the beginning of the array arr and the number of elements of this array n, has no return value. 
- **double find\_average\_value(int\* arr, int n)** is a function for calculating the average value of array elements.  Takes as input a pointer to the beginning of the array arr and the number of elements of this array n, returns the average value of the array elements. 
- **void  free\_up\_memory\_of\_matrix(int\*\*  arr,  int  n)** – the function of freeing the memory allocated for a two-dimensional array.  Accepts as input a pointer to the beginning of the array arr and the number of rows of this array n, has no return value. 
- **void print\_header(char\* name)** – function for displaying headers of the comparison results table.  Accepts a string with the name of the sorting method as input, has no return value. 
- **void print\_footer()** – function for displaying the last row of the comparison results table.  No input data, has no return value. 

**Program structure** 

` `The program operates in two modes.  At the beginning of the work, you need to choose one of them: 

**Compare select sort and shell sort by yourself**
**
` `In this mode, the user is given the opportunity to personally compare two sorting methods and verify the correctness of the program.  The program will require you to enter the following parameters for comparison: 

- The number of elements in the generated array 
- The type of ordering of elements in the generated array: direct, reverse, random 
- Does the user want to output the generated and sorted arrays 

` `The program will allocate memory for two generated arrays (one array will be sorted by the simple selection method, and the other by the Shell method), fill them equally with elements ordered according to the user's choice. It sorts in two ways, counting the number of comparisons of the values of elements and their movements in parallel. Then, at the request of the user, it will output the generated array and two sorted in different ways.  After that, the program will display a table with the results of comparing the values of elements and their movements.  Next, the program will free up the memory allocated for the two generated arrays, after which it will successfully finish its execution. 

**View the result of a full comparison**
**
` `In this mode, the program will immediately display two tables of a gentle comparison of sorts by the simple selection method and the Shell method.** 
**
` `The program will allocate memory for two tables in which parameter values will be stored (the number of comparisons of element values and their movements during sorting), and for two arrays in which the average parameter values will be stored. Next, the program will generate arrays of different lengths and with different ordering of elements: in direct order, reverse and random, simultaneously counting the number of comparisons of the values of elements and their movements and filling tables with parameter values and arrays with average parameter values. Next, the program will output two tables of a complete comparison of sorting methods, free up the memory allocated for all arrays, and successfully finish its execution.** 
# <a name="_page9_x78.00_y75.98"></a>**Program debugging, function testing**
` `Based on the above tests, the correctness of the program was checked, errors were found when generating an array. After their elimination, repeated testing was carried out, the results of which confirmed the correctness of the program. 

**Sorting by simple selection method**



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |-2097024362 |-2085528704 |1883940024 |1520443392 |1181503488 |390061584 |
|**Output** |-2097024362 |-2085528704 |1883940024 |1520443392 |1181503488 |390061584 |

Table 3: Test #1 (elements are ordered in the generated array)



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |-175792224 |929069568 |-950310848 |-1347756824 |1395662520 |1821413120 |
|**Output** |1821413120 |1395662520 |-1347756824 |-950310848 |929069568 |-175792224 |

Table 4: Test #2 (in the generated array, the elements are ordered in reverse order)



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |-445552768 |1622093152 |-435601372 |-1149299620 |2101800184 |1737483712 |
|**Output** |2101800184 |1737483712 |1622093152 |-1149299620 |-445552768 |-435601372 |

Table 5: Test #3 (elements are unordered in the generated array)



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |-611220664 |-1681091076 |36596640 |250786816 |1024169308 |1165672110 |
|**Conclusion** |-1681091076 |1165672110 |1024169308 |-611220664 |250786816 |36596640 |

Table 6: Test #4 (elements are unordered in the generated array)


**Shell sorting** 



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |1984261440 |-1895874040 |1804025546 |-924202539 |557662617 |486915336 |
|**Output** |1984261440 |-1895874040 |1804025546 |-924202539 |557662617 |486915336 |

Table 7: Test #1 (elements are ordered in the generated array)



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |22420120 |161165952 |-821832184 |-921450688 |-1136101488 |1804312340 |
|**Output** |1804312340 |-1136101488 |-921450688 |-821832184 |161165952 |22420120 |

Table 8: Test #2 (in the generated array, the elements are ordered in reverse order)



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |745733056 |554581652 |-1382680832 |255998898 |762489440 |-576903020 |
|**Output** |-1382680832 |762489440 |745733056 |-576903020 |554581652 |255998898 |

Table 9: Test #3 (elements are unordered in the generated array)



||**arr[0]** |**arr[1]** |**arr[2]** |**arr[3]** |**arr[4]** |**arr[5]** |
| :- | - | - | - | - | - | - |
|**Input** |-1010899310 |-2064547984 |314161792 |81696724 |-895362968 |1726387200 |
|**Output** |-2064547984 |1726387200 |-1010899310 |-895362968 |314161792 |81696724 |

Table 10: Test #4 (elements are unordered in the generated array)
# <a name="_page11_x78.00_y75.98"></a>**Analysis of mistakes made**
In the process of work, errors were made that are related only to the generation of arrays and the output of tables with the results of comparison of sorts.  There were no errors in the implementation of other functions.  In the course of the work, some algorithms related to parallel filling of tables were optimized.
# **List of literature** 
1. Lorin G. Sorting and sorting systems. — M.: Nauka, 1983.
1. Knut D. The Art of computer programming. Vol.3. — Moscow: Mir, 1978.
12
