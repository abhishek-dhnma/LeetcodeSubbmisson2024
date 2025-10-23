class Solution {
public:
int n;
int m;  


    vector<vector<int>> dp;

    int  solve(int i, int j, string &w1, string& w2){

        // bases cases

        if (i == n){
            return m -j;
        }

        if(j == m){
            return n-i;
        }

        // check if precomputed

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // recur fun

        // if both char are same

        if(w1[i] == w2[j]) return dp[i][j] =  solve(i+1, j+1, w1, w2);



        // if they are matacjiong

        int ins = 1 + solve(i, j+1, w1, w2);
        int d = 1 + solve(i+1, j, w1, w2);
        int r = 1 + solve(i+1, j+1, w1, w2);


        return dp[i][j] = min({ins, d, r});
    }

    int minDistance(string w1, string w2) {

        n = w1.size();
        m = w2.size();

       dp.assign(n+1, vector<int>(m+1, -1));

       return solve(0, 0, w1, w2 );
        
    }
};