class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int solve(string & s1, string & s2, int i, int j) {

        // base cases
        if (i == n || j == m) {
            return 0;
        }


        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // recursions

        int result = 0;
        if (s1[i] == s2[j]) {
            // matching
            result =  1 + solve(s1, s2, i + 1, j + 1);
        } else {
            // not matching
            result = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));
        }

        return dp[i][j] = result;
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();

        memset(dp, -1, sizeof(dp));

        return solve(text1, text2, 0, 0);
    }
};