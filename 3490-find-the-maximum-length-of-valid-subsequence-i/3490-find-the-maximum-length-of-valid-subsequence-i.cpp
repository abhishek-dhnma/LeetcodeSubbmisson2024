class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        
        int sameParity = 1;  // longest subsequence with same parity
        int diffParity = 1;  // longest subsequence with alternating parity

        int lastSame = nums[0];
        int lastDiff = nums[0];

        for (int i = 1; i < n; ++i) {
            // For same parity
            if (nums[i] % 2 == lastSame % 2) {
                sameParity++;
                lastSame = nums[i];
            }

            // For alternating parity
            if (nums[i] % 2 != lastDiff % 2) {
                diffParity++;
                lastDiff = nums[i];
            }
        }

        return max(sameParity, diffParity);
    }
};
