// Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// Brute Force Approach : 
// class Solution {
//     public int removeDuplicates(int[] nums) {
//         HashSet<Integer> set = new LinkedHashSet<>(); // To preserve the orders (LinkedHashSet)

//         for(int val : nums) {
//             if(!set.contains(val)) {
//                 set.add(val);
//             }
//         }

//         int i = 0;
//         for(int val : set) {
//             nums[i] = val;
//             i++;
//         }

//         return i;
//     }
// }

// TC : O(n)
// SC : O(n)


// Optimised Approach :
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0) return 0;

        // Concept of slow and fast pointers
        int i = 1; // The index at which the next unique element needs to be placed 
        int previousElement = nums[0];

        for(int j = 1; j < nums.length; j++) {
            if(nums[j] != previousElement) {
                nums[i] = nums[j];
                previousElement = nums[i];
                i++;
            }
        }

       return i;
    }
}

// TC : O(n)
// SC : O(1)
