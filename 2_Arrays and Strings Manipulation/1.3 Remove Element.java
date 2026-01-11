// Remove Element - https://leetcode.com/problems/remove-element/submissions/1881895023/

class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0; // Represents the index where the next unique element needs to be placed.

        for(int j = 0; j < nums.length; j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++; // Important setup for Slow and Fast Pointers 
            }
        }
        return i;
    }
}

// TC : O(n)
// SC : O(1)
