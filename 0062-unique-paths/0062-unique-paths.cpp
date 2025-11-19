class Solution {
public:

    vector<vector<int>> dir = {{1,0}, {0,1}}; // D R
    int dp[101][101];

    int dfs(int m, int n, int i, int j){


        // base case destination
        if(i==m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ways = 0;
        for(auto& d : dir){
            int i_ = i + d[0];
            int j_ = j + d[1];

            if(i_ >= 0 && i_ <m && j_ >=0 && j_ <n){
               ways += dfs(m, n, i_, j_);
            }
        }

        return dp[i][j] = ways;

    }

    int uniquePaths(int m, int n) {

        memset(dp, -1, sizeof(dp));
        return dfs(m, n , 0, 0);
        
    }
};