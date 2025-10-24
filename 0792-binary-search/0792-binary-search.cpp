class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) { // 1.  find mid
            int mid = l + (r - l) / 2;

            // 2.
            if (nums[mid] < target) {
                l = mid + 1; // right side
            } else if (nums[mid] > target) {
                r = mid - 1; // left side
            } else {
                // both are equal or we found our target
                return mid;
            }
        }

        return -1;
    }
};