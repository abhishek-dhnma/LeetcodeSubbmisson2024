class Solution {
public:
    int n, m;

    int dp[501][501];

    int solve(string& s1, string& s2, int i, int j) {

        // base cases

        if (i == n) {

            return m - j;
        }

        if (j == m) {

            return n - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // recurion

        int rep=0, ins=0, del=0;
        if (s1[i] != s2[j]) {
            rep = 1 + solve(s1, s2, i + 1, j + 1);

            ins = 1 + solve(s1, s2, i, j + 1);

            del = 1 + solve(s1, s2, i + 1, j);

        } else {
            return dp[i][j] = solve(s1, s2, i + 1, j + 1);
        }

        return dp[i][j] = min({ins, del, rep});
    }
    int minDistance(string s1, string s2) {

        // both are equal we don't need any operations

        n = s1.size();
        m = s2.size();

        if (s1 == s2) {
            return 0;
        }
        memset(dp, -1, sizeof(dp));

        return solve(s1, s2, 0, 0);
    }
};