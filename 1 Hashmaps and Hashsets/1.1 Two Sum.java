// Important map/set inbuilt functions :

// map.put(key, value);
// map.containsKey(element);
// map.get(element);


// Two Sum -  https://leetcode.com/problems/two-sum/

// Bruteforce Approach - Nested Loops Based 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];

        for(int i = 0; i < nums.length; i++) {
            for(int j = i + 1; j < nums.length; j++) {
                if(nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        return result;
    }
} 

// TC : O(n * n) : O(n ^ 2) - Least Efficient TC
// SC : O(2)

// Better Approach - Hashmap Based
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];

        Map<Integer, Integer> seen = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            seen.put(nums[i], i);
        }

        for(int i = 0; i < nums.length; i++) {
            int remaining = target - nums[i];

            if(seen.containsKey(remaining) && seen.get(remaining) != i) {
                result[0] = i;
                result[1] = seen.get(remaining);
            }
        }
        return result;
    }
} 

// TC : O(n) + O(n) = O(2n) // O(n)
// SC : O(n)

