class Solution {
public:
    // Top-Down : LIS : longest Increasing Subsequence

    int n;
    int dp[2501][2501];

    int findLIS(vector<vector<int>>& pairs, int curridx, int preidx) {

        if (curridx >= n) {
            return 0;
        }

        if (preidx != -1 && dp[preidx][curridx] != -1) {
            return dp[preidx][curridx];
        }

        int take_include = 0;
        if (preidx == -1 || pairs[preidx][1] < pairs[curridx][0]) {
            take_include = 1 + findLIS(pairs, curridx + 1, curridx);
        }

        int skip_exclude = findLIS(pairs, curridx + 1, preidx);

        if (preidx != -1) {
            dp[preidx][curridx] = max(take_include, skip_exclude);
        }

        return max(take_include, skip_exclude);
    }

    int findLongestChain(vector<vector<int>>& pairs) {

        // Top-Down Approach
        n = pairs.size();
        int curridx = 0;
        int preidx = -1;
        memset(dp, -1, sizeof(dp));

        // sorting
        sort(pairs.begin(), pairs.end());
        return findLIS(pairs, curridx, preidx);
    }
};