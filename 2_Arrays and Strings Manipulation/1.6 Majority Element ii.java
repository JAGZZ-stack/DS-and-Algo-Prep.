// Majority Element ii - https://leetcode.com/problems/majority-element-ii/submissions/1883052777/

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> sol = new ArrayList<>();

        if(nums.length == 0) return sol;

        HashMap<Integer, Integer> count = new HashMap<>();

        for(int i : nums) {
            count.put(i, count.getOrDefault(i, 0) + 1);
        }

        for(Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if(entry.getValue() > nums.length/3) {
                sol.add(entry.getKey());
            }
        }
        return sol;
    }
}

// TC : O(n)
// SC : O(n)

class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> sol = new ArrayList<>();

        if(nums.length == 0) return sol;

        int candidate_1 = 0; int count_1 = 0;
        int candidate_2 = 0; int count_2 = 0;

        for(int i : nums) {
            // 1. Check if it matches an existing candidate first
            if (i == candidate_1) {
                count_1++;
            } else if (i == candidate_2) {
                count_2++;
            } 
            // 2. If not, check if a slot is empty
            else if (count_1 == 0) {
                candidate_1 = i;
                count_1 = 1;
            } else if (count_2 == 0) {
                candidate_2 = i;
                count_2 = 1;
            } 
            // 3. If it's a new number and slots are full, decrement BOTH
            else {
                count_1--;
                count_2--;
            }
        }

        int count_3 = 0, count_4 = 0;
        for(int i : nums) {
            if(i == candidate_1) {
                count_3 ++;
            } else if(i == candidate_2) {
                count_4 ++;
            }
        }

        if(count_3 > nums.length/3) {
            sol.add(candidate_1);
        } if(count_4 > nums.length/3) {
            sol.add(candidate_2);
        }

        return sol;
    }
}

// TC : O(n)
// SC : O(1)

