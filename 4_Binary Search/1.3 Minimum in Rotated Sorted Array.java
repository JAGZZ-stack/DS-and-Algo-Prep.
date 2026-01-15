// Minimum in Rotated Sorted Array - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Brute Force :
// Linear Search (find the smallest element in the array)
// TC : O(n), SC : O(1)

// Binary Search : 
class Solution {
    public int findMin(int[] nums) {
        if(nums.length == 0) return 0;

        int low = 0;
        int high = nums.length - 1;
        int sol = nums.length;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[nums.length - 1]) {
                low = mid + 1;
            } else {
                sol = nums[mid];
                high = mid - 1;
            }
        }

        return sol;
    }
} 
// TC : O(log n)
// SC : O(1)
