class Solution {
public:

    int BinarySearch(vector<int>& nums, int n, int target){
        int left = 0;
        int right = n-1;

        int result = n;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                result = mid;
                right = mid - 1; // right
            }else{
                left = mid +1; // left
            }
        }

        return result;
    }

    int maximumCount(vector<int>& nums) {

        int totalElements = nums.size();
        
        int firstZeroidx = BinarySearch(nums, totalElements, 0);
        int firstPositiveidx = BinarySearch(nums, totalElements, 1) ;

 

        int zeroCount = firstPositiveidx - firstZeroidx;
        
        int negativecount = firstZeroidx;

        int positivecount = totalElements - firstPositiveidx;

        return max(positivecount, negativecount);

        
    }
};