Important map/set inbuilt functions :

map.put(key, value); // Build the map
map.containsKey(element); // Check if map contains the key
map.get(element); // Get the value for one Key in the map

// Change the value of one key in the map
if(map.containsKey(element)) {
    map.put(c, map.getOrDefault(c, 0) + 1); 
}

// Adding the list of values for one particular Key
if (!map.containsKey(sortedString)) {
        map.put(sortedString, new ArrayList<>());
    } // Performing this only if the key is not present
    
    map.get(sortedString).add(strs[i]);

map.get(sortedString).add(strs[i]); 

// -----------------------------------------------------------------------------------------------
set.add(element) // Add an element into the set
if(set.contains(element)) // Check if the set contains one particular element

// ------------------------------------------------------------------------------------------------
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

