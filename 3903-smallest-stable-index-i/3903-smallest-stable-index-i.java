class Solution {
    public int firstStableIndex(int[] nums, int k) {

        int n = nums.length;

        int[] mx = new int[n];
        int[] mn = new int[n];

        mx[0] = nums[0];
        mn[n-1] = nums[n-1];

        for(int i=1; i<n; i++){

            mx[i] = Math.max(mx[i-1], nums[i]);

        }

        for(int i=n-2; i>=0; i--){

            mn[i] = Math.min(mn[i+1], nums[i]);

        }

        int ans = -1;
        for(int i=0; i<n; i++){
            
            if(k >= (mx[i] - mn[i])){
                return i;
            }

        }

        return ans;
         
        
    }
}