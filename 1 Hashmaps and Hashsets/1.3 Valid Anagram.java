// Valid Anagram - https://leetcode.com/problems/valid-anagram/

// Sort and Compare
public class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        char[] sSort = s.toCharArray();
        char[] tSort = t.toCharArray();
        Arrays.sort(sSort);
        Arrays.sort(tSort);
        return Arrays.equals(sSort, tSort);
    }
}

// TC : O(n * log n)
// SC : O(1)

// Hashmap Based Approach
class Solution {
    public boolean isAnagram(String s, String t) {
        // Conditions to be met :
        // 1. Same length
        // 2. Same distinct characters
        // 3. Count of each distinct characters should be the same.

        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> count = new HashMap<>();

        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        int countDistinct = count.size(); // Very important setup

        for(int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);

            if(count.containsKey(c)) {
                count.put(c, count.getOrDefault(c, 0) - 1);
                if(count.get(c) == 0) {
                    countDistinct--;
                }
            }
        }

        if(countDistinct == 0) return true;
        return false;
    }
}

// TC : O(n)
// SC : O(n)
