// Majority Element ii - https://leetcode.com/problems/majority-element-ii/submissions/1883052777/

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> list = new ArrayList<>();
        if (nums.length == 0) return list;

        int count_1 = 0;
        int element_1 = 0;
        int count_2 = 0;
        int element_2 = 0;

        for (int i = 0; i < nums.length; i++) {
            // 1. First, check if the number matches an existing candidate
            if (nums[i] == element_1) {
                count_1++;
            } else if (nums[i] == element_2) {
                count_2++;
            } 
            // 2. Only if it matches neither, check if a slot is empty
            else if (count_1 == 0) {
                element_1 = nums[i];
                count_1 = 1;
            } else if (count_2 == 0) {
                element_2 = nums[i];
                count_2 = 1;
            } 
            // 3. If it's a completely new number, decrement BOTH counters
            else {
                count_1--;
                count_2--;
            }
        } 

        // Verification pass
        int count_3 = 0;
        int count_4 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == element_1) {
                count_3++;
            } else if (nums[i] == element_2) {
                count_4++;
            }
        }

        // Fix: Check each candidate separately
        if (count_3 > nums.length / 3) {
            list.add(element_1); 
        }
        if (count_4 > nums.length / 3) {
            list.add(element_2);
        }

        return list;
    }
}
