# [hw7 - AOE Network](https://github.com/st9540808/Data-Structures/tree/master/Homeworks/hw7%20AOE-Network)

the program read input graph from file `Sample_input.txt`. <br>
By calling method topologicalSort(), it calculate 

- early time
- latest time
- slack

and print out in a readable formate 
<br>


## Compilation
```
g++ hw7.cpp -o main -std=gnu++14
```
> forget to add ```-std=gnu++14``` flag will result in compilation error

> this is for the final hand-in version on moodle
<br>


## Output Example
```
   earlyTime|   lateTime|   slack|   critical|
a1         0|          0|       0|        Yes|
a2         0|          2|       2|         No|
a3         0|          3|       3|         No|
a4         6|          6|       0|        Yes|
a5         4|          6|       2|         No|
a6         5|          8|       3|         No|
a7         7|          7|       0|        Yes|
a8         7|          7|       0|        Yes|
a9         7|         10|       3|         No|
a10       16|         16|       0|        Yes|
a11       14|         14|       0|        Yes|
```
if input graph is DAG, print out :
```
input Graph in not a DAG (directed acyclic graph)
program terminated.
```
<br>


## Class UML
```cpp
class Graph

- addNode(i : int, j : int, duration : int)
- adjList   : vector<ListNode *>
- inDegree  : vector<int>
- earlyTime : vector<int>
- lateTime  : vector<int>

<<constructor>> + Graph()
<<destructor>> + ~Graph()
+ topologicalSort() : vector<int>
+ input(&inputGraph : ifstream)
+ print()
```
