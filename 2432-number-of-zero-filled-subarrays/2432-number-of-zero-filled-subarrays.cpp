class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;  // Start of current run of 0s
        int j = 0;  // Current index to scan array
        long long count = 0;  // Total number of subarrays

        while (j < n) {
            if (nums[j] == 0) {  // Start of a run of 0s
                i = j;  // Mark start of run
                while (j < n - 1 && nums[j + 1] == 0) {  // Extend run until non-0 or end
                    j++;
                }
                int s = j - i + 1;  // Length of current run (m_i)
                count += (s * (long long)(s + 1)) / 2;  // Add subarrays: m_i * (m_i + 1) / 2
            }
            j++;  // Move to next potential run
        }

        return count;
    }
};