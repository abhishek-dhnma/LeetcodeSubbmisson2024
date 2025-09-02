class Solution {
public:
    vector<vector<int>> ans;

    void twoSum(vector<int>& nums, int target, int i, int j) {

        while (i < j) {

            if (nums[i] + nums[j] > target) {
                j--;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                // first we will remove duplicates from eith ends
                while (i < j && nums[i] == nums[i + 1])
                    i++;
                while (i < j && nums[j] == nums[j - 1])
                    j--;

                ans.push_back({-target, nums[i], nums[j]});

                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        // Optimal Solution
        // Sort
        // fixed (n1), remove duplicates

        int n = nums.size();

        if (n < 3)
            return {};

        // sort
        sort(nums.begin(), nums.end());

        // fixing one element
        for (int i = 0; i <= n-3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i + 1,
                   n - 1); // it will find n2 and n3 : {n1, n2 , n3}
        }

        return ans;
    }
};