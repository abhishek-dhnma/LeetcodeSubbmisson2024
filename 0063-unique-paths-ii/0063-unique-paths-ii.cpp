class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> gridDP(n+1, vector<int>(m+1, -1));

        // fill first Coloumn

        for(int c=0; c<m; c++){
            
            if( c >= 1 && obstacleGrid[0][c-1] == 1){
                gridDP[0][c] = 0;
                obstacleGrid[0][c] = 1;
            }else if(obstacleGrid[0][c] == 1 ){
                    gridDP[0][c] = 0;
            }else{
                    gridDP[0][c] = 1;
            }

        } 


        // fill first Row

         for(int r=0; r<n; r++){
            
            if( r >= 1 && obstacleGrid[r-1][0] == 1){
                gridDP[r][0] = 0;
                obstacleGrid[r][0] = 1;
            }else if(obstacleGrid[r][0] == 1){
                    gridDP[r][0] = 0;
            }else{
                    gridDP[r][0] = 1;
            }

        } 


        // fill gridDP

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){

                if(obstacleGrid[i][j] == 1 ){
                    gridDP[i][j] = 0;
                }else {
                    gridDP[i][j] = gridDP[i][j-1] + gridDP[i-1][j];
                }

            }
        }


        return gridDP[n-1][m-1];

        
    }
};