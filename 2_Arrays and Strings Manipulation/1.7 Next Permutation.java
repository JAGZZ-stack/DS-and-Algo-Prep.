// Next Permutation - https://leetcode.com/problems/next-permutation/

class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            swap(nums, start++, end--);
        }
    }

    public void nextPermutation(int[] nums) {
        int n = nums.length;

        // 1. Find the rightmost pivot
        for(int i = n - 1; i >= 1; i--) {
            if(nums[i] > nums[i - 1]) {
                index = i - 1;
                break;
            }
        }

        // 2. If index is -1, the array is in descending order (last permutation)
        // Just reverse the whole thing to get the first permutation.
        if (index != -1) {
            // Find the successor (the number to swap with index)
            for (int i = n - 1; i > index; i--) {
                if (nums[i] > nums[index]) {
                    swap(nums, i, index);
                    break;
                }
            }
        }

        // 3. Reverse the suffix (everything after index)
        reverse(nums, index + 1, n - 1);
    }
}

// TC : O(n)
// SC : O(1)
