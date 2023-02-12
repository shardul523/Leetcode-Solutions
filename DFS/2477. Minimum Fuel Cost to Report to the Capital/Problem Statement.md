## 2477. Minimum Fuel Cost to Report to the Capital

# Problem Statement

There is a tree (i.e., a connected, undirected graph with no cycles) structure country network consisting of n cities numbered from 0 to n - 1 and exactly n - 1 roads. The capital city is city 0. You are given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a **bidirectional road** connecting cities ai and bi.

There is a meeting for the representatives of each city. The meeting is in the capital city.

There is a car in each city. You are given an integer seats that indicates the number of seats in each car.

A representative can use the car in their city to travel or change the car and ride with another representative. The cost of traveling between two cities is one liter of fuel.

*Return the minimum number of liters of fuel to reach the capital city.*

---

**Example 1**

**Input:** roads = [[0,1],[0,2],[0,3]], seats = 5

**Output:** 3

**Explanation:**
- Representative1 goes directly to the capital with 1 liter of fuel.
- Representative2 goes directly to the capital with 1 liter of fuel.
- Representative3 goes directly to the capital with 1 liter of fuel.
- It costs 3 liters of fuel at minimum. 
  
It can be proven that 3 is the minimum number of liters of fuel needed.

---

**Constraints:**

- 1 <= n <= 105
- roads.length == n - 1
- roads[i].length == 2
- 0 <= ai, bi < n
- ai != bi
- roads represents a valid tree.
- 1 <= seats <= 105

---