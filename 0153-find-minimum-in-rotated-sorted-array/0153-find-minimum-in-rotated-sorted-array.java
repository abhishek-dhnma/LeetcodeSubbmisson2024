class Solution {
    public int findMin(int[] nums) {

        int n = nums.length;
        int r = n-1;
        int l = 0;

        while(l < r){
            int mid = l + (r-l)/2;

            if(nums[mid] < nums[r]){

                r = mid;

            }else{
                l = mid +1;
            }
        }


        //return nums[l]; both works - breaking condition when r == l -> break
        return nums[r];
    }
}