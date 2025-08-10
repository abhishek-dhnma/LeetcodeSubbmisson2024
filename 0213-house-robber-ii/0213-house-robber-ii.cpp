class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Case 1: Rob houses from index 0 to n-2 (exclude last house)
        vector<int> t1(n, 0);
        t1[0] = nums[0];
        if (n > 1) t1[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n - 1; i++) {
            int take = nums[i] + (i-2 >= 0 ? t1[i-2] : 0);
            int skip = t1[i-1];
            t1[i] = max(take, skip);
        }
        
        int res1 = (n == 2) ? t1[1] : t1[n-2];
        
        // Case 2: Rob houses from index 1 to n-1 (exclude first house)
        vector<int> t2(n, 0);
        t2[1] = nums[1];
        
        for (int i = 2; i < n; i++) {
            int take = nums[i] + (i-2 >= 1 ? t2[i-2] : 0);
            int skip = t2[i-1];
            t2[i] = max(take, skip);
        }
        
        int res2 = t2[n-1];
        
        // Return the maximum of the two cases
        return max(res1, res2);
    }
};