class Solution {
public:

    vector<vector<int>> dp2, dp3;

    int dfs2(vector<vector<int>>& fruits, int i, int j, int n) {

        if (i < 0 || j >= n || j < 0 || i >= n) {
            return 0;
        }

        if(dp2[i][j] != -1){
            return dp2[i][j];
        }

        int val = fruits[i][j];
        int res = 0;

        

        if (i == j) {

            res = max(res, dfs2(fruits, i + 1, j + 1, n));

        } else if (i == j - 1) {

            res =
                max(res, max(dfs2(fruits, i + 1, j, n), dfs2(fruits, i + 1, j + 1, n)));

        } else {
            res = max(dfs2(fruits, i + 1, j, n), max ( dfs2(fruits, i + 1, j + 1, n),
                      dfs2(fruits, i + 1, j - 1, n))

            );
        }

        return dp2[i][j] = res + val;
    }

    int dfs3(vector<vector<int>>& fruits, int i, int j, int n) {

        if (i < 0 || j >= n || j < 0 || i >= n) {
            return 0;
        }

        if(dp3[i][j] != -1){
            return dp3[i][j];
        }

        int val = fruits[i][j];
        int res = 0;

        if (i == j) {

            res = max(res, dfs3(fruits, i + 1, j + 1, n));

        } else if (i -1 == j ) {

            res =
                max(res, max(dfs3(fruits, i+1, j+1, n), dfs3(fruits, i , j + 1, n)));

        } else {
            res = max(dfs3(fruits, i - 1, j+1,n), max (dfs3(fruits, i , j + 1,n),
                      dfs3(fruits, i + 1, j + 1,n))

            );
        }

        return dp3[i][j] = res + val;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {

       int total = 0;

       int n = fruits.size();
        //child 1
       for(int i=0; i<n; i++){
        total += fruits[i][i];
        fruits[i][i] = 0;
       }

        dp2 = vector<vector<int>>(n, vector<int>(n, -1));
        dp3 = vector<vector<int>>(n, vector<int>(n, -1));

    //Child 2
        total += dfs2(fruits,0, n-1, n );
    //Child 3
       total += dfs3(fruits, n-1, 0, n );

       return total;
    }
};