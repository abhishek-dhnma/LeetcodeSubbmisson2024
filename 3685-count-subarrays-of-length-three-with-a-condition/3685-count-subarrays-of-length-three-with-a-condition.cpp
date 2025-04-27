class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = i + 2;
            if (j < n && k < n) {
                if (nums[i] + nums[k] == nums[j] / 2.0) {
                    count++;
                }
            }
        }

        return count;
    }
};