class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefixSum(n);
        prefixSum[0] = 0;
        vector<int> suffixSum(n);
        suffixSum[n-1] = 0;

        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }


        for(int i= n-2; i>=0; i--){

            suffixSum[i] = suffixSum[i+1] + nums[i+1];
        }

        for(int i=0; i<n; i++){
            if(prefixSum[i] == suffixSum[i]){
                return i;
                break;
            }

        }

        return -1;
        
    }
};