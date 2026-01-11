// Top K Frequent Elements - https://leetcode.com/problems/top-k-frequent-elements/submissions/1881623104/

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap();

        for(int val : nums) {
            count.put(val, count.getOrDefault(val, 0) + 1);
        }

        // 2. Convert Map Entries to a List so we can sort them
        // entrySet() gives us a list of "Key-Value" pairs
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(count.entrySet());

        // 3. Sort the list based on the "Value" (Frequency) in descending order
        // This is like saying: "Compare pair B and pair A, and put the larger one first"
        list.sort((a, b) -> b.getValue() - a.getValue());

        // 4. Create the result array list and pick the top K keys
        int[] result = new int[k];
        int i = 0;
        for(Map.Entry<Integer, Integer> entry : list) {
            if (i >= k) break; // Stop once we have filled K elements
            result[i] = entry.getKey();
            i++;
        } 

        return result;
    }
}

// TC : O(n)
// SC : O(n)

// pair<int, int>	Map.Entry<Integer, Integer>	- A single Key-Value pair.
// it.first	        entry.getKey()	- Grab the number.
// it.second	    entry.getValue() - Grab the frequency.
