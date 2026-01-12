// First Missing Positive : https://leetcode.com/problems/first-missing-positive/editorial/

class Solution {
    public int firstMissingPositive(int[] nums) {
        // Place all the valid elements in their correct index
        for(int i = 0; i < nums.length; i++) {
            while(nums[i] > 0 && nums[i] <= nums.length && nums[nums[i] - 1] != nums[i]) {
                int targetIdx = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[targetIdx];
                nums[targetIdx] = temp;
            }
        }

        // Check for the first missing positive
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.length + 1;
    }
}

// TC : O(n)
// SC : O(1)

