// Majority Element - https://leetcode.com/problems/majority-element/submissions/1883026835/

class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int element = 0;

        for(int i = 0; i < nums.length; i++) {
            if(count == 0) {
                element = nums[i];
                count++;
            } else if(nums[i] == element) {
                count++;
            } else if(nums[i] != element) {
                count--;
            }
        } 

        int count_1 = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] == element) {
                count_1 ++;
            }
        }

        if(count_1 > nums.length / 2) {
            return element;
        }

        return 1;
    }
}

// TC : O(n)
// SC : O(1)
