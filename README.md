# DS-and-Algo-Prep.

============================================================
ALGO INTERVIEW: THE INSTANT BRUTE FORCE FRAMEWORK
============================================================

1. THE CORE PHILOSOPHY
------------------------------------------------------------
Master the "Optimal" implementation for fluency, but use the 
"Mental Map" to work backward to the Brute Force during the 
interview. To derive Brute Force, ask: "What is the most 
'brainless' way to look at every possibility?"

2. THE 3-BUCKET FRAMEWORK
------------------------------------------------------------

BUCKET 1: THE "SEARCH & MATCH" (Linear/Tabular Data)
- Triggers: "Find a pair/triplet", "Longest subarray", "Search target".
- The Framework: Nested Loops.
  - Need a pair? 2 loops.
  - Need a triplet? 3 loops.
  - Need a subarray? 2 loops (start index i, end index j).
- Complexity: O(n^2) or O(n^3).



BUCKET 2: THE "DECISION TREE" (Combinatorics)
- Triggers: "Permutations", "Subsets", "Find all paths", "Sum to X".
- The Framework: Recursion (Pick or Don't Pick).
  - For every element, you have two choices: Include or Exclude.
- Complexity: O(2^n) for subsets or O(n!) for permutations.



BUCKET 3: THE "STATE EXPLORER" (Graphs/Matrices)
- Triggers: "Shortest path", "Number of islands", "Reach the end".
- The Framework: The Flood Fill (DFS/BFS).
  - Just visit every neighbor. Don't worry about efficiency yet.
- Complexity: O(V + E) or O(Rows x Cols).



3. THE INTERVIEW EXECUTION (3 STEPS)
------------------------------------------------------------
STEP 1: Identify the Bucket.
        (e.g., "This is a subarray problem, so it's Search & Match.")

STEP 2: State the 'Brainless' Goal.
        "The simplest way is to check every single possible subarray."

STEP 3: Explain the Logic.
        "I'll use a nested loop where i is start and j is end. 
        For each (i, j), I'll calculate the sum. This is O(n^2)."

TRANSITION TO OPTIMAL: 
"However, I notice we are recalculating sums repeatedly, 
so we can optimize this to O(n) using [Optimal Solution]."

4. THE DERIVATION CHEAT SHEET
------------------------------------------------------------
Keyword             | Brute Force Logic            | Complexity
--------------------|------------------------------|------------
"Subarray"          | Try all i (start) & j (end)  | O(n^2)
"Pair"              | Try all i and j              | O(n^2)
"Subsets"           | Try every combination (2^n)  | O(2^n)
"Permutations"      | Try every ordering (n!)      | O(n!)
"Matrix Path"       | DFS every possible direction | O(3^N/4^N)
============================================================
