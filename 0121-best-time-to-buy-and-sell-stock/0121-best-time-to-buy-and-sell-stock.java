class Solution {
    public int maxProfit(int[] prices) {
         int n = prices.length;

        int[] temparr = new int[n];

        temparr[n-1] = prices[n-1];

        for(int i=n-2; i>=0; i--){
            temparr[i] =Math.max(prices[i], temparr[i+1]) ;

        }
        int maxProfit = 0;

        for(int i=0; i<n; i++){
            int profit = temparr[i] - prices[i];
            maxProfit = Math.max(maxProfit, profit);
        }
       

        return maxProfit;
        
        
    }
}