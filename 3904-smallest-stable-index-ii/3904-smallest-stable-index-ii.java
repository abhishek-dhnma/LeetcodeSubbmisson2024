class Solution {
    public int firstStableIndex(int[] nums, int k) {

        int n  = nums.length;

        int[] mn = new int[n];

        mn[n-1] = nums[n-1];

        for(int j=n-2;  j>=0; j--){

            mn[j] = Math.min(mn[j+1], nums[j]);
        }

        int mx = nums[0];

        for(int i=0; i<n; i++){

            mx = Math.max(nums[i], mx);


            if( k >= (mx - mn[i])){
                return i;
            }
        }

        return -1;
        
    }
}