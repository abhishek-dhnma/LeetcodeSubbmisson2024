class Solution {
public:
    int ansCount = 0;

    void solve(vector<int>& nums, int i, vector<int>& out, int maxOr) {

        if (i == nums.size()) {
            int loclOr = 0;

            if(!out.empty()){
                loclOr = out[0];

            for (int i = 1; i < out.size(); i++) {
                loclOr  |= out[i];
            }

            }
            

            if (maxOr == loclOr) {
                ansCount++;
            }

            return;
        }

        out.push_back(nums[i]);
        solve(nums, i + 1, out, maxOr);

        out.pop_back();
        solve(nums, i + 1, out, maxOr);

        return;
    }
    int countMaxOrSubsets(vector<int>& nums) {


        if (nums.empty()) {
            return 0;
        }

        

        int maxOr = nums[0];
        bool allSame = true;

        int n = nums.size();

        for (int i = 1; i < n; i++) {
            maxOr |= nums[i];
            if (nums[i] != maxOr) {
                allSame = false;
            }
        }
        

        if (allSame) {
            return (1LL << nums.size()) - 1;
        }

        vector<int> out;
        solve(nums, 0, out, maxOr);

        return ansCount;
    }
};