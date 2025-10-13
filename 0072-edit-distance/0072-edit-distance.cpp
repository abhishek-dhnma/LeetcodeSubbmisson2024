class Solution {
public:
    int n, m;

    vector<vector<int>> dp;

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

        // recurion - just move forward and explore next characters
        if(s1[i] == s2[j]) return dp[i][j] = solve(s1, s2, i + 1, j + 1);

        int rep=0, ins=0, del=0;

            rep = 1 + solve(s1, s2, i + 1, j + 1);

            ins = 1 + solve(s1, s2, i, j + 1);

            del = 1 + solve(s1, s2, i + 1, j);

        return dp[i][j] = min({ins, del, rep});
    }
    int minDistance(string s1, string s2) {

        // both are equal we don't need any operations

        n = s1.size();
        m = s2.size();

        if (s1 == s2) {
            return 0;
        }

        dp.assign(n+1, vector<int>(m+1,-1));

        return solve(s1, s2, 0, 0);
    }
};