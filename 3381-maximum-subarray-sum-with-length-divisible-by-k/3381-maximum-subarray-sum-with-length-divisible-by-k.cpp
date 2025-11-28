class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> prefixSum(n);

            prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }


        long long maxsum = LLONG_MIN;

        for(int s=0; s<k; s++){

            int i = s;
            long long currSum = 0;

            while( i<n && (i+k-1)<n ){
                int j = i+k-1;

                long long subsum= prefixSum[j] - (i>0 ? prefixSum[i-1] : 0);

                currSum = max(subsum, currSum + subsum );

                maxsum = max(maxsum, currSum);

                i += k;

            }

        }

        return maxsum;
        
    }
};