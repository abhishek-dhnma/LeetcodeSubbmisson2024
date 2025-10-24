class Solution {
public:
    int n;

    int findpivot(vector<int>& nums) {

        int l = 0;
        int r = n - 1;

        while (l < r) {

            // remove duplicated left

            while(l < r && nums[l] == nums[l+1]){
                l++;
            }


            // remove duplicate right side 

            while(l < r && nums[r] == nums[r-1]){
                r--;
            }

            
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                // non sorted part

                l = mid + 1; //  right
            }else
            {
                r = mid; // left
            }
        }

        return r;
    }

    int binarysearch(vector<int>& nums, int l, int r, int target) {

        while (l <= r) {

            int mid = l + (r - l) / 2;

            // move

            if (nums[mid] > target) {
                // left

                r = mid - 1;
            } else if (nums[mid] < target) {
                // right
                l = mid + 1;
            } else {
                // both same
                return mid;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        // binary seaarch

        n = nums.size();

        int pivot = findpivot(nums);

        cout << pivot << endl;

        int idx = -1;

        idx = binarysearch(nums, 0, pivot - 1, target);

        if (idx != -1)
            return true;

        idx = binarysearch(nums, pivot, n - 1, target);

         if (idx != -1)
            return true;

        return false;
    }
};