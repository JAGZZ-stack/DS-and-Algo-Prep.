// Sort Colors - https://leetcode.com/problems/sort-colors/submissions/1882002318/

// Frequency Counting & Partitioning
// Two Pass // TC : O(n), SC : O(n)

// Dutch National Flag (Three Pointers Approach) :
// We define three invariant boundaries in the array. At any point during the process, the array is divided into four mathematical zones:

// Zone 1 : [0...low - 1] -> All the elements are 0
// Zone 2 : [low...mid - 1] -> All the elements are 1
// Zone 1 : [mid...high] -> Elements are Unknown (to be processed).
// Zone 1 : [high + 1...n - 1] -> All the elements are 2

class Solution {
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public void sortColors(int[] nums) {
        int low = 0;
        int mid = 0;
        int high = nums.length - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Found a 0: Swap it to the 'low' section
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Found a 1: It's already in the middle, just move on
                mid++;
            } else {
                // Found a 2: Swap it to the 'high' section
                swap(nums, mid, high);
                high--;
                // Note: We DON'T increment mid here because the swapped 
                // element from 'high' hasn't been checked yet!
            }
        }
    }
}

// TC : O(n)
// SC : O(1)
