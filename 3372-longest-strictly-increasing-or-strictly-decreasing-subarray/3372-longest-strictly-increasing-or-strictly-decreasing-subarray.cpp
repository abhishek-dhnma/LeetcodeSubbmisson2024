class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        //Pure brute force
        int n = nums.size();
        vector<vector<int>> subarray;

        // Generate all subarrays
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> sub;
                for (int k = i; k <= j; k++) {
                    sub.push_back(nums[k]);
                }
                subarray.push_back(sub);
            }
        }

        int incc = 1, dess = 1;

        // Check for increasing sequences
        for (auto& sub : subarray) {
            bool isIncreasing = true;
            for (int i = 0; i < sub.size() - 1; i++) {
                if (sub[i] >= sub[i + 1]) {
                    isIncreasing = false;
                    break;
                }
            }
            if (isIncreasing) {
                incc = max(incc, (int)sub.size()); // Update longest increasing subarray length
            }
        }

        // Check for decreasing sequences
        for (auto& sub : subarray) {
            bool isDecreasing = true;
            for (int i = 0; i < sub.size() - 1; i++) {
                if (sub[i] <= sub[i + 1]) {
                    isDecreasing = false;
                    break;
                }
            }
            if (isDecreasing) {
                dess = max(dess, (int)sub.size()); // Update longest decreasing subarray length
            }
        }

        return max(incc, dess);
        
    }
};