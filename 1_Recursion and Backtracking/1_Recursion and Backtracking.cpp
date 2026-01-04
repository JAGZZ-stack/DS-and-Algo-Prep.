#include<bits/stdc++.h>
using namespace std;

Recursion For Coding Interviews (Insights from the Candidate Master - Codeforces) : 

-- Logical Definition
-- Way to implement Recursion
-- Recursive Thinking (Recurrence Relations and Base Case)
-- Structure/Skeleton of Recursive Function
-- Estimating Time and Space Complexities
-- Predict the output (Drawing the recursive tree)

// Types of Recursive Problems :
-- Divide and Conquer 
    // 1. Factorial 
    // 2. Fibonacci 
    // 3. Check for Palindromic Strings
-- Backtracking 
    // 1. Generate all the subsets of the array.
    // 2. N-Queens Problem
    
Logical Definition : 
Practically, recursion is breaking the larger problem into smaller subproblems.
This can only be expressed in terms of mathematical expressions that are said to be "Recurrence Relations". // (Recurrence Relation relates the larger problem to the smaller subproblems

Way to implement Recursion : 
Function calling itself multiple times with the changed input values.

Recursive Thinking :
Recurrence Relation :
Lets say we have a larger problem. 
-- We need to think if we can break down this larger problem into multiple smaller      problems step by step. (//until the base case is hit (or) the problem cannot be 
   // broken down further)

-- Then, start solving from the smaller problems and with the help of which we find 
   the answers for the larger problems

// Example :
// fact(n) = fact(n-1) * n;
// fib(n) = fib(n-1) + fib(n-2);

Base Case : 
-- Recurrence Relations are not true for all the values of input.
-- For example, fact(n) = fact(n-1) * n; fails for the input 0. So, this is called the base case and the recursion needs to stop here.

Structure of Recursive function :
1. Factorial Problem
int factorial(int n) {
    // Base Case : 
    if(n == 0) 
        return 1;
    
    // Recurrence Relation
    return factorial(n-1) * n;
}    
// Total Functions calls : n; TC : O(n)
// Space Complexity ; O(n)

2. Fibonacci Problem
int fibonacci(int n) {
    // Base Case : 
    if(n < 2) 
        return n;
    
    // Recurrence Relation
    return fibonacci(n-1) + fibonacci(n-2);
}
// Total Functions calls : 2^n; TC : O(2^n) // Consider all the circles of a tree
// Space Complexity : O(n) // Maximum Height of a tree.
// For visualisation : Either make use of call stack or tree like visualisation

Why stack is the appropriate data structure.
Because the control flow is from top to bottom and return flow is from bottom to top, we make use of LIFO data structure, stack.

// Predict the output :
void func(int x) {
    print(x);
    if(x >= 3) 
        return;
    func(x+1);
    func(x+2);
}

func(0) [Prints 0]
               /        \
        func(1) [P:1]    func(2) [P:2]
        /      \          /      \
   func(2) [P:2]  func(3) [P:3]  func(3) [P:3]  func(4) [P:4]
   /      \        (Base Case)    (Base Case)    (Base Case)
func(3) [P:3] func(4) [P:4]
(Base Case)   (Base Case)

Output : 0 1 2 3 4 3 2 3 4
// TC : O(2^n)
// SC : O(4)

// (Divide and Conquer Based Recursion Problems) 
1. Check if the given string is a Palindrome 
// Note : Factorial and Fibonacci Problems are also Divide and Conquer based.

bool isPalindrome(string s, int i, int j) {
    // Base Case  
    if(i >= j) // To handle both odd and even length strings
        return true;

    // Recurrence Relation 
    return (s[i] == s[j] && isPalindrome(s, i+1, j-1)); // Calling the function should be the last thing.   
}

// TC : O(n/2) function calls : O(n)
// SC : O(n/2) : O(n)

// (Backtracking Based Recursion Problems)

1. Generate all the subsets of the array (Inputs are distinct).

 * DETAILED EXECUTION TREE (Pick/Don't Pick)
 * * MOVIE 0: rec(0) -> Focus: 1 (Apples)
 * Tray: [ ]
 * |
 * |--- CHOICE 1: PICK 1 (Apples)
 * |    - Action: Tray: [ 1 ]
 * |    - Status: Pause Movie 0. CALL rec(1) ------------------------------------┐
 * |                                                                             |
 * |    MOVIE 1: rec(1) -> Focus: 2 (Bananas)                                    |
 * |    Tray: [ 1 ]                                                              |
 * |    |                                                                        |
 * |    |--- CHOICE 1: PICK 2 (Bananas)                                          |
 * |    |    - Action: Tray: [ 1, 2 ]                                            |
 * |    |    - Status: Pause Movie 1. CALL rec(2) -----------------------------┐ |
 * |    |                                                                     | |
 * |    |    MOVIE 2: rec(2) -> Focus: 3 (Oranges)                            | |
 * |    |    Tray: [ 1, 2 ]                                                   | |
 * |    |    |                                                                | |
 * |    |    |--- CHOICE 1: PICK 3 (Oranges)                                  | |
 * |    |    |    - Action: Tray: [ 1, 2, 3 ]                                 | |
 * |    |    |    - CALL rec(3) --------------------------------------------┐ | |
 * |    |    |      MOVIE 3: rec(3) (Base Case)                             | | |
 * |    |    |      - ACTION: Print "{ 1 2 3 }"                             | | |
 * |    |    |      - RETURN to Movie 2. -----------------------------------┘ | |
 * |    |    |                                                                | |
 * |    |    |--- BACKTRACK: Pop 3. Tray: [ 1, 2 ]                            | |
 * |    |    |                                                                | |
 * |    |    |--- CHOICE 2: DON'T PICK 3 (Oranges)                            | |
 * |    |    |    - CALL rec(3) --------------------------------------------┐ | |
 * |    |    |      MOVIE 4: rec(3) (Base Case)                             | | |
 * |    |    |      - ACTION: Print "{ 1 2 }"                               | | |
 * |    |    |      - RETURN to Movie 2. -----------------------------------┘ | |
 * |    |    |                                                                | |
 * |    |    |--- MOVIE 2 ENDS. Return to Movie 1. ---------------------------┘ |
 * |    |                                                                        |
 * |    |--- BACKTRACK: Pop 2. Tray: [ 1 ]                                       |
 * |    |                                                                        |
 * |    |--- CHOICE 2: DON'T PICK 2 (Bananas)                                    |
 * |    |    - Status: Pause Movie 1. CALL rec(2) -----------------------------┐ |
 * |    |                                                                     | |
 * |    |    MOVIE 5: rec(2) -> Focus: 3 (Oranges)                            | |
 * |    |    Tray: [ 1 ]                                                      | |
 * |    |    |--- CHOICE 1: PICK 3 -> rec(3) -> Print "{ 1 3 }"               | |
 * |    |    |--- BACKTRACK: Pop 3. Tray: [ 1 ]                               | |
 * |    |    |--- CHOICE 2: DON'T PICK 3 -> rec(3) -> Print "{ 1 }"           | |
 * |    |    |--- MOVIE 5 ENDS. Return to Movie 1. ---------------------------┘ |
 * |    |                                                                        |
 * |    |--- MOVIE 1 ENDS. Return to Movie 0. -----------------------------------┘
 * |
 * |--- BACKTRACK: Pop 1. Tray: [ ]
 * |
 * |--- CHOICE 2: DON'T PICK 1 (Apples)
 * |    - Status: Pause Movie 0. CALL rec(1) ------------------------------------┐
 * |                                                                             |
 * |    MOVIE 6: rec(1) -> Focus: 2 (Bananas)                                    |
 * |    Tray: [ ]                                                                |
 * |    |--- CHOICE 1: PICK 2 (Bananas)                                          |
 * |    |    - Action: Tray: [ 2 ]                                               |
 * |    |    - CALL rec(2) ----------------------------------------------------┐ |
 * |    |      MOVIE 7: rec(2) -> Focus: 3 (Oranges)                           | |
 * |    |      |-- PICK 3 -> rec(3) -> Print "{ 2 3 }"                         | |
 * |    |      |-- BACKTRACK: Pop 3. Tray: [ 2 ]                               | |
 * |    |      |-- DON'T PICK 3 -> rec(3) -> Print "{ 2 }"                     | |
 * |    |      |-- MOVIE 7 ENDS. ----------------------------------------------┘ |
 * |    |                                                                        |
 * |    |--- BACKTRACK: Pop 2. Tray: [ ]                                         |
 * |    |                                                                        |
 * |    |--- CHOICE 2: DON'T PICK 2 (Bananas)                                    |
 * |    |    - CALL rec(2) ----------------------------------------------------┐ |
 * |    |      MOVIE 8: rec(2) -> Focus: 3 (Oranges)                           | |
 * |    |      |-- PICK 3 -> rec(3) -> Print "{ 3 }"                           | |
 * |    |      |-- BACKTRACK: Pop 3. Tray: [ ]                                 | |
 * |    |      |-- DON'T PICK 3 -> rec(3) -> Print "{ }"                       | |
 * |    |      |-- MOVIE 8 ENDS. ----------------------------------------------┘ |
 * |    |--- MOVIE 6 ENDS. Return to Movie 0. -----------------------------------┘
 * |
 * |--- MOVIE 0 ENDS. (FINISH)

// Strictly stick to this framework to construct the code : 
// Look at the tree-diagram, notice what we do at any one level.
// We have two choices, either pick up or skip
// If picked up, move to the next level
// Else skip it and move to the next level.

// Dont forget to clean up (pop_back) before going for the next choice.

void generateSubsets(int index, vector<int>& nums, vector<int>& tray, vector<vector<int>>& result) {
    // --- THE BASE CASE ---
    // Condition: Have we finished making choices for all elements?
    if (index == nums.size()) {
        result.push_back(tray); // Action: Take a snapshot of the current tray
        return;                 // Action: Exit this 'Movie'
    }

    // --- THE RECURSIVE CHOICES ---

    // CHOICE 1: PICK the element
    tray.push_back(nums[index]);          // Action: Put item in Tray
    generateSubsets(index + 1, nums, tray, result); // Call next Movie

    // BACKTRACK: Clean up before the next choice
    tray.pop_back();                      // Action: Remove item from Tray

    // CHOICE 2: DON'T PICK the element
    generateSubsets(index + 1, nums, tray, result); // Call next Movie
}

// Time and Space Complexities Estimation 
// TC : O(2 ^ n * n)
// SC : O(n)
