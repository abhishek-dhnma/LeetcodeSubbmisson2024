// ✅ Problem Intuition for Future Abhishek:
// We need to check if there exist **two consecutive increasing subarrays** of length ≥ k each.
// That means — either we find one long increasing run of length ≥ 2*k,
// or two back-to-back increasing runs of length ≥ k each.
//
// Example: nums = [1,2,3,1,2,3], k=2
// Here, [1,2,3] and [1,2,3] → both runs of length 3 ≥ 2 → so return true.
//
// So, we track two things:
// - curRun → length of current increasing streak
// - preRun → length of previous increasing streak (before drop)

class Solution { 
public: 
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        // curRun → current increasing segment length
        int curRun = 1;

        // preRun → previous increasing segment (before last drop)
        int preRun = 0;

        // Start from index 1 and compare each element with its previous one
        for (int i = 1; i < n; i++) {

            // ✅ Case 1: increasing trend continues
            if (nums[i] > nums[i - 1]) {
                curRun++;
            } 
            // ❌ Case 2: sequence breaks — store the last run length into preRun
            else {
                preRun = curRun; // save the previous run
                curRun = 1;      // reset current run
            }

            // \U0001f4a1 Case 1 check: If we ever get one long continuous run of length ≥ 2*k
            // That means we already have two k-length increasing subarrays overlapping.
            if (curRun >= 2 * k) {
                return true;
            }

            // \U0001f4a1 Case 2 check: If both previous and current runs have at least k length
            // e.g. prev = 3, current = 2, k=2 → [1,2,3][1,2] = valid pair
            if (min(preRun, curRun) >= k) {
                return true;
            }
        }

        // If no valid pair of runs found → false
        return false;
    }
};
