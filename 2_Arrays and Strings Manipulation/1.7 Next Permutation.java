// Next Permutation - https://leetcode.com/problems/next-permutation/

// Brute Force Approach : 
// Generate all the permuations in the order - O(n!). Store them in the list.
// Linear Search of the input 
// Fetch the next element 

// TC : O(n!), SC : O(n)

// Optimised Approach :
// Prefix match based approach : 
// To only deal with all the next permutations of the given number.
class Solution {
    public void nextPermutation(int[] nums) {
        int breakingPoint = -1; // most important set up

        // Step 1 : Find the breaking point index
        for(int i = nums.length - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                breakingPoint = i;
                break;
            }
        }

        // Step 2 : Swap the element at breakingPoint index with the index of the element that is next closest
        if(breakingPoint != -1) {
            for(int i = nums.length - 1; i >= breakingPoint + 1; i--) {
                if(nums[breakingPoint] < nums[i]) {
                    int temp = nums[breakingPoint];
                    nums[breakingPoint] = nums[i];
                    nums[i] = temp;
                    break; // Only once - most important
                }
            }
        }

        // Step 3 : Sort the remaining portion other than prefix to get the next permutation
        int start = breakingPoint + 1; int end = nums.length - 1;
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start ++; end--;
        }
    }
}

// TC : O(n)
// SC : O(1)

