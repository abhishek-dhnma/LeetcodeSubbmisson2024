class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = nums.size();

        long long badPairs = 0;
    
        unordered_map<int, int> freq;
        for(int j=0; j<n; j++){
            int TotalPairs = j;
            int goodPairs = freq[nums[j]-j];
            badPairs += (TotalPairs - goodPairs);

            freq[nums[j]-j]++;
        }

        return badPairs;
    }
};