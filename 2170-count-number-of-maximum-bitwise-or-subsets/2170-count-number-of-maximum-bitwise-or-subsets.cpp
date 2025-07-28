class Solution {
public:
    int ansCount = 0;

    void solve(vector<int>& nums, int i, vector<int>& out, int maxOr) {

        if (i == nums.size()) {
            // Handle empty subset case
            int loclOr = 0;
            if (!out.empty()) {
                loclOr = out[0];

                for (int i = 1; i < out.size(); i++) {
                    loclOr |= out[i];
                }
            }

            if (maxOr == loclOr) {
                ansCount++;
            }

            return;
        }

        // Include nums[i]
        out.push_back(nums[i]);
        solve(nums, i + 1, out, maxOr);

        // Exclude nums[i]
        out.pop_back();
        solve(nums, i + 1, out, maxOr);

        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        // Handle empty input
        if (nums.empty()) {
            return 0;
        }

        // Compute maxOr
        int maxOr = nums[0];
        bool allSame = true;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            maxOr |= nums[i];
            if (nums[i] != nums[0]) {
                allSame = false;
            }
        }

        // If all elements are identical, all non-empty subsets have the same OR
        if (allSame) {
            return (1LL << n) - 1;
        }

        vector<int> out;
        solve(nums, 0, out, maxOr);

        return ansCount;
    }
};