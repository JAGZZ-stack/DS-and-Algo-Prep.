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
    // 1. Factorial 2. Fibonacci 3. Check for Palindromic Strings
-- Backtracking 
    // This is nothing but implementing the brute force problems in the recursive 
    // manner. When I mean brute force, you can think of like checking for all 
    // choices.
    
    // 1. N-Queens Problem
    // 2. Generate all the subsets of the array.
    
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

1. Check if the given string is a Palindrome 
// (Divide and Conquer mode)

bool isPalindrome(string s, int i, int j) {
    // Base Case  
    if(i >= j) // To handle both odd and even length strings
        return true;

    // Recurrence Relation 
    return (s[i] == s[j] && isPalindrome(s, i+1, j-1)); // Calling the function should be the last thing.   
}

// TC : O(n/2) function calls : O(n)
// SC : O(n/2) : O(n)

Backtracking Idea :

Stick to this brilliant framework to solve the backtracking problems.
LCCMD Framework - (Level, Choice, Check, Move, Decide)

1. N-Queens Problem 

// Code :
int n;
vector<int> queens;

int canPlace(int level, int col) {
    // We only need to check the rows ABOVE the current 'level'
    // because rows below haven't been filled yet.
    for (int prev_row = 0; prev_row < level; prev_row++) {
        int prev_col = queens[prev_row];

        // 1. Column Check: Is there a queen already in this column?
        if (prev_col == col) {
            return 0; 
        }

        // 2. Diagonal Check:
        // Math Trick: If the row distance equals the column distance, 
        // the two queens are on the same diagonal.
        // |row1 - row2| == |col1 - col2|
        if (abs(level - prev_row) == abs(col - prev_col)) {
            return 0; 
        }
    }

    // If we passed all checks, it is safe to place the queen here.
    return 1;
}

void rec(int level) { // 'level' represents the current Row we are working on
    
    // --- PHASE 1: THE BASE CASE ---
    // This is the "Bottom" of the recursion. When level reaches n, 
    // it means rows 0, 1, 2, and 3 are all filled.
    if(level == n) {
        for(int val : queens) cout << val << " ";
        cout << endl;
        return; // This triggers the start of "Climbing Back Up"
    }

    // --- PHASE 2: THE EXPLORATION ---
    // Every level (row) tries every column from 0 to n-1. (Choice)
    for(int col = 0; col < n; col++) {
        
        if(canPlace(level, col)) {
            // 1. PLACE: 
            queens.push_back(col);

            // 2. RECURSE: 
            // The code PAUSES here. Level 'x' stays in memory 
            // and waits for 'level + 1' to finish everything it has to do.
            rec(level + 1);

            // 3. RESUME & REVERT:
            // This line is only reached AFTER the deeper call (Level + 1) 
            // has completely finished its loop or hit the base case.
            // We "pop_back" to remove our current row's choice so the 
            // 'for' loop can try the NEXT column index.
            queens.pop_back(); 
            
            // After pop_back, the 'for' loop increments 'col' and 
            // we try Phase 2 again with a new column.
        }
    }
    
    // --- PHASE 3: THE EXIT ---
    // If the 'for' loop finishes (col reaches n), this specific 
    // instance of 'rec' ends. The computer automatically jumps 
    // back to the level ABOVE it to resume at its own "Phase 2, Step 3".
}

int main() {
    cin >> n;
    rec(0);
    return 0;
}

// TC : O(n! * n), SC : O(n)

 * THE N-QUEENS CHESS TOURNAMENT: ANALOGY & DRY RUN
 * * In this problem, 'level' represents the ROW number.
 * * In each ROW, we have 4 chairs (columns 0, 1, 2, 3).
 * * We want to seat 4 Queens so none of them can "see" each other.



1. THE ANALOGY: "THE PROTECTIVE SISTERS"
   - There are 4 Sisters (Queens). 
   - Sister 0 must sit in Row 0, Sister 1 in Row 1, and so on.
   - They are very angry; if any sister sees another in the same 
     column or on a diagonal, the "canPlace" check fails.
   
