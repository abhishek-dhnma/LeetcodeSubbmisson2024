class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // Count how many numbers fall into each remainder bucket [0..value-1]
        vector<long long> cnt(value, 0);
        for (long long x : nums) {
            // normalize negative mods
            int r = (int)((x % value + value) % value);
            cnt[r]++;
        }

        // Greedily try to form 0,1,2,... in order.
        // For i, we need a number from bucket (i % value).
        // If the bucket has stock, consume one and move on.
        for (long long i = 0;; ++i) {
            int r = (int)(i % value);
            if (cnt[r] > 0) {
                cnt[r]--;
            } else {
                return (int)i; // first i we cannot form => MEX
            }
        }
    }
};
