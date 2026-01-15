// Sqrt (x) - https://leetcode.com/problems/sqrtx/

// Brute Force :
// Linear Search (from 1 to i * i <= n)
// TC : O(sqrt(n)), SC : O(1)

// Binary Search :
class Solution {
    public int mySqrt(int x) {
        if(x <= 1) return x;

        int low = 0;
        int high = x;
        int sol = x + 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if ((long) mid * mid == x) {
                sol = mid;
                return sol;
            } else if ((long) mid * mid < x) {
                sol = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return sol;
    }
}

// TC : O(log n)
// SC : O(1)
