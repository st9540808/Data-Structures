#Discrete Math Proposal

Compare different sorting algorithms on linked lists

##Experiment one
We know that insertion sort has running time O(n^2) and merge sort O(nlgn) 
in average case. And we have an intituion that for n is sufficiently small
, insertion sort will be faster than merge sort. We are going to observe 
the probability that insertion sort is faster than merge sort for<br>
1. n from 1 to 50
2. n form 1 to 100

##Experiment two
There are a plenty of variation of merge sort. In particular, tim sort, 
is a combination of insertion sort and merge sort(iterative version). The 
problem is that we don't know how to determine a good run size sorted with 
insertion sort and combine with merge sort. Thus, we are going to observe 
the running time for<br>
1. run size from 2 to 50
2. run size from 2 to 100

##Experiment three
We know that all variation of merge sort has the running time O(nlgn) 
differ by a constant. For this experiment, we are going to use our 
implementation of <br>
1. recursive merge sort
2. iterative merge sort
3. natural merge sort
4. best running time of tim sort from experiment two
<br>
and plot the running time with respected to size of the list n.
