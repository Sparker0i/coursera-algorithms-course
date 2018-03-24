## CODE
[fibonacci](fibonacci.cpp)
## TASK
Given a number n, find the nth Fibonacci number F~n~
## INPUT FORMAT
The input consists of a single integer n
## OUTPUT FORMAT
Output F~n~
## CONSTRAINTS
0 ≤ n ≤ 45

### Sample 1
#### Input 
`10`
#### Output
`55`

This is so because the 10th Fibonacci number is 55

## EXPLANATION
We start by assigning F~0~ = 0 and F~1~ = 1. After this, for every i ≥ 2 and i ≤ n, we follow the trivial way of solving the algorithm as:

`F[i] = F[i - 1] + F[i - 2] ; i ≥ 2`

In this way we compute the fibonacci numbers until the given limit n. Once we calculate, we return `F[n]` , which is our answer.
