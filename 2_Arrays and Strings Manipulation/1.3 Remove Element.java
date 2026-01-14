// Remove Element - https://leetcode.com/problems/remove-element/submissions/1881895023/

// Brute Force :
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums.length == 0) return 0;

        HashMap<Integer, Integer> map = new LinkedHashMap<>();

        for(int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        int j = 0;
        for(Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if(entry.getKey() != val) {
                for(int i = 0; i < entry.getValue(); i++) {
                    nums[j] = entry.getKey();
                    j++;
                }
            }
            
        }

        return j;
    }
}

// TC : O(n)
// SC : O(n)

// Optimised Approach : 
class Solution {
    public int removeElement(int[] nums, int val) {
        if(nums.length == 0) return 0;
        
        int i = 0; // Index at which the next non-val element should be placed

        for(int j = 0; j < nums.length; j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
}

// TC : O(n) 
// SC : O(1)
