// Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// HashSet Based Approach
class Solution {
    public int removeDuplicates(int[] nums) {
        Set<Integer> set = new LinkedHashSet<>();

        for(int val : nums) {
            if(!set.contains(val)) {
                set.add(val);
            }
        }

        int index = 0;
        for(int val : set) {
            nums[index] = val;
            index++;
        }

        return index;
    }
}

// TC : O(n)
// SC : O(n)

// Two Pointers Based Approach :
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 1; // Represents the index where the next unique element needs to be placed.
        int previousElement = nums[0];

        for(int j = 1; j < nums.length; j++) {
            if(nums[j] != previousElement) {
                nums[i] = nums[j];
                previousElement = nums[i];
                i++; // Important setup for Slow and Fast Pointers 
            }
        }

        return i;
    }
}

// TC : O(n)
// SC : O(1)

