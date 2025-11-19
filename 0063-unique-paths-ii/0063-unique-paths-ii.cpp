class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // DP grid initialized with -1
        vector<vector<int>> gridDP(n+1, vector<int>(m+1, -1));

        // -------------------------
        // Fill FIRST ROW
        // -------------------------
        for(int c = 0; c < m; c++){

            // If previous cell in the same row had an obstacle,
            // then all cells after it in that row must be unreachable
            if(c >= 1 && obstacleGrid[0][c-1] == 1){
                gridDP[0][c] = 0;
                obstacleGrid[0][c] = 1; // mark current as blocked too
            }
            // If this current cell has an obstacle
            else if(obstacleGrid[0][c] == 1){
                gridDP[0][c] = 0;
            }
            // Otherwise path exists
            else{
                gridDP[0][c] = 1;
            }
        }

        // -------------------------
        // Fill FIRST COLUMN
        // -------------------------
        for(int r = 0; r < n; r++){

            // If previous cell in same column had obstacle,
            // then entire column below becomes unreachable
            if(r >= 1 && obstacleGrid[r-1][0] == 1){
                gridDP[r][0] = 0;
                obstacleGrid[r][0] = 1; // mark as blocked
            }
            // If this cell itself has obstacle
            else if(obstacleGrid[r][0] == 1){
                gridDP[r][0] = 0;
            }
            // Otherwise path exists
            else{
                gridDP[r][0] = 1;
            }
        }

        // -------------------------------------------
        // Fill the rest of the DP grid (bottom-up DP)
        // -------------------------------------------
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){

                // If current cell has obstacle -> no paths
                if(obstacleGrid[i][j] == 1){
                    gridDP[i][j] = 0;
                }
                // Otherwise paths = from left + from top
                else{
                    gridDP[i][j] = gridDP[i][j-1] + gridDP[i-1][j];
                }
            }
        }

        // Final cell contains total unique paths
        return gridDP[n-1][m-1];
    }
};
