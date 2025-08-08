class Solution {
public:
    vector<vector<int>> dir = {{100,0}, {75,25}, {50,50}, {25,75}};

    double solve(int a , int b, vector<vector<double>> & dp){


        // base cases

        if(a <= 0 && b > 0){
            return 1.0;
        }

         if(a <= 0 && b <= 0){
            return 0.5;
        }
        if(a>0 && b <= 0){
            return 0.0;
        }

        if(dp[a][b] != -1.0) {
            return dp[a][b];
        }



        double total = 0.0;
        for(auto& d : dir){
            int x = a - d[0];
            int y = b - d[1];

            total += solve(x, y, dp);
        }


        return dp[a][b] = total/4;


    }

    double soupServings(int n) {
    if(n > 5000) return 1;

    vector<vector<double>> dp(n+1, vector<double>(n+1, -1.0));
    return solve(n, n, dp);
        
    }
};