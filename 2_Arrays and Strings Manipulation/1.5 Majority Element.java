// Majority Element - https://leetcode.com/problems/majority-element/submissions/1883026835/

// HashMap Approach :
class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length == 0) return 0;

        HashMap<Integer, Integer> count = new HashMap<>();

        for(int i : nums) {
            count.put(i, count.getOrDefault(i, 0) + 1);
        }

        for(Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if(entry.getValue() > nums.length/2) {
                return entry.getKey();
            }
        }
        return 0;
    }
}

// TC : O(n)
// SC : O(n)

// Boyer - Moore Voting Approach : 
class Solution {
    public int majorityElement(int[] nums) {
        int element = 0; int count = 0;

        for(int i = 0; i < nums.length; i++) {
            if(count == 0) {
                element = nums[i];
                count = 1;
            } else if(nums[i] == element) {
                count ++;
            } else if(nums[i] != element) {
                count --;
            } 
        } 
        
        int count_2 = 0;
        for(int i : nums) {
            if(i == element) {
                count_2 ++;
            }
        }

        if(count_2 > nums.length/2) return element;
        return 0;
    }
}

// TC : O(n)
// SC : O(1)

// Dry runs :
// nums = [3, 2, 3] 
// int element = 0; int count = 0

// element = 3, count = 1
// element != 3, count = 0
// element = 3, count = 1

// Count the frequency of element 1. 
// If the frequency is more than n/2, return
// SC : O(1)
