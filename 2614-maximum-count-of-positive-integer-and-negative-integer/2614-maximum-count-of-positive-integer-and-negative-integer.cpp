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
                right = mid - 1; // left
            }else{
                left = mid +1; // right
            }
        }

        return result;
    }

    int maximumCount(vector<int>& nums) {

        int totalElements = nums.size();
        
        int firstzeroidx = BinarySearch(nums, totalElements, 0);
        int firstpositiveidx = BinarySearch(nums, totalElements, 1);

        int zerocount = firstpositiveidx - firstzeroidx;

        int positivecount = totalElements - firstpositiveidx;
        
        int negativecount = totalElements - positivecount - zerocount;

        return max(positivecount, negativecount);

        
    }
};