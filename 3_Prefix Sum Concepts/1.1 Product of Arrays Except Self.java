// Product of Array Except Self - https://leetcode.com/problems/product-of-array-except-self/submissions/1883667533/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] productExceptSelf = new int[nums.length];
        productExceptSelf[0] = 1;

        for(int i = 1; i < nums.length; i++) {
            // Remember but know the reasoning behind.
            productExceptSelf[i] = productExceptSelf[i - 1] * nums[i - 1]; 
        }

        int suffixProduct = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            // Remember but know the reasoning behind
            productExceptSelf[i] = productExceptSelf[i] * suffixProduct;
            suffixProduct *= nums[i];
        }

        return productExceptSelf;
    }
}

// TC : O(n)
// SC : O(1)
