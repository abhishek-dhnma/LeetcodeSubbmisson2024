class Solution {
public:

    vector<vector<int>> dir = {{1,0}, {0,1}}; // D R 

    int dp[101][101];

    int dfs(vector<vector<int>>& obstacleGrid, int n, int m, int i, int j){


        // base case and last cell also obstacle cell
        if(i == n-1 && j == m-1 && obstacleGrid[i][j] != 1){
            return 1;
        }

        // if any cell is obstacle cell return from there
        if(obstacleGrid[i][j] ==1){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }


        int ways = 0;
        for(auto & d : dir){

            int i_ = i + d[0]; 
            int j_ = j + d[1];


            if(i_ >= 0 && i_ <n && j_ >= 0 && j_ < m ){
                ways += dfs(obstacleGrid, n, m, i_, j_);
            }


        }

        return dp[i][j] = ways;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {


        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        memset(dp, -1, sizeof(dp));
        
        return dfs(obstacleGrid, n, m, 0, 0);

        
    }
};