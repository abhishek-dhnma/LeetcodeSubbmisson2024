class Solution {
public:
    vector<vector<int>> ans; // Store all valid triplets

    void twoSum(vector<int>& nums, int target, int i, int j) {
        // Two-pointer technique to find pairs summing to target
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum > target) {
                j--; // Sum too large, move right pointer left
            } else if (sum < target) {
                i++; // Sum too small, move left pointer right
            } else {
                // Found a valid pair (nums[i], nums[j])
                // Skip duplicates to avoid repeated triplets
                while (i < j && nums[i] == nums[i + 1]) i++;
                while (i < j && nums[j] == nums[j - 1]) j--;
                
                // Add triplet {-target, nums[i], nums[j]} to result
                ans.push_back({-target, nums[i], nums[j]});
                
                i++; // Move left pointer
                j--; // Move right pointer
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        // Goal: Find all unique triplets (n1, n2, n3) where n1 + n2 + n3 = 0
        // Optimal Approach: 
        // 1. Sort array (O(n log n)) to use two-pointer technique
        // 2. Fix one number (n1), find pair (n2, n3) summing to -n1
        // 3. Skip duplicates to ensure unique triplets

        int n = nums.size();
        if (n < 3) return {}; // Need at least 3 numbers for a triplet

        // Sort array to enable two-pointer technique and duplicate handling
        sort(nums.begin(), nums.end());

        // Fix first element (n1) and find pair (n2, n3)
        for (int i = 0; i <= n-3; i++) {
            // Skip duplicates for first element to avoid repeated triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int n1 = nums[i];
            int target = -n1; // We need n2 + n3 = -n1

            // Find pair (n2, n3) in subarray nums[i+1...n-1]
            twoSum(nums, target, i + 1, n - 1);
        }

        return ans; // Return all unique triplets
    }
};