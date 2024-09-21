# Dijkstra-s-Algorithm-assignment-4
This below explanation is one of the test cases 
This shows that the shortest path from node 0 to node 3 goes through node 4, with a total cost of 5.

## Explanation

The path 0 -> 4 -> 3 is the shortest because:
1. The edge from 0 to 4 has a weight of 3
2. The edge from 4 to 3 has a weight of 2
3. The total cost is 3 + 2 = 5

This is shorter than other possible paths, such as:
- 0 -> 1 -> 2 -> 3 (cost: 10 + 2 + 9 = 21)
- 0 -> 1 -> 4 -> 3 (cost: 10 + 4 + 2 = 16)
