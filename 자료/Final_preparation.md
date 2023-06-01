# Problem Solving
## Table of Contents
1. [C Programming](#c-programming)
2. [Basic Structure](#structures)
3. [Sorting](#sorting)
4. [Strings](#strings)
5. [Backtracking](#backtracking)
6. [Grids](#grids)
7. [Graphs](#graphs)
8. [Traversal](#traversal)
9. [Dynamic Programming](#dynamic-programming)
10. [Combinatorics](#combinatorics)
11. [Shoemaker Problem](#shoemaker-problem)
12. [Real-Time Systems](#real-time-systems)

## Problem Solving Steps
1. Understand the problem
2. Decide how to solve the problem
>    - Use a graphs
>    - Write an equation
>    - Find a pattern
>    - Use reasoning
>    - Make a table
>    - Use formulas
>    - Make a list
>    - Work backwards
>    - Draw a picture
>    - Act it out
3. Solve the problem
4. Look back & check

## Problem Solving Strategies
1. Generate & Test: Brute Force
    - Test every case
2. Hill-Climbing: Heuristic
    - Always move towards the goal state
3. Subproblems: Divide & Conquer
    - Break the problem into several subproblems
4. Working Backwards
    - Start from goal state and go towards initial state
5. Reasoning by Analogy (Pattern)
    - Find a pattern

# C Programming
## Syntax
```c
#include <header file>

int main(/*arguments*/)
{
    /*statements*/
    return 0;
}
```

## Flow of control
### If... else syntax
```c
if(/*condition*/)
{
    /*statements*/
}
else if(/*other condition*/)
{
    /*statements*/
}
else
{
    /*statements*/

}
```

### Switch syntax: multiple conditional statement
```c
switch(/*expression*/)
{
    
    case /*constant expression 1*/: /*statements*/
    case /*constant expression 2*/: /*statements*/
    default: /*statements*/break;
}
```

### Conditional operator syntax
```c
//condition ? true:false;
(x > y) ? z = x : z = y;
```

### while syntax
```c
while(/*expression*/)
{
    /*statements*/
}
```

### for syntax
```c
for(expr1; expr2; expr3)
{
    /*statement*/
}

// expr1 = initialization
// expr2 = condition for loop
// expr3 = statement after full loop execution
```

## Function
### Syntax

    return-type function_name(parameter)
    {
        declarations
        statements
        return variable of function type
    }
- Example
```c
double power_of_two(double x)
{
    double result = x * x;
    return result;
}
```

## Data type
- Integral type
    - int, short, long, unsigned
- Floating type
    - float, double, long double
- Type conversion
```c
int a = 1, b = 2;
double c = (double) a / b;
```
- enum (enumeration) type
```c
//each element from sun to sat is assigned 0, 1, ..., 6
enum day {sun, mon, tue, wed, thu, fri, sat};
```

## Pointer
- Declaration
    - data_type * variable
- & (reference) operator
    - "address of" variable

## Arrays
- data_type variable[size];
```c
int a[4] = {2, 4, 3, 0};
int b[2][3]{{1, 6, 4}, {5, 3, 2}};
int c[2][2][3] = {{{1, 2, 0}, {3, 5, 4}}, {{9, 8, 7}, {14, 15, 16}}};

// b[0][1] = 6
// c[1][1][1] = 15
// c[1][0][0] = 9
```
- Equivalent to a[i]
    - *(a + i)
    - *(&a[0] + i)
- Equivalent to a[i][j]
    - *(a[i] + j)
    - (*(a + i))[j]
    - *(( *a + i) + j)
    - *(&a[0][0] + J_SIZE * i + j)
    - etc.

- Dynamic Memory Allocation
    - stdlib.h
    - malloc(object_size): memory allocation
    - calloc(n, object_size): allocate memory for *n* blocks, each having a size of *object_size*
    - realloc(ptr, object_size): realloc *ptr* to *object_size*
    - free(ptr): free pointer memory

## Recursion
```c
int factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
```

## Structure
>difference with array functions
>>Array
>>- Elements in array of the same type
>>- each element accessible using index
>
>>Structure
>>- Elements with different types
>>- Each element has its own name
>>- access individual elements using name

- struct member operator "."
    - struct_name.variable_name
- struct pointer operator
    - struct_name->variable_name

# Structures
## Queue
- FIFO (first-in-first-out) structure
- first element, first serve

- Operations
    - Enqueue(x, Q): insert x to end of Q
    - Dequeue(Q): return and / or delete the first item of Q
    - Initialize(Q): initialize Q
    - isFull(Q), isEmpty(Q): boolean to check if Q is full or empty

- Type defintion
```c
typedef struct {
    int q[QUEUESIZE + 1]; // body of queue
    int first; // position of first element
    int last; // position of last element
    int count; // number of queue elements
}queue;
```

- Initialization, & empty / full check
```c
init_queue(queue* q)
{
    q->first = 0;
    q->last = QUEUESIZE - 1;
    q->count = 0;
}

int empty(queue *q)
{
    if(q->count <= 0) return 1;
    else return 0;
}

int full(queue *q)
{
    if(q->count >= QUEUESIZE) return 1;
    else return 0;
}
```

- Enqueue
```c
void enqueue(queue *q, int x)
{
    if(full(q)) printf("Queue is full\n");
    else
    {
        q->last = (q->last+1) % QUEUESIZE;
        q->q[q->last] = x;
    }
}
```

- Dequeue
```c
int dequeue(queue *q, int x)
{
    int x;
    if(empty(q)) printf("Queue is empty\n");
    else
    {
        x = q->q[q->first];
        q->first = (q->first + 1) % QUEUESIZE;
        q->count--;
    }

    return x;
}
```

# Sorting
## Time Complexity: big O notation
- worst case
- e.g. N^3 + 10000N^2 + N + 200
    - answer: O(N^3)

## Sorting Algorithms
- [Bubble Sort](#bubble-sort)
- [Selection Sort](#selection-sort)
- [Insertion Sort](#insertion-sort)
- Shell Sort * not studied
- [Merge Sort](#merge-sort)
- [Quick Sort](#quick-sort)
- [Bitmap Sort](#bitmap-sort)
- [Counting Sort](#counting-sort)
- [Radix Sort](#radix-sort)

## Bubble Sort
- simple sorting algorithm
- Worst Case: O(n^2)
- Average Case: O(n^2)
1. repeatedly step through list
2. compare each pair of adjacent items and swap if wrong order

## Selection Sort
- Divided into two parts
    - Already sorted list, built up from left to right
    - unsorted list
- Worst Case: O(n^2)
- Average Case: O(n^2)

1. Traverse the list of unsorted items
2. Find the smallest value
3. Place the smallest value at the left most of the unsorted list
4. This value is now considered sorted as well
5. Repeat 1 - 4 until all values are considered sorted

## Insertion Sort
- Iterates, consuming one input element each repetition
- Worst Case: O(n^2)
- Average Case: O(n^2)

1. Remove one element from input data
2. Find the location it belongs within the sorted list (located to the left of the element)
    - if current element is greater than previous element, swap
    - else, it is in the right position, insert
3. Repeat until no input elements remain

## Merge Sort
- Divides unsorted list into n sublists, each containing 1 element, and repeatedly merges sublists to produce sorted sublists
- Worst Case O(n * log n)
- Average Case O(n * log n)

1. Divide into n sublists
2. Loop the following until sorted
> 3. Take two adjacent lists
> 4. Compare two smallest values
> 5. Insert the smaller value
> 6. Repeat 4 - 5 until both lists are empty

## Quick Sort
- Divide and conquer
- Quickly separate the smaller and larger values
- Worst Case: O(n^2)
- Average Case: O(n * log n)

1. Left-most value is pivot
2. Set adjacent (right) value as a swap index
3. Iterate through list
4. Compare pivot with iterated value
    - If value is less than pivot, swap with swap index and increment swap index
    - else, continue
5. Once done iterating, swap pivot with (swap index - 1)
6. Repeat 1 - 5 until all values are sorted

## Bitmap Sort
- Uses a bitmap / bit vector to represent a finite set of distinct integers
- Advantages:
    - O(1) access time
- Limitations: 
    - Positive integers
    - One appearance per integer
    - Limited size

1. Initialize a byte array to zero
2. set each corresponding bit to 1 by reading integer in file
3. Verify each bit


- Short implementation
```c
void SetBit(int n)
{
    // 8 bits per byte
    // for n / 8th byte, set the n % 8 bit to 1
    bitmap[n / 8] |= 1 << n % 8;
}

int CheckBit (int n)
{
    return(bitmap[n / 8] >> (n % 8)) & 1;
}
```

## Counting Sort
- Use a count array and store the count for each number
- Advantages:
    - Similar to bitmap with more
    - each number can appear more than once
    - No size limitation
- Limitations:
    - Positive integers
    - Limited range
    - Not sparsely distributed set of values
- O(1)

1. On each number n, increment count at index n on the count array by one
2. Traverse count array and print out each index by count number of times

## Radix Sort
- sort the list by comparing the digits from least to greatest

1. Check next least significant digit, arrange list using this significant digit
2. Continue until there most significant digit was used

# Strings
## ASCII Code
- American Standard Code for Information Interchange
- single byte character code with 2^7 = 128 characters specified

## Properties of ASCII
- non-printable characters have first three bits zero or all seven lowest bits as 1
- upper and lowercase letters and numerical digits appear sequentially
- Converting upper -> lower vice versa can be done by adding / subtracting the difference of the upper and lowercase Character 'a' - 'A'

## Unicode
- Modern international character code

## Strings
- sequence of characters
- order clearly matters
- Null-terminated arrays: C string arrays ending the array with null character "\0"
- Array Plus Length: Use the first array location to store the length of string
    - avoids the need of null terminating character
    - used in Java
- Linked list of characters: text strings represented using linked lists

## C string library functions
- ctype.h
    - several simple test and manipulations on character codes
- string.h
    - string manipulation and tests

# Backtracking
- Systematic method to iterate through all the possible configurations of a search space

Steps:
1. Try extending a partial solution by adding another element
2. Test whether it still is a solution
    - if solution, continue
    - else, check whether partial solution is still potentially extendible to some complete solution
        - if so, recur and continue
        - else, delete last element and try from number 1 again

```c
bool finished = FALSE; /* found all solutions yet? */

//adjust is_a_solution, process_solution, and construct_candidates to the problem / application

backtrack(int a[], int k, data input)
{
    int c[MAXCANDIDATES]; /* candidates for next position */
    int ncandidates /* candidates for next position */
    int i; /* counter */

    /*
    *is_a_solution
    * checks whether the first k elements of vector a is a complete solution
    * input: pass general information
    */

   /*
   *process_solution
   * prints, counts, or processes a complete solution once constructed 
   */
    if(is_a_solution(a, k, input))
        process_solution(a, k, input);
    else
    {
        k = k + 1;
        /*
        *construct_candidates
        * fills an array c with the complete set of possible candidates for kth position of a, given the contents of the first k - 1 positions
        * ncandidates: number of candidates
        */
        construct_candidates(a, k, input, c, &ncandidates);
        for(i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            backtrack(a, k, input);
            if(finished) return; /*terminate early */
        }
    }
}
```

# Grids
- Number of squares / rectangles and cubes / boxes
- Given a value N, being the length of each dimension, find the number of squares / rectangles in a N x N two-dimensional grid
- with the same value, find the number of cubes / boxes in a N x N x N three-dimensional grid

- For squares and cubes
> Sn = Sum of (N + 1 - i) ^ n
>- n = number of dimensions
>- N = length of dimension
>- i = iterative value from 1 to N

- For rectangles and boxes
>R2 = (Sum of sum of (N + 1 - A) (N + 1 - B)) - S2 (number of squares)
>- A, B: one dimension each
>
>R3 = (Sum of Sum of Sum of (N + 1 - A)(N + 1 - B)(N + 1 - C)) - S3 (number of cubes)
>- A, B, C: one dimension each

# Graphs
Graph G = (V, E)
- V: set of vertices
- E: set of edges

## Flavors of Graphs
1. Direction
    - Undirected
        - edge (x, y) exists, then edge (y, x) exists
    - Directed
        - edge (x, y) exists, we dont know if (y, x) exists
2. Weight
    - Weighted
        - Each edge given a numerical weight
    - Unweighted
        - All weight = 1
3. Degree of vertex
    - Undirected
        - Number of edges incident / connected to it
        - degree 0 means isolated vertex
    - Directed
        - Out-degree: number of edges leaving vertex
        - In-degree: number of edges entering vertex
        - Degree = In-degree + out-degree

## Data Structure of Graphs
- G = (V, E), |V| = n and |E| = m
- Adjacenct Matrices
    - G represented using n x n matrix M
    - Each element M[i][j] =
        - 1 if (i,j) has an edge
        - 0 if not
    - advantage
        - fast answer to edge existence
        - rapid updates for edge manipulation
    - disadvantage
        - when n >> m: it uses excessive space
- Adjacency Lists in lists
    - linked lists to store neighbors adjacent to each vertex
    - require pointers
    - efficient to represent sparse graphs
- Adjacency Lists in matrices
    - Represent a list in an array
    - Keeping a count k for number of elements per vertex
    - Simple and static graphs
    - Combines disadvatage of adjacency matrices and adjacency lists
        - Large space
        - need to search for edges

# Traversal
- Breadth-First Search (BFS)
- Depth-First Search (DFS)

## BFS
- Given a graph G = (V, E) and a distinguished source vertex s
- systematically explore edges of G to "discover" every vertex reachable from s
- discover all vertices at distance k from s before discovering any vertex at distance k + 1

```c
BFS(G, v)
{
    for each v in V - {s}: //s: starting vertex
        visited[v]<- NO;
    visited[s]<- YES;
    enqueue(Q, s); //Q: Queue
    while(Q not empty)
    {
        u<-dequeue(Q);
        for each v in L(u) //L(u): adjacency list of vertex u
            if(visited[v] = NO)
                visited[v]<-YES;
                enqueue(Q, v);
    }
}
```

## DFS
- Given a graph G = (V, E) and a distinguished source vertex s
- systematically explore edges of G to discover every vertex reachable from s
- continue discovering away from s

```c
DFS(G, u)
{
    visited[u]<-YES;
    for each v in adj[u]: //u: current vertex
        visited[v]<-NO;
        DFS(G, v);
}

init()
{
    for each u in G:
        visited[u]<-NO;
    for each u in G:
        DFS(G, u);
}
```
# Dynamic Programming
- Systematically searching all possibilities (guarantee correctness) while storing results to avoid recomputing (provide efficiency)

## Implement Recursive Algorithms
Divide-and-Conquer
- Top-Down approach
- Not feasible for problems which common parts exist in subproblems, such as Fibonacci numbers

Dynamic Programming
- Bottom-Up approach
- Divide entire problem to various levels of subproblems
    - subproblem solutions are stored at their level
    - necessary information can be reused when solving problem

## Rod cutting example with maximizing profit for n
- naive algorithm
```c
cut-rod(p, n)
{
    if n == 0
        return 0
    q = negative max;
    for i = 1 to n
        q = max(q, p[i] + cut-rod(p, n - 1));
    
    return q;
}
```

- Memoization(top down approach)
```c
memoized-cut-rod(p,n)
{
    r[n];
    for i = 0 to n
        r[i] = negative max;
    return memoized-cut-rod-aux(p,n,r);
}

memoized-cut-rod-aux(p,n,r)
{
    if r[n]>= 0
    {
        return r[n];
    }

    if(n == 0)
        q == 0;
    else
        q == negative max;
        for i = 1 to n
            q = max(q, p[i] + memoized-cut-rod-aux(p, n - i, r[i]));
    r[n] = q;
    return q;
}
```
- bottom up approach
```c
bottom-up-cut-rod(p,n)
{
    r[n];
    r[0] = 0;
    for j = 1 to n
        q = negative max;
        for i = 1 to j
            q = max(q, p[i] + r[j - i])
        r[j] = q;
    
    return r[n];
}
```

## Rod Cutting Example for optimal way
```c
extended-bottom-up-cut-rod(p,n)
{
    r[n],s[n];
    r[0] = 0;
    for j = 1 to n
        q = negative max;
        for i = 1 to j
            if q < p[i] + r[j - i]
                q = p[i] + r[j - i];
                s[j] = i;
        r[j] = q;
    return r and s;
}

print-cut-rod-solution(p, n)
{
    (r, s) = extended-bottom-up-cut-rod(p, n);
    while(n > 0)
    {
        print s[n];
        n = n - s[n];
    }
}
```

## Elevator Optimization
- Given are the riders' destinations, and k stops
- find the optimized k number of stops to reduce penalty of walking up and down
- penalty for walking up and down are the same
- aim is to select the floors to minimize total number of floors people have to walk up or down

### Solution
- Dynamic programming is based on recursive algorithms
- Best place to put the kth stop depends on the cost of all possible solutions with k - 1th stops
- Given two floors f1 and f2
    - f2 is of no interest for passengers with destinations f1 and below
    - f1 is of no interest for passengers with destinations f2 and above

**Approach: Incrementally add a new stop higher than all selected stops**

**Store the minimum cost of the situation where the number of stops is j and the last highest stop is floor i**

- Recurrence relation
    - Mij = minimum cost of serving riders using j stops, the last stop being at floor i
    - (j + 1)th stop must be higher than the previous jth stop at floor i
    - the (j + 1)th stop is only of interest for passengers above ith floor
    - We must divide the passengers between the (j + 1)th stop and ith stop based on which stop they are closer to

Mij = min{Mk(j-1) - walk(k, MAX) + walk(k, i) + walk(i, MAX)}
// k = 0 to i
- Mij as the minimum cost of serving all the riders using exactly j stops, the last of which is at floor i
- walk(a, b): total number of floors walked between floor a and b

```c
//global matrices
#define NFLOORS 110 //building height in floors
#define MAX_RIDERS 50 //elevator capacity

int stops[MAX_RIDERS]; //floor that everyone gets off
int nriders; //number of riders
int nstops; //number of allowable stops

int m[NFLOORS+1][MAX_RIDERS]; //dynamic programming cost table
int p[NFLOORS+1][MAX_RIDERS]; //dynamic programming parent table

//function to count total number of floors walked by passengers when elevator stops at consecutive previous and current floors
int floors_walked(int previous, int current)
{
    int nsteps = 0; //total distance traveled
    int i; //counter

    for(i = 1; i <= nriders; i++)
    {
        if((stops[i] > previous) && (stops[i] <= current))
        {
            nsteps += min(stops[i] - previous, current - stops[i]);
        } 
    }
    return nsteps;
}

//implementation of the recurrence
int optimize_floors()
{
	int i, j, k;
	int cost;
	int laststop;
	
	for(i = 0; i <= NFLOORS; i++)
	{
		m[i][0] = floors_walked(0, MAXINT);
		p[i][0] = -1;
	}
	
	for(j = 1; j <= nstops; j++)
	{
		for(i = 0; i <= NFLOORS; i++)
		{
			m[i][j] = MAXINT;
			for(k = 0; k <= i; k++)
			{
				cost = m[k][j - 1] - floors_walked(k, MAXINT) + floors_walked(k, i) + floors_walked(i, MAXINT);
				if(cost < m[i][j])
				{
					m[i][j] = cost;
					p[i][j] = k;
				} 
			}
		}
	}
	
	laststop = 0;
	for(i = 1; i <= NFLOORS; i++)
	{
		if(m[i][nstops] < m[laststop][nstops])
		{
			laststop = i;
		}
	}
	
	return laststop;
}

// reconstruct solution by following parent pointers and working backwards
void reconstruct_path(int lastfloor, int stops_to_go)
{
	if(stops_to_go > 1)
	{
		reconstruct_path(p[lastfloor][stops_to_go], stops_to_go - 1);
	}
	
	printf("%d\n", lastfloor);
}
```

# Combinatorics
## Basic Counting
- Math notion on counting
- Rule of Product
    - Cases that A and B occur together
    - |A| = m, |B| = n-> m*n
- Rule of Sum
    - Cases that event A or B occur
    - A & B are independent-> m + n

- Elements in Union Sets
    - |A U B| = |A| + |B| - |A & B|
    - & = intersection

- Permutation
    - arrangement of n items, each item appearing once only
    - n!

## Recurrence relations
- equation defined in terms of itself
- An = A(n-1) + 1, A1 = 1 -> An = n

## Binomial Coefficient
- Effective way of choosing k ones out of n things [n k] (n on top) or nCk
- Directly related to Pascal's Triangle
    - Each coefficient is nCk
    - n = 3
    - 1(3C0) 3(3C1) 3(3C2) 1(3C3)
    - sum of row *n* in Pascal's triangle = 2^n
- nCk = n! / ((n - k)! * (k!))
- nCk = (n - 1)C(k - 1) + (n - 1)C(k)
    - Case 1: element belongs to the chosen k elements
    - Case 2: element is not in the chosen k elements

EXAMPLE
```
Given a set {1, 2, 3, 4}; n = 4, k = 2, no repetition
4C2 = {12, 13, 14, 23, 24, 34} = 6

for specific element '1'
Case 1: '1' already belongs to the two chosen elements
    only need to choose one more element from {2, 3, 4}
Case 1 = 3C1

Case 2: '1' does not belong to the two elements
    need to choose two elements from {2, 3, 4}
Case 2 = 3C2

4C2 = 3C1 + 3C2 = 3 + 3 = 6
```

## Recursion
Recursion (and Induction)
- Math Induction provides a tool to solve recurrences
- Math induction is implemented by recursion
- Thus, recursion is the way of solving recurrences
```
Tn = 2T(n - 1) + 1, T0 = 0

Solution by Math Induction
As n increases, Tn increases roughly double. Assume Tn = 2^n - 1

n = 0; T0 = 2^0 - 1 = 0

Tn = 2^n - 1 assumed to be true 

T(n + 1) = 2Tn + 1 = 2(2^n - 1) + 1 = 2^(n + 1) - 1

True for all n
```

# Shoemaker Problem
## Problem
- Shoemaker has N order from customers. He can work on one job each day. Jobs take several days. For the ith job, the integer Ti denotes the number of days it takes the shoemaker to finish the job.
- For each delay before starting to work on the ith job, shoemaker agrees to pay a fine of Si cents per day.
- Create a program to find the sequence of jobs with minimum total fine

Input:
- N: nubmer of jobs
- Ti: completion time
- Si: daily penalty

Output:
- print the sequence of jobs with minimal fine

## Solution
### Example
- Suppose job sequence {A, B, C, D}
    - A: T = 3, S = 4
    - B: T = 1, S = 1000
    - C: T = 2, S = 2
    - D: T = 5, S = 5

- Original cost (A, B, C, D):
- 0*4 + (0 + 3) * 1000 + (0 + 3 + 1) * 2 + (0 + 3 + 1 + 2) * 5

- Trying (B, A, C, D):
- 0 * 1000 + (0 + 1) * 4 + (0 + 1 + 3) * 2 + (0 + 1 + 3 + 2) * 5

### Pattern / Property
1. swapping two consecutive jobs' orders, the cost of jobs after the two jobs do not change
2. When swapping consecutive two jobs, with the example as basis
    - Original cost before change:
        - 0*4 + (0 + 3) * 1000
    - Trying cost after change:
        - 0 * 1000 + (0 + 1) * 4

    - Difference in Original:
        - 3 * 1000
        - Day[A] * Fine[B]
    - Difference in Trying:
        - 1 * 4
        - Day[B] * Fine[A]
    
    - When changing two job positions, the cost difference is Day[A] * Fine[B] - Day[B] * Fine[A]

### Solution Summarize
1. Start from any job sequence
2. Find any two consecutive jobs that reduce the total fine by comparing Day[A] * Fine[B] - Day[B] * Fine[A] (Swap if difference is greater than 0)
3. Repeat 2 until there in no such job pair

- Time Complexity = O(n^2)
    - Bubble sort


# Real-Time Systems
- Systems that operate with time constraints
## Definition
- Systems whose correctness depends on their temporal aspects as well as their functional aspects

## Performance Measure
- Timeliness on timing constraints (deadlines)
- Speed / average case performances are less significant

## Key Property
- Predictability on timing constraints

## Real-time systems (contd.)
- Real-time != Fast
    - common misconception
    - rather predictable than fast
    - Prefer max or min close to average rather than insane max / min stats