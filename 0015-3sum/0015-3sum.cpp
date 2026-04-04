class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        // WHY SORT? 
        // 1. It allows us to use the Two-Pointer technique (only works on sorted data).
        // 2. It makes it easy to skip duplicate numbers because they will be adjacent.
        // 3. It allows for an early exit optimization if the smallest number is > 0.
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {
            
            // WHY BREAK? 
            // If the smallest of the three numbers is positive, their sum 
            // will always be > 0. No need to check further.
            if (nums[i] > 0) break;

            // WHY SKIP nums[i] DUPLICATES? 
            // If we already tried this number as our 'fixed' first element,
            // using it again would result in the exact same triplets.
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int x = i + 1; // Left pointer
            int y = n - 1; // Right pointer

            while (x < y) {
                int sum = nums[i] + nums[x] + nums[y];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[x], nums[y]});
                    
                    // WHY SKIP nums[x] & nums[y] DUPLICATES?
                    // We found a valid triplet. If the next x or previous y are the 
                    // same numbers, they would produce the same triplet again.
                    while (x < y && nums[x] == nums[x + 1]) x++;
                    while (x < y && nums[y] == nums[y - 1]) y--;

                    // After skipping duplicates, we still need to move to the next 
                    // potential unique pair.
                    x++;
                    y--;
                } 
                else if (sum < 0) {
                    // WHY x++? 
                    // The sum is too small. Since the array is sorted, 
                    // moving the left pointer to the right gives us a larger number.
                    x++;
                } 
                else {
                    // WHY y--? 
                    // The sum is too large. Moving the right pointer to the 
                    // left gives us a smaller number.
                    y--;
                }
            }
        }
        return ans;
    }
};