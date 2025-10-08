class Solution {
public:
    int n, m;
    int dp[1001][1001]; // DP table: dp[i][j] stores LCS length of s1[i:] and s2[j:]

    // Recursive helper function with memoization
    int solve(const string& s1, const string& s2, int i, int j) {
        // Base case: if any string is fully traversed, LCS length = 0
        if (i == n || j == m) return 0;

        // Reference to dp cell (to avoid typing dp[i][j] repeatedly)
        int &memo = dp[i][j];

        // If result already computed, return it
        if (memo != -1) return memo;

        // If characters match, include it in LCS and move both indices forward
        if (s1[i] == s2[j]) {
            memo = 1 + solve(s1, s2, i + 1, j + 1);
        }
        // If characters don't match, take the best of:
        // - skipping one character from s1
        // - skipping one character from s2
        else {
            memo = max(solve(s1, s2, i + 1, j),
                       solve(s1, s2, i, j + 1));
        }

        return memo;
    }

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size();
        m = text2.size();

        // Initialize dp with -1 (indicating uncomputed states)
        memset(dp, -1, sizeof(dp));

        // Start recursion from index 0 of both strings
        return solve(text1, text2, 0, 0);
    }
};
