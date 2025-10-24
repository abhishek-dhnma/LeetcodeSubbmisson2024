class Solution {
public:
    int findMin(vector<int>& nums) {

        // binary seacrh

        int n = nums.size();

        int l = 0;
        int r = n-1;

        // binary search algo 
        while(l < r ){

            int mid = l + (r-l)/2; // mid

            // move but which side?

            // consditions

            if(nums[mid] > nums[r]){ // non - sorted part

                l = mid + 1;

            }else{

                r = mid;
            }


        }


        return nums[r];

    }
};