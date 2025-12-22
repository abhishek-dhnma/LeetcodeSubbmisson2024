class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int lis = 1;

        int r = strs.size();
        int c = strs[0].length();
 
        vector<int> dp(c, 1);

        // lis
        for (int i = 0; i < c; i++) { 
            for (int j = 0; j < i; j++) {

                bool validsafe = true;
                for (int k = 0; k < r; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        validsafe = false;
                        break;
                    }
                }

                if (validsafe) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            lis = max(lis, dp[i]);
        }

        return (c - lis);
    }
};