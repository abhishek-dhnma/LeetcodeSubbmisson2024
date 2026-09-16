class Solution {

    public int M = (int) 1e9+7;
    

    public int numberOfSets(int n, int k) {

        int[][] dp = new int[k+1][n+1];

        for(int i=0; i<=n-1; i++){
            dp[0][i] = 1;
        }


        for(int K = 1; K<= k; K++){

            int[] prevRowSum = new int [n+1];
            
            for(int x = n-1; x>=0; x--){
                prevRowSum[x] = (prevRowSum[x+1] + dp[K-1][x]) % M;
            }

            for(int i = n-1; i>=0 ;i--){

                int take = prevRowSum[i+1];

                int skip = dp[K][i+1] % M;

                dp[K][i] = (take + skip) % M;

            }
        }

        return  dp[k][0];

        
    }
}