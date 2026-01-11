// Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence/submissions/1881598330/

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for(int val : nums) {
            set.add(val);
        }

        int result = 0;
        for(int val : set) { // Iterate over the set and not the array to avoid TLEs due to duplicates
            if(!set.contains(val - 1)) {
                int count = 1;
                int currentElement = val;

                while(set.contains(currentElement+1)) {
                    count++;
                    currentElement = currentElement+1;
                }

                result = Math.max(result, count);
            }
        }
        return result;
    }
}

// TC : O(n)
// SC : O(n)
