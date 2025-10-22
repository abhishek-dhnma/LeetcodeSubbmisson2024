class Solution {
public:
    int n;

    int findpivot(vector<int>& nums){

        int l = 0;
        int r = n-1;

        while(l <r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){
                l = mid +1;
            }else{
                r = mid;
            }
        }

        return r;

    }

    int binarySearch(vector<int>& nums, int l, int r, int target){

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){

                l = mid+1;

            }else{
                r = mid-1;
            }
        }


        return -1;   

    }


    int search(vector<int>& nums, int target) {

        n = nums.size();

        int pivot = findpivot(nums); // similar to find minimum in rotated sorted array


        // find target in left side 
        int idx = binarySearch(nums,0, pivot-1, target);

        if(idx != -1) return idx;
        // find target in right side
        idx = binarySearch(nums,pivot, n-1, target);

        return idx;        
    }
};