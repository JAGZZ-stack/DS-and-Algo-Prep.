// Search in Rotated sorted array i - https://leetcode.com/problems/search-in-rotated-sorted-array/

// Brute force approach : 
// Linear Search - TC : O(n), SC : O(1)

// Optimised Approach :
// Modified Binary Search
class Solution {
    public int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[low] <= nums[mid]) { // The underlying reason is important
                if(nums[low] <= target && target < nums[mid]) { // The underlying reason is important
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if(nums[mid] < target && target <= nums[high]) { // The underlying reason is important
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
}

// TC : O(log n)
// SC : O(1)

