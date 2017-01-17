#[hw7 - AOE Network](https://github.com/st9540808/Data-Structures/tree/master/Homeworks/hw7%20AOE-Network)

the program read input graph from file `Sample_input.txt`.
and print out early time, lastest time, slack.

##Compilation
```g++ hw7.cpp -o main -std=gnu++14```
> this is for the final hand-in version on moodle

##Class UML
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

