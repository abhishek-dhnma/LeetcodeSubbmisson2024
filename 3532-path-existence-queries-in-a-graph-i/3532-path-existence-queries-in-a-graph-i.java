class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        
        int[] component = new int[n];
        Arrays.fill(component, -1);

        int compid = 0;
        component[0] = compid;

        for(int i=1; i<n; i++){

                if(Math.abs(nums[i] - nums[i-1]) > maxDiff){
                    compid++;
                }   

                component[i] = compid;

        }

        int x = queries.length;
        boolean[] ans = new boolean[x];

        for(int i=0; i<x; i++){
            int u = queries[i][0];
            int v =  queries[i][1];


            if(component[u] == component[v]){
                ans[i] = true;
            }
        }
        return ans;       
    }
}