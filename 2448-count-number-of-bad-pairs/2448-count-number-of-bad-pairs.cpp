class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = nums.size();

        long long result = 0;
    
        unordered_map<int, int> freq;
        for(int j=0; j<n; j++){
            int elementsSeenBeforeJ = j;
            result += (elementsSeenBeforeJ - freq[nums[j]-j]);

            freq[nums[j]-j]++;
        }

        return result;
    }
};