// Group Anagrams - https://leetcode.com/problems/group-anagrams/
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for(int i = 0; i < strs.length; i++) {
            char[] charArray = strs[i].toCharArray(); // Convert to charArray
            Arrays.sort(charArray); // Perform Sorting
            String sortedString = new String(charArray); // Convert back to String

            if (!map.containsKey(sortedString)) {
                map.put(sortedString, new ArrayList<>());
            }

            map.get(sortedString).add(strs[i]);

        } 

        return new ArrayList<>(map.values());
    }
}

// TC : O(n)
// SC : O(n)
