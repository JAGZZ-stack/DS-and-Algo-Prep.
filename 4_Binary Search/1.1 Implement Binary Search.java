// Standard Binary Search Algorithm : https://leetcode.com/problems/binary-search/

// Intuitive Approach : 
// Linear Search - TC : O(n), SC : O(1)

// Optimised Approach : 
class Solution {
    public int search(int[] nums, int target) {
        int low = 0; 
        int high = nums.length - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
}

// TC : O(log n)
// SC : O(1)