2. THE "PAUSE & RESUME" (The Movies):
   - Movie 0 (Row 0) picks a seat, then PAUSES to let Movie 1 (Row 1) try.
   - If Movie 1 finds no seat, it "Ends," and Movie 0 "Resumes" 
     to move its queen to the next chair.

DRY RUN: Input n = 4 (Let's follow the first successful path)

 * MOVIE 0: rec(0) -- Standing at Row 0
 * Tray (queens): [ ]
 * |
 * |--- CHOICE 1: col = 0
 * |    - check(Row 0, Col 0): Safe!
 * |    - Pick: [ 0 ]
 * |    - CALL rec(1) -----------------------------------------------------------┐
 * |                                                                             |
 * |    MOVIE 1: rec(1) -- Standing at Row 1                                     |
 * |    Tray: [ 0 ]                                                              |
 * |    |                                                                        |
 * |    |--- CHOICE 1: col = 0 -> FAIL (Same column as Row 0)                    |
 * |    |--- CHOICE 2: col = 1 -> FAIL (Diagonal to Row 0)                       |
 * |    |--- CHOICE 3: col = 2                                                   |
 * |    |    - check(Row 1, Col 2): Safe!                                        |
 * |    |    - Pick: [ 0, 2 ]                                                    |
 * |    |    - CALL rec(2) --------------------------------------------------┐   |
 * |    |                                                                    |   |
 * |    |    MOVIE 2: rec(2) -- Standing at Row 2                            |   |
 * |    |    Tray: [ 0, 2 ]                                                  |   |
 * |    |    |                                                               |   |
 * |    |    |--- CHOICE 1: col = 0 -> FAIL (Col check)                      |   |
 * |    |    |--- CHOICE 2: col = 1 -> FAIL (Diagonal to Row 1, Col 2)       |   |
 * |    |    |--- CHOICE 3: col = 2 -> FAIL (Col check)                      |   |
 * |    |    |--- CHOICE 4: col = 3 -> FAIL (Diagonal to Row 1, Col 2)       |   |
 * |    |    |                                                               |   |
 * |    |    |--- RESULT: All columns failed for Row 2!                      |   |
 * |    |    |--- MOVIE 2 ENDS (Dead End). Return to Movie 1. ---------------┘   |
 * |    |                                                                        |
 * |    |--- BACKTRACK (i=2): Put Queen 1 back. Tray: [ 0 ]                      |
 * |    |--- CHOICE 4: col = 3                                                   |
 * |    |    - check(Row 1, Col 3): Safe!                                        |
 * |    |    - Pick: [ 0, 3 ]                                                    |
 * |    |    - CALL rec(2) --------------------------------------------------┐   |
 * |    |                                                                    |   |
 * |    |    MOVIE 2 (v2): rec(2) -- Standing at Row 2                       |   |
 * |    |    Tray: [ 0, 3 ]                                                  |   |
 * |    |    |                                                               |   |
 * |    |    |--- CHOICE 1: col = 0 -> FAIL (Col check)                      |   |
 * |    |    |--- CHOICE 2: col = 1                                          |   |
 * |    |    |    - check(Row 2, Col 1): Safe!                               |   |
 * |    |    |    - Pick: [ 0, 3, 1 ]                                        |   |
 * |    |    |    - CALL rec(3) -----------------------------------------┐   |   |
 * |    |    |                                                           |   |   |
 * |    |    |    MOVIE 3: rec(3) -- Standing at Row 3                   |   |   |
 * |    |    |    Tray: [ 0, 3, 1 ]                                      |   |   |
 * |    |    |    |                                                      |   |   |
 * |    |    |    |--- CHOICE 1: col = 0 -> FAIL (Col check)             |   |   |
 * |    |    |    |--- CHOICE 2: col = 1 -> FAIL (Col check)             |   |   |
 * |    |    |    |--- CHOICE 3: col = 2 -> FAIL (Diagonal to Row 2,Col 1) |   |   |
 * |    |    |    |--- CHOICE 4: col = 3 -> FAIL (Col check)             |   |   |
 * |    |    |    |--- MOVIE 3 ENDS (Dead End). Return to Movie 2. ------┘   |   |
 * |    |    |                                                               |   |
 * |    |    |--- BACKTRACK (i=1): Put Queen 2 back. Tray: [ 0, 3 ]          |   |
 * |    |    |--- CHOICE 3: col = 2 -> FAIL (Diagonal to Row 1, Col 3)       |   |
 * |    |    |--- CHOICE 4: col = 3 -> FAIL (Col check)                      |   |
 * |    |    |--- MOVIE 2 ENDS. Return to Movie 1. --------------------------┘   |
 * |    |                                                                        |
 * |    |--- BACKTRACK (i=3): Put Queen 1 back. Tray: [ 0 ]                      |
 * |    |--- MOVIE 1 ENDS. Return to Movie 0. -----------------------------------┘
 * |
 * |--- BACKTRACK (i=0): Put Queen 0 back. Tray: [ ]
 * |
 * |--- CHOICE 2: i = 1 (Movie 0 moves Queen 0 to Column 1)
 * |    - Pick: [ 1 ]
 * |    - CALL rec(1) ... This eventually leads to the solution [ 1, 3, 0, 2 ]
 */

3. WHY THE TIME COMPLEXITY O(n! * n)?
   - In Row 0, we have N choices.
   - In Row 1, we have roughly N-1 choices (cannot be in the same column).
   - In Row 2, we have roughly N-2 choices.
   - This creates a N * (N-1) * (N-2)... pattern, which is N!.
   - The extra '* n' comes from the 'canPlace' loop checking all previous rows.

4. WHY THE SPACE COMPLEXITY O(n)?
   - We only ever store 'n' queens in the vector.
   - The recursion stack only ever goes 'n' levels deep (one for each row).
*/

int main() {
    /* * In N-Queens, we "Prune" the tree. 
     * Notice how we didn't visit every single possible column? 
     * 'canPlace' acts like a gatekeeper that stops us from 
     * wasting time on paths that are obviously wrong.
     * * Would you like me to explain the "Diagonal Math Trick" 
     * (|r1-r2| == |c1-c2|) in more detail using a grid?
     */
    return 0;
}

// 2. Generate all the subsets of the array (Inputs are distinct).
// Based on the notes that I had taken from my mentors' session, can you kindly teach me this problem using the same framework, same coding style and detailed comments.

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> subset;

// PHASE 1: THE CHECK (Constraint)
// In basic Subsets, every choice is valid as long as we move forward.
// If the problem was "Subsets of size K" or "Sum equals S", 
// this function would contain that logic.
bool canPlace(int index) {
    return true; 
}

void rec(int start_index) { // 'level' here is the starting point for choices
    
    // --- PHASE 2: THE BASE CASE (Decide) ---
    // In this template, every node in the recursion tree is a valid subset.
    // So we print/save the subset immediately.
    cout << "[ ";
    for(int val : subset) cout << val << " ";
    cout << "]" << endl;

    // --- PHASE 3: THE EXPLORATION (The For-Loop) ---
    // We try every possible next element from the current 'start_index' to n-1.
    for(int i = start_index; i < n; i++) {
        
        if(canPlace(i)) {
            // 1. PLACE
            subset.push_back(arr[i]);

            // 2. RECURSE
            // Move to i + 1 so we don't pick the same element again.
            rec(i + 1);

            // 3. RESUME & REVERT (Backtrack)
            subset.pop_back();
        }
    }
}

int main() {
    arr = {1, 2, 3};
    n = arr.size();
    
    // Start from index 0
    rec(0);
    
    return 0;
}

// If I asked you to "Find all subsets of size 2", you would only need to change one line in the N-Queens template:

// if(subset.size() == 2) { 
//     // print and return 
// }



THE RECTIFIED FRUIT BUFFET: PERFECT INDENTATION DRY RUN
I understand completely. Indentation is the "GPS" of recursion. 
Without it, you lose track of which "Movie" you are currently watching.
In this trace, every level of recursion is pushed further to the right.


#include <iostream>
#include <vector>
#include <string>

STATIONS: 0:Apples, 1:Bananas, 2:Oranges
n = 3


 * MOVIE 0: rec(0) 
 * Tray: [ ]
 * |
 * |--- ACTION: Print "[ ]"
 * |
 * |--- CHOICE 1: i = 0 (Apples)
 * |    - Action: Pick Apples. Tray: [ Apples ]
 * |    - Status: Pause Movie 0 at i=0.
 * |    - CALL rec(1) -----------------------------------------------------------┐
 * |                                                                             |
 * |    MOVIE 1: rec(1)                                                          |
 * |    Tray: [ Apples ]                                                         |
 * |    |                                                                        |
 * |    |--- ACTION: Print "[ Apples ]"                                          |
 * |    |                                                                        |
 * |    |--- CHOICE 1: i = 1 (Bananas)                                           |
 * |    |    - Action: Pick Bananas. Tray: [ Apples, Bananas ]                   |
 * |    |    - Status: Pause Movie 1 at i=1.                                     |
 * |    |    - CALL rec(2) --------------------------------------------------┐   |
 * |    |                                                                    |   |
 * |    |    MOVIE 2: rec(2)                                                 |   |
 * |    |    Tray: [ Apples, Bananas ]                                       |   |
 * |    |    |                                                               |   |
 * |    |    |--- ACTION: Print "[ Apples, Bananas ]"                        |   |
 * |    |    |                                                               |   |
 * |    |    |--- CHOICE 1: i = 2 (Oranges)                                  |   |
 * |    |    |    - Action: Pick Oranges. Tray: [ Apples, Bananas, Oranges ] |   |
 * |    |    |    - Status: Pause Movie 2 at i=2.                            |   |
 * |    |    |    - CALL rec(3) -----------------------------------------┐   |   |
 * |    |    |                                                           |   |   |
 * |    |    |    MOVIE 3: rec(3)                                        |   |   |
 * |    |    |    Tray: [ Apples, Bananas, Oranges ]                     |   |   |
 * |    |    |    |                                                      |   |   |
 * |    |    |    |--- ACTION: Print "[ Apples, Bananas, Oranges ]"      |   |   |
 * |    |    |    |--- LOOP: i=3; (3 < 3) is FALSE.                      |   |   |
 * |    |    |    |--- MOVIE 3 ENDS. Return to Movie 2. -----------------┘   |   |
 * |    |    |                                                               |   |
 * |    |    |--- BACKTRACK (i=2): Put Oranges back. Tray: [ Apples, Bananas ]|   |
 * |    |    |--- LOOP: i++ becomes 3; (3 < 3) is FALSE.                     |   |
 * |    |    |--- MOVIE 2 ENDS. Return to Movie 1. --------------------------┘   |
 * |    |                                                                        |
 * |    |--- BACKTRACK (i=1): Put Bananas back. Tray: [ Apples ]                 |
 * |    |                                                                        |
 * |    |--- CHOICE 2: i = 2 (Oranges)                                           |
 * |    |    - Action: Pick Oranges. Tray: [ Apples, Oranges ]                   |
 * |    |    - Status: Pause Movie 1 at i=2.                                     |
 * |    |    - CALL rec(3) --------------------------------------------------┐   |
 * |    |                                                                    |   |
 * |    |    MOVIE 4: rec(3)                                                 |   |
 * |    |    Tray: [ Apples, Oranges ]                                       |   |
 * |    |    |                                                               |   |
 * |    |    |--- ACTION: Print "[ Apples, Oranges ]"                        |   |
 * |    |    |--- LOOP: i=3; FALSE.                                          |   |
 * |    |    |--- MOVIE 4 ENDS. Return to Movie 1. --------------------------┘   |
 * |    |                                                                        |
 * |    |--- BACKTRACK (i=2): Put Oranges back. Tray: [ Apples ]                 |
 * |    |--- LOOP: i++ becomes 3; FALSE.                                         |
 * |    |--- MOVIE 1 ENDS. Return to Movie 0. -----------------------------------┘
 * |
 * |--- BACKTRACK (i=0): Put Apples back. Tray: [ ]
 * |
 * |--- CHOICE 2: i = 1 (Bananas)
 * |    - Action: Pick Bananas. Tray: [ Bananas ]
 * |    - Status: Pause Movie 0 at i=1.
 * |    - CALL rec(2) -----------------------------------------------------------┐
 * |                                                                             |
 * |    MOVIE 5: rec(2)                                                          |
 * |    Tray: [ Bananas ]                                                        |
 * |    |                                                                        |
 * |    |--- ACTION: Print "[ Bananas ]"                                         |
 * |    |                                                                        |
 * |    |--- CHOICE 1: i = 2 (Oranges)                                           |
 * |    |    - Action: Pick Oranges. Tray: [ Bananas, Oranges ]                  |
 * |    |    - Status: Pause Movie 5 at i=2.                                     |
 * |    |    - CALL rec(3) --------------------------------------------------┐   |
 * |    |                                                                    |   |
 * |    |    MOVIE 6: rec(3)                                                 |   |
 * |    |    Tray: [ Bananas, Oranges ]                                      |   |
 * |    |    |--- ACTION: Print "[ Bananas, Oranges ]"                       |   |
 * |    |    |--- MOVIE 6 ENDS. Return to Movie 5. --------------------------┘   |
 * |    |                                                                        |
 * |    |--- BACKTRACK (i=2): Put Oranges back. Tray: [ Bananas ]                |
 * |    |--- MOVIE 5 ENDS. Return to Movie 0. -----------------------------------┘
 * |
 * |--- BACKTRACK (i=1): Put Bananas back. Tray: [ ]
 * |
 * |--- CHOICE 3: i = 2 (Oranges)
 * |    - Action: Pick Oranges. Tray: [ Oranges ]
 * |    - CALL rec(3) -----------------------------------------------------------┐
 * |                                                                             |
 * |    MOVIE 7: rec(3)                                                          |
 * |    |--- ACTION: Print "[ Oranges ]"                                         |
 * |    |--- MOVIE 7 ENDS. Return to Movie 0. -----------------------------------┘
 * |
 * |--- BACKTRACK (i=2): Put Oranges back. Tray: [ ]
 * |--- LOOP: i++ becomes 3; FALSE.
 * |--- MOVIE 0 ENDS. (FINISH)
 */

int main() {
    /*
     * Look how the indentation "collapses" back to the left 
     * every time a movie ends. This is the visual representation 
     * of Backtracking.
     * * Does the visual "staircase" of indentation make it 
     * clearer how the computer "steps back" in its memory?
     */
    return 0;
}


ORDER OF PRINTING:
   1.  [ ]                          (The starting point - Movie 0)
   2.  [ Apples ]                   (Pick the first available fruit)
   3.  [ Apples, Bananas ]          (Pick the next available)
   4.  [ Apples, Bananas, Oranges ] (Deepest possible path reached)
   --- Backtrack starts ---
   5.  [ Apples, Oranges ]          (Back to Apples, skip Bananas, pick Oranges)
   --- Backtrack to Start ---
   6.  [ Bananas ]                  (Start fresh from second fruit)
   7.  [ Bananas, Oranges ]         (Pick next available after Bananas)
   --- Backtrack to Start ---
   8.  [ Oranges ]                  (Start fresh from third fruit)












    
    
    
    
    
    
    
    
    
    
    
