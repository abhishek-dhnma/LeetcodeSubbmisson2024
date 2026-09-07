class Solution {

    int M = (int)1e9+7;
    int[] dp = new int[2001];
    int[] prev;


    public int solve(int n){

        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        int total = (solve(n-1) * 2) % M;

        if(prev[n] != 0){
            int duplicates = solve(prev[n] - 1);
            total = (total - duplicates + M) % M;
        }

        return dp[n] = total;

    }

    
    public int distinctSubseqII(String s) {

    int n = s.length();
    Arrays.fill(dp, -1);

    prev = new int[n+1];

    int[] lastseen  = new int[26];

    for(int i =1; i<= n; i++){
        int idx = s.charAt(i-1) - 'a';

        prev[i] = lastseen[idx];
        lastseen[idx] = i;

    }

    return (solve(n) - 1 + M) % M;

        
    }
}