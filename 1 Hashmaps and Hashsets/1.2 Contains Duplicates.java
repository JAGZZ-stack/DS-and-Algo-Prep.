// Contains Duplicates : https://leetcode.com/problems/contains-duplicate/

// Brute Force : 
// For each element, check if the duplicate exists.
// TC : O(n * n), SC : O(1)

// HashSet Based Approach
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for(int i = 0; i < nums.length; i++) {
            if(set.contains(nums[i])) 
                return true;
            else 
                set.add(nums[i]);
        }
        return false;
    }
}

// TC : O(n)
// SC : O(n)
