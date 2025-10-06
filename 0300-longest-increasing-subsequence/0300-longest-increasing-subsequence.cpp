class Solution {
public:
    int n;

    int findLIS(vector<int>& nums, int currentIndex, int prevIndex, vector<vector<int>>& dp) {
        // base case: reached end of array
        if (currentIndex >= n) {
            return 0;
        }

        // use memoized value if available
        if (prevIndex != -1 && dp[currentIndex][prevIndex] != -1) {
            return dp[currentIndex][prevIndex];
        }

        // option 1: include current element (if it's increasing)
        int include = 0;
        if (prevIndex == -1 || nums[prevIndex] < nums[currentIndex]) {
            include = 1 + findLIS(nums, currentIndex + 1, currentIndex, dp);
        }

        // option 2: skip current element
        int exclude = findLIS(nums, currentIndex + 1, prevIndex, dp);

        // store result in dp if prevIndex is valid
        if (prevIndex != -1) {
            dp[currentIndex][prevIndex] = max(include, exclude);
        }

        return max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        if (n == 0) return 0;

        // dp[i][j] stores LIS starting from index i with previous index j
        // initialized to -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return findLIS(nums, 0, -1, dp);
    }
};
