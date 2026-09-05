class Solution {
    public int firstStableIndex(int[] nums, int k) {

        int n  = nums.length;

        int[] mx = new int[n];
        int[] mn = new int[n];

        mx[0] = nums[0];
        mn[n-1] = nums[n-1];



        for(int i=1,j=n-2; i<n && j>=0; i++, j--){
            mx[i] = Math.max(mx[i-1], nums[i]);
            mn[j] = Math.min(mn[j+1], nums[j]);
        }

        for(int i=0; i<n; i++){
            if( k >= (mx[i] - mn[i])){
                return i;
            }
        }

        return -1;
        
    }
}