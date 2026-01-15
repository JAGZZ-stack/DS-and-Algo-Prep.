// First missing positive - https://leetcode.com/problems/first-missing-positive/submissions/1886073542/

// Brute Force Approach : 

class Solution {
    public int firstMissingPositive(int[] nums) {
        for(int i = 1; i <= nums.length; i++) {
            int val = i;
            boolean isPresent = false;
            for(int j = 0; j < nums.length; j++) {
                if(nums[j] == val) {
                    isPresent = true;
                    break;
                }
            }
            if(!isPresent) return val;
        }

        return 0;
    }
}

// TC : O(n * n)
// SC : O(1)

class Solution {
    public int firstMissingPositive(int[] nums) {
        // Step 1 : Place all the valid elements of the array at the right index
        for(int i = 0; i < nums.length; i++) {
            while(nums[i] >= 1 && nums[i] <= nums.length && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[temp - 1] = temp; // Very important 
            }
        }

        // Step 2 : Check for the first mismatch
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
