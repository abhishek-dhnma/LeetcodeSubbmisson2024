class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> gridDP(n+1 , vector<int>(m+1, 0));

        if(obstacleGrid[0][0] == 1) return 0;

        gridDP[0][0] = 1;


        // fill coloum

        for(int c=1; c<m; c++){
            if(obstacleGrid[0][c] == 1){
                gridDP[0][c] = 0;
            }else{
                gridDP[0][c] = gridDP[0][c-1];
            }

        }

        // fill rows

        for(int r=1; r<n; r++){
            if(obstacleGrid[r][0] == 1){
                gridDP[r][0] = 0;
            }else{
                gridDP[r][0] = gridDP[r-1][0];
            }
        }

        // fill gridDP matrix

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){

                if(obstacleGrid[i][j] == 1){
                    gridDP[i][j] = 0;
                }else{
                    gridDP[i][j] = gridDP[i-1][j] + gridDP[i][j-1];
                }
            }
        }

        return gridDP[n-1][m-1];
        
    }
};