class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        int curRun = 1;
        int preRun = 0;

        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                curRun++;
            } else {
                preRun = curRun;
                curRun = 1;

                
            }
            if (curRun >= 2*k) {
                    return true;
                }

            if(min(preRun, curRun) >= k){
                return true;
            }
        }

        return false;
    }
};