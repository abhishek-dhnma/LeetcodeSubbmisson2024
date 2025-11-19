class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // DP array of same size as grid
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // If starting cell is blocked → no paths possible
        if(obstacleGrid[0][0] == 1) return 0;

        dp[0][0] = 1;   // Starting position has exactly 1 way to be reached

        // -------------------------
        // Fill first row
        // -------------------------
        for(int j = 1; j < m; j++) {

            // If cell has obstacle → 0 ways
            if(obstacleGrid[0][j] == 1)
                dp[0][j] = 0;

            // Otherwise, it can only come from left
            else
                dp[0][j] = dp[0][j-1];
        }

        // -------------------------
        // Fill first column
        // -------------------------
        for(int i = 1; i < n; i++) {

            // If obstacle → 0 ways
            if(obstacleGrid[i][0] == 1)
                dp[i][0] = 0;

            // Otherwise, it can only come from top
            else
                dp[i][0] = dp[i-1][0];
        }

        // -------------------------
        // Fill the rest of the grid
        // -------------------------
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                // If obstacle → no paths
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;

                // Otherwise sum of top + left
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        // Bottom-right cell gives final answer
        return dp[n-1][m-1];
    }
};
