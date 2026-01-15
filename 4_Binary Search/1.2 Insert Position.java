// Search Insert Position : https://leetcode.com/problems/search-insert-position/submissions/1885869270/

// Brute Force Approach : 
// Linear Search
// TC : O(n), SC : O(1)

class Solution {
    public int searchInsert(int[] nums, int target) {
        if(nums.length == 0) return 0;

        int low = 0;
        int high = nums.length - 1;
        int sol = nums.length;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) {
                sol = mid;
                return sol;
            } else if(nums[mid] < target) {
                low = mid + 1;
            } else {
                sol = mid;
                high = mid - 1;
            }
        }

        return sol;
    }
} // TC : O(log n), SC : O(1)

// Dry runs :
// nums = [1, 3, 5, 6] target = 4

// low = 0; high = 3; sol = nums.length

// while(low <= high) :
    // mid = 1
    // 3 < 4;
    // low = 2;

    // mid = 2
    // 5 > 4
    // sol = 2;
    // high = 1

    // Loop Breaks

// return sol;
