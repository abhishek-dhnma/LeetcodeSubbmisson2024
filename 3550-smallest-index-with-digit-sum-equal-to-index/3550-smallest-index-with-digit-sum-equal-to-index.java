class Solution {
    public int smallestIndex(int[] nums) {

        int ans = Integer.MAX_VALUE;

        for(int i=0; i<nums.length; i++){
            int n = nums[i];
            int dsum = 0;
            while(n > 0){
                int d = n%10;
                dsum += d;
                n/=10;
            }

            if(dsum == i){
                ans = Math.min(ans, i);
            }

        }

        return (ans == Integer.MAX_VALUE) ? -1 : ans ;    
    }

}