# Map Coloring Constraint Solver

## 📌 Project Overview

The **Map Coloring Constraint Solver** is a menu-driven console application developed in **C** to solve the **Graph Coloring Problem** using the **Backtracking Algorithm**.

The objective is to assign colors to all vertices of an undirected graph such that **no two adjacent vertices have the same color**, using a maximum of `M` available colors.

The project demonstrates the use of:

- Graph representation using an adjacency matrix
- Constraint checking
- Recursion
- Backtracking
- Graph coloring
- Algorithm performance tracking

---

## 🎯 Problem Statement

Given an undirected graph with `V` vertices and a maximum of `M` colors, assign a color to every vertex such that:

> No two adjacent vertices should have the same color.

If a valid assignment is possible using at most `M` colors, the program displays the color assigned to each vertex.

If no valid assignment exists, the program reports that the graph is **not colorable with the given number of colors**.

---

## 🧠 Algorithm Used

### Backtracking

The program uses a recursive backtracking approach.

For every vertex:

1. Try a color from `1` to `M`.
2. Check whether assigning that color is safe.
3. If the color is safe, assign it to the vertex.
4. Recursively move to the next vertex.
5. If no valid solution is found, remove the assigned color and **backtrack**.
6. Try another color.
7. Continue until all vertices are successfully colored or all possibilities are exhausted.

### Basic Flow

```text
Start
  |
  v
Select a vertex
  |
  v
Try Color 1 to M
  |
  v
Is the color safe?
  |
  +------ No ------> Try next color
  |
 Yes
  |
  v
Assign color
  |
  v
Color next vertex
  |
  +------ Solution found ------> Display solution
  |
  +------ No solution ----------> Backtrack
```

---

## 🏗️ Project Structure

The program is divided into **three major sections**.

### 1. Graph Management

This section handles:

- Graph initialization
- Number of vertices
- Number of edges
- Edge input
- Adjacency matrix
- Graph display

Main functions:

```c
initializeGraph()
enterGraph()
displayGraph()
```

---

### 2. Backtracking Algorithm

This is the core part of the project.

It handles:

- Checking whether a color can be assigned
- Trying different colors
- Recursive traversal
- Backtracking when a choice fails

Main functions:

```c
isSafe()
graphColoring()
resetSolution()
enterColors()
```

---

### 3. Output and Menu Control

This section handles:

- Displaying the final color assignment
- Reporting whether the graph is colorable
- Displaying algorithm statistics
- Providing the menu-driven interface

Main functions:

```c
displaySolution()
displayStatistics()
solveMapColoring()
main()
```

---

## 💻 Features

- ✅ Menu-driven console interface
- ✅ Undirected graph representation
- ✅ Adjacency matrix implementation
- ✅ User-defined number of vertices and edges
- ✅ User-defined number of colors
- ✅ Recursive backtracking
- ✅ Safe-color checking
- ✅ Valid color assignment
- ✅ Detection of insufficient colors
- ✅ Number of color trials
- ✅ Number of backtracks
- ✅ Supports different types of graphs

---

## 📥 Input

The program allows the user to enter:

1. Number of vertices
2. Number of edges
3. Source and destination of every edge
4. Maximum number of colors `M`

Vertices are numbered from:

```text
1 to V
```

---

## 📤 Output

If a valid coloring exists, the program displays:

```text
========================================
          COLOR ASSIGNMENT
========================================

Vertex  Colour
----------------
V1      C1
V2      C2
V3      C1
V4      C3

Colouring is VALID.
No adjacent vertices have the same colour.
```

The program also displays:

```text
========================================
        BACKTRACKING STATISTICS
========================================

Number of vertices : 4
Number of edges    : 4
Colours available  : 3
Colour trials      : 7
Backtracks         : 1
```

If the graph cannot be colored:

```text
========================================
             NO SOLUTION
========================================

The graph cannot be coloured using 2 colour(s).

Therefore, 2 colours are NOT sufficient.
```

---

## 📋 Menu

The program provides the following menu:

```text
========================================
       MAP COLORING CONSTRAINT SOLVER
========================================

1. Enter Graph
2. Display Graph
3. Solve Map Coloring
4. Display Solution
5. Display Statistics
6. Exit
```

### Option 1 — Enter Graph

Creates the graph by accepting vertices and edges from the user.

### Option 2 — Display Graph

Displays the graph in the form of an adjacency matrix.

### Option 3 — Solve Map Coloring

Accepts the maximum number of colors and applies the backtracking algorithm.

### Option 4 — Display Solution

Displays the color assigned to every vertex.

### Option 5 — Display Statistics

Displays:

- Number of vertices
- Number of edges
- Number of available colors
- Number of color trials
- Number of backtracks

### Option 6 — Exit

Terminates the program.

---

## 🧪 Test Cases

The program can be tested using different types of graphs.

### 1. Path Graph

```text
1 ----- 2 ----- 3 ----- 4
```

A path graph can be colored using two colors.

---

### 2. Cycle Graph

```text
      1
     / \
    2   4
     \ /
      3
```

The program checks whether the given number of colors is sufficient.

---

### 3. Complete Graph

Example:

```text
1 ----- 2
|\     /|
| \   / |
|  \ /  |
|   X   |
|  / \  |
| /   \ |
|/     \|
3 ----- 4
```

A complete graph with `n` vertices requires `n` different colors.

---

### 4. Disconnected Graph

A graph containing multiple independent components can also be tested.

Example:

```text
1 ----- 2       4 ----- 5
```

---

### 5. Insufficient Colors

Provide fewer colors than required by the graph.

For example, a triangle:

```text
    1
   / \
  2---3
```

With only `2` colors:

```text
M = 2
```

the graph cannot be colored successfully.

---

## ⏱️ Complexity

For a graph with `V` vertices and `M` available colors, the worst-case time complexity of the backtracking approach is approximately:

```text
O(M^V)
```

The adjacency matrix requires:

```text
O(V²)
```

space.

The backtracking solution may explore many possible color assignments in the worst case.

---

## 🛠️ Technologies Used

| Technology | Purpose |
|---|---|
| C | Programming language |
| Backtracking | Main algorithm |
| Recursion | Exploring color assignments |
| Adjacency Matrix | Graph representation |
| GCC / Code::Blocks / VS Code | Compilation and execution |

---

## 📁 Suggested Project Structure

```text
Map-Coloring-Constraint-Solver/
│
├── map_coloring.c
├── README.md
└── screenshots/
    ├── menu.png
    ├── graph.png
    ├── solution.png
    └── statistics.png
```

---

## 🎓 Learning Outcomes

After completing this project, the following concepts are demonstrated:

- Understanding graph representation
- Implementing adjacency matrices
- Understanding graph coloring
- Applying constraint checking
- Implementing recursion
- Understanding backtracking
- Handling unsuccessful choices
- Measuring algorithm performance
- Designing a menu-driven C application

---

## 👥 Project Type

**Subject:** Analysis and Design of Algorithms (AOA)

**Project:** Mini Project

**Problem:** Map Coloring Constraint Solver

**Algorithm:** Backtracking

**Language:** C

**Interface:** Console / Menu-driven

**Database:** Not Required

**GUI:** Not Required

---

## 📌 Conclusion

The **Map Coloring Constraint Solver** demonstrates how the **Backtracking technique** can be used to solve a constraint satisfaction problem.

The algorithm systematically tries possible color assignments and abandons invalid choices whenever a constraint is violated. This makes the project a practical demonstration of **recursion, constraint checking, and backtracking in graph problems**.