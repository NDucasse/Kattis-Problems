#Problem
A 2d grid map of m rows and n columns is initially filled with water. We may perform an `addLand` operation which turns the water at position `[row, col]` into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:
```
Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
```

Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

```
0 0 0
0 0 0
0 0 0
```

Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

```
1 0 0
0 0 0   Number of islands = 1
0 0 0
```

Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

```
1 1 0
0 0 0   Number of islands = 1
0 0 0
```

Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

```
1 1 0
0 0 1   Number of islands = 2
0 0 0
```

Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

```
1 1 0
0 0 1   Number of islands = 3
0 1 0
```

Follow up:

```
Can you do it in time complexity O(k log mn), where k is the length of the positions?
```


#Solution
I solved this using a data structure called a Disjoint Set, or Disjoint Tree. The main idea is that each "node"
(in this case, '1's which represent land) is in its own set, and anytime a new land is placed next to an existing land,
a union operation occurs between the new node and any existing nodes, joining them to the same set with the same root node.
In this, I count the number of "meaningful" union operations (i.e. unions between two land values not already in the same set)
as well as the number of "meaningful" land placement operations (i.e. sometimes land is placed where land already exists, ignore those),
and subtract the two after each operation to get the total number of seperate landmasses.

###Runtime complexity:
This solution runs in `O(log(MxN))` time, where `MxN` are the dimensions of the starting array.

###Spacial complexity:
This solution takes up `O(MxN)` memory, from the original grid as well as the disjoint set array. 
