// Subarray Sum Equals k - https://leetcode.com/problems/subarray-sum-equals-k/

public int subarraySum(int[] nums, int k) {
    int totalCount = 0;
    int runningTotal = 0;
    
    // A hashmap to remember old totals
    HashMap<Integer, Integer> seen = new HashMap<>();
    
    // Note down that we start at 0
    seen.put(0, 1);
    
    for (int num : nums) {
        // Add the current number to our running total
        runningTotal += num;
        
        // Calculate: "What number should I have seen before to make a gap of k?"
        int lookBackValue = runningTotal - k;
        
        // If that number is in our hashmap, we found k!
        if (seen.containsKey(lookBackValue)) {
            totalCount += seen.get(lookBackValue);
        }
        
        // Write the current running total in the hashmap for later
        seen.put(runningTotal, seen.getOrDefault(runningTotal, 0) + 1);
    }
    
    return totalCount;
}

// TC : O(n)
// SC : O(n)
