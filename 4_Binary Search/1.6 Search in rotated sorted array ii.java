// Search in rotated sorted array ii - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Brute Force : 
// Linear Search : TC : O(n), SC : O(1)

// Modified Binary Search :
class Solution {
    public boolean search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            } else if (nums[low] == nums[mid] && nums[mid] == nums[high]) { 
                // Only scenario that does not tell us which side is sorted.
                low ++;
                high --;
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
        return false;
    }
}

// TC : O(log n)
// SC : O(1)
