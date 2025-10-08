class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        // This vector stores the "top cards" of piles (like in patience sorting).
        // Each element represents the smallest possible tail of an increasing subsequence of that length.
        vector<int> patienceSortedTechnique;

        int n = nums.size();

        // Iterate through all elements of the input array
        for (int i = 0; i < n; i++) {

            // Find the first pile top (element in patienceSortedTechnique)
            // that is >= current number nums[i]
            // This is done using binary search (O(log n))
            auto it = lower_bound(patienceSortedTechnique.begin(),
                                  patienceSortedTechnique.end(),
                                  nums[i]);

            // Case 1: Found a pile top >= nums[i]
            // Replace it with nums[i] — making this pile's top smaller
            // (so it’s easier for future numbers to extend this subsequence)
            if (it != patienceSortedTechnique.end()) {
                *it = nums[i];
            } 
            // Case 2: No such pile top found
            // That means nums[i] is greater than all current pile tops
            // → start a new pile (extend the LIS length)
            else {
                patienceSortedTechnique.push_back(nums[i]);
            }
        }

        // The number of piles = length of Longest Increasing Subsequence
        return patienceSortedTechnique.size();        
    }
};
