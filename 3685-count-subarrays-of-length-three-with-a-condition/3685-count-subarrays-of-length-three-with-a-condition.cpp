class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = i + 2;
            if (j < n && k < n) {
                if ((double)nums[i] + nums[k] == (double)nums[j] / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};