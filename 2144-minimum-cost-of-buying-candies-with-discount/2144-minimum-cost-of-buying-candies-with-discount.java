class Solution {
    public int minimumCost(int[] cost) {

        int n = cost.length;

        if(n == 0) return 0;

        if(n == 1) return cost[0];

        if(n == 2) return cost[0] + cost[1];

        Arrays.sort(cost);

        int minCost = 0 ;

        for(int i=n-1; i>=0; i-=2){

            if(i == 0) {
                minCost += cost[i];
            }else{
            
           minCost += (cost[i] + cost[i-1]);
           i--; 
            }

        }

        return minCost;
        
    }
}