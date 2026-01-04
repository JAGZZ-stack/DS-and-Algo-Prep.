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
    // This is nothing but implementing the brute force problems in the recursive 
    // manner. When I mean brute force, you can think of like checking for all 
    // choices.
    
    // 1. Generate all the subsequences
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
// Step 1 : Take pen and paper, draw the recursion tree.    
* DETAILED EXECUTION TREE (Pick / Don't Pick)
 * Input: [1, 2, 3] (Apples, Bananas, Oranges)
 * * Root: rec(0) -> Focus: 1
 * Path: []
 * |
 * |--- CHOICE 1: PICK 1
 * |    - Path: [ 1 ]
 * |    - CALL rec(1) ------------------------------------------------------┐
 * |      rec(1) -> Focus: 2                                                |
 * |      |                                                                 |
 * |      |--- CHOICE 1: PICK 2                                             |
 * |      |    - Path: [ 1, 2 ]                                             |
 * |      |    - CALL rec(2) ---------------------------------------------┐ |
 * |      |      rec(2) -> Focus: 3                                       | |
 * |      |      |                                                        | |
 * |      |      |--- CHOICE 1: PICK 3 -> rec(3) (Base) -> Print { 1 2 3 } | |
 * |      |      |--- BACKTRACK: Pop 3. Path: [ 1, 2 ]                    | |
 * |      |      |--- CHOICE 2: SKIP 3 -> rec(3) (Base) -> Print { 1 2 }   | |
 * |      |      └--- RETURN to rec(1) -----------------------------------┘ |
 * |      |                                                                 |
 * |      |--- BACKTRACK: Pop 2. Path: [ 1 ]                                |
 * |      |                                                                 |
 * |      |--- CHOICE 2: SKIP 2                                             |
 * |      |    - CALL rec(2) ---------------------------------------------┐ |
 * |      |      rec(2) -> Focus: 3                                       | |
 * |      |      |--- CHOICE 1: PICK 3 -> rec(3) (Base) -> Print { 1 3 }   | |
 * |      |      |--- BACKTRACK: Pop 3. Path: [ 1 ]                       | |
 * |      |      |--- CHOICE 2: SKIP 3 -> rec(3) (Base) -> Print { 1 }     | |
 * |      |      └--- RETURN to rec(1) -----------------------------------┘ |
 * |      └--- RETURN to rec(0) --------------------------------------------┘
 * |
 * |--- BACKTRACK: Pop 1. Path: []
 * |
 * |--- CHOICE 2: SKIP 1
 * |    - CALL rec(1) ------------------------------------------------------┐
 * |      rec(1) -> Focus: 2                                                |
 * |      |--- CHOICE 1: PICK 2                                             |
 * |      |    - Path: [ 2 ]                                                |
 * |      |    - CALL rec(2) ---------------------------------------------┐ |
 * |      |      rec(2) -> Focus: 3                                       | |
 * |      |      |--- CHOICE 1: PICK 3 -> rec(3) (Base) -> Print { 2 3 }   | |
 * |      |      |--- BACKTRACK: Pop 3. Path: [ 2 ]                       | |
 * |      |      |--- CHOICE 2: SKIP 3 -> rec(3) (Base) -> Print { 2 }     | |
 * |      |      └--- RETURN to rec(1) -----------------------------------┘ |
 * |      |                                                                 |
 * |      |--- BACKTRACK: Pop 2. Path: []                                   |
 * |      |                                                                 |
 * |      |--- CHOICE 2: SKIP 2                                             |
 * |      |    - CALL rec(2) ---------------------------------------------┐ |
 * |      |      rec(2) -> Focus: 3                                       | |
 * |      |      |--- CHOICE 1: PICK 3 -> rec(3) (Base) -> Print { 3 }     | |
 * |      |      |--- BACKTRACK: Pop 3. Path: []                          | |
 * |      |      |--- CHOICE 2: SKIP 3 -> rec(3) (Base) -> Print { }       | |
 * |      |      └--- RETURN to rec(1) -----------------------------------┘ |
 * |      └--- RETURN to rec(0) --------------------------------------------┘
 * └--- FINISH
    
// Step 2 :
// Strictly stick to this framework to construct the code : 
// Look at the tree-diagram, notice what we do at any one level.
// We have two choices, either pick up or skip
// If picked up, move to the next level
// Else skip it and move to the next level.

// Dont forget to clean up (pop_back) before going for the next choice.

void rec(int index, vector<int>& nums, vector<int>& tray, vector<vector<int>>& result) {
    // --- THE BASE CASE ---
    // Condition: Have we finished making choices for all elements?
    if (index == nums.size()) {
        result.push_back(tray); // Action: Take a snapshot of the current tray
        return;                 // Action: Exit this 'Movie'
    }

    // --- THE RECURSIVE CHOICES ---

    // CHOICE 1: PICK the element
    tray.push_back(nums[index]);          // Action: Put item in Tray
    rec(index + 1, nums, tray, result); // Call next Movie

    // BACKTRACK: Clean up before the next choice
    tray.pop_back();                      // Action: Remove item from Tray

    // CHOICE 2: DON'T PICK the element
    rec(index + 1, nums, tray, result); // Call next Movie
}

// Time and Space Complexities Estimation 
// TC : O(2 ^ n * n)
// SC : O(n)

2. N Queens Problem 
// Subsets uses: tray.push_back(nums[index])
// N-Queens uses: queens[row] = col ✓ Same logic!

* DETAILED EXECUTION TREE (Backtracking Search)
 * Problem: 4-Queens (Place 4 queens on 4x4 such that no two attack)
 * Focus: Row index (0 to 3)
 * Path: [Col index for Row 0, Col for Row 1, ...]
 * * * Root: rec(0) -> Focus: Row 0
 * |
 * |--- CHOICE: Place at Col 0 -> Path: [0]
 * |    - CALL rec(1) -> Focus: Row 1
 * |      |--- Col 0, 1: INVALID (Same col/diagonal)
 * |      |--- CHOICE: Place at Col 2 -> Path: [0, 2]
 * |      |    - CALL rec(2) -> Focus: Row 2
 * |      |      |--- Col 0, 1, 2, 3: ALL INVALID (Under attack)
 * |      |      └--- BACKTRACK (Dead End)
 * |      |--- CHOICE: Place at Col 3 -> Path: [0, 3]
 * |      |    - CALL rec(2) -> Focus: Row 2
 * |      |      |--- CHOICE: Place at Col 1 -> Path: [0, 3, 1]
 * |      |      |    - CALL rec(3) -> Focus: Row 3
 * |      |      |      |--- Col 0, 1, 2, 3: ALL INVALID
 * |      |      |      └--- BACKTRACK
 * |      └--- BACKTRACK
 * |
 * |--- CHOICE: Place at Col 1 -> Path: [1]
 * |    - CALL rec(1) -> Focus: Row 1
 * |      |--- CHOICE: Place at Col 3 -> Path: [1, 3]
 * |      |    - CALL rec(2) -> Focus: Row 2
 * |      |      |--- CHOICE: Place at Col 0 -> Path: [1, 3, 0]
 * |      |      |    - CALL rec(3) -> Focus: Row 3
 * |      |      |      |--- CHOICE: Place at Col 2 -> Path: [1, 3, 0, 2]
 * |      |      |      |    - rec(4) (Base Case) -> FOUND SOLUTION: { 1 3 0 2 }
 * |      |      |      └--- BACKTRACK
 * |      └--- BACKTRACK
 * |
 * |--- CHOICE: Place at Col 2 -> Path: [2]
 * |    - CALL rec(1) -> Focus: Row 1
 * |      |--- CHOICE: Place at Col 0 -> Path: [2, 0]
 * |      |    - CALL rec(2) -> Focus: Row 2
 * |      |      |--- CHOICE: Place at Col 3 -> Path: [2, 0, 3]
 * |      |      |    - CALL rec(3) -> Focus: Row 3
 * |      |      |      |--- CHOICE: Place at Col 1 -> Path: [2, 0, 3, 1]
 * |      |      |      |    - rec(4) (Base Case) -> FOUND SOLUTION: { 2 0 3 1 }
 * |      |      |      └--- BACKTRACK
 * |      └--- BACKTRACK
 * |
 * |--- CHOICE: Place at Col 3 -> Path: [3]
 * |    - CALL rec(1) (Mirrors Col 0 logic...)
 * |
 * └--- FINISH

bool isSafe(int row, int col, vector<int>& queens) {
    for (int prevRow = 0; prevRow < row; prevRow++) {
        if (queens[prevRow] == col ||                    // Column attack
            abs(row - prevRow) == abs(col - queens[prevRow])) // Diagonal
            return false;
    }
    return true;
}

void solveNQueens(int row, int n, vector<int>& queens, vector<vector<int>>& result) {
    // IDENTICAL STRUCTURE TO SUBSETS
    if (row == n) {              // Base case ✓
        result.push_back(queens); // Snapshot ✓
        return;
    }
    
    // TRY ALL "PICK" CHOICES (constrained)
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, queens)) {
            queens[row] = col;           // PICK ✓
            solveNQueens(row + 1, n, queens, result);  // RECURSE ✓
            queens[row] = -1;            // BACKTRACK ✓
        }
    }
}

// TC : n=4: 4 choices(row0) × 3(row1) × 2(row2) × 1(row3) = 24 = 4!
// SC : O(n)
















    
    
    
    
    
    
    
    
    
    
    
