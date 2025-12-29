// Recursion - Building Blocks :

// Agenda :
// Logical Definition
// Way to implement Recursion
// Recursive Thinking (Recurrence Relations and Base Case)
// Structure/Skeleton of Recursive Function
// Estimating Time and Space Complexities
// Predict the output (Drawing the recursive tree)
// Backtracking Idea
// Why Recursion and Backtracking complement each other.
// Problem 1 : Check palindromic strings

// Logical Definition : 
// Practically, recursion is breaking the larger problem into smaller subproblems.
// This can only be expressed in terms of mathematical expressions that are said to be "Recurrence Relations". // (Recurrence Relation relates the larger problem to the smaller subproblems

// Way to implement Recursion : 
// Function calling itself multiple times with the changed input values.

// Recursive Thinking :
// Recurrence Relation :
// Lets say we have a larger problem. 
// -- We need to think if we can break down this larger problem into multiple smaller      problems step by step. (//until the base case is hit (or) the problem cannot be 
//    // broken down further)

// -- Then, start solving from the smaller problems and with the help of which we find 
//    the answers for the larger problems

// Example :
// fact(n) = fact(n-1) * n;
// fib(n) = fib(n-1) + fib(n-2);

// Base Case : 
// -- Recurrence Relations are not true for all the values of input.
// -- For example, fact(n) = fact(n-1) * n; fails for the input 0. So, this is called the base case and the recursion needs to stop here.

// Structure of Recursive function :
// 1. Factorial Problem
int factorial(int n) {
    // Base Case : 
    if(n == 0) 
        return 1;
    
    // Recurrence Relation
    return factorial(n-1) * n;
}    
// Total Functions calls : n; TC : O(n)
// Space Complexity ; O(n)

// 2. Fibonacci Problem
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

// Why stack is the appropriate data structure.
// Because the control flow is from top to bottom and return flow is from bottom to top, we make use of LIFO data structure, stack.

// Predict the output :
// void func(int x) {
//     print(x);
//     if(x >= 3) 
//         return;
//     func(x+1);
//     func(x+2);
// }

// func(0) [Prints 0]
//                /        \
//         func(1) [P:1]    func(2) [P:2]
//         /      \          /      \
//    func(2) [P:2]  func(3) [P:3]  func(3) [P:3]  func(4) [P:4]
//    /      \        (Base Case)    (Base Case)    (Base Case)
// func(3) [P:3] func(4) [P:4]
// (Base Case)   (Base Case)

// Output : 0 1 2 3 4 3 2 3 4
// TC : O(2^n)
//  SC : O(4)

// 1. Check if the given string is a Palindrome 
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

// Backtracking Idea :
// Lets say we have a number 7. This undergoes series of operations.
//     Op : 1            Op : 2              Op : 3
// 7 ------------> 14 --------------> 15 --------------> 3
//       *2                +1                  /5

// Now, If we only know the final number and the operations that were performed, can we get to our initial number? Yes, Undoing all the operations in the reverse 
// manner would give us the initial value.
    
// This is the basis of backtracking.

// Why Recursion and Backtracking complement each other?
// In recursion, we call f(x), do some modifications call f(x') -> f(x'') -> f(x''')..
// Then, the undoing/returning happens in the reverse order and that automatically resembles backtracking.
    
















    
    
    
    
    
    
    
    
    
    
    
