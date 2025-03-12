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
                right = mid - 1; 
            }else{
                left = mid +1;
            }
        }

        return result;
    }

    int maximumCount(vector<int>& nums) {

        int totalElements = nums.size();
        
        int firstzeroidx = BinarySearch(nums, totalElements, 0);
        int firstpositiveidx = BinarySearch(nums, totalElements, 1);

        int positivecount = totalElements - firstpositiveidx;
        
        int negativecount = firstzeroidx;

        return max(positivecount, negativecount);

        
    }
};