class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        int n = nums.size();

        long long result = 0;

        vector<int> modifiedNums;
        for(int i=0; i<n; i++){
            modifiedNums.push_back(nums[i] - i);
        }

        unordered_map<long long, long long> freq;
        for(int j=0; j<n; j++){
            long long elementsSeenBeforeJ = j;
            result += (elementsSeenBeforeJ - freq[modifiedNums[j]]);

            freq[modifiedNums[j]]++;

        }

        return result;
    }
};