class Solution {
public:
    int countPartitions(vector<int>& nums) {

        int s = nums.size();

        vector<int> prefixSum(s);

        prefixSum[0] = nums[0];

        for(int i=1; i<s; i++){

            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        //ps = [10,20,23,30,36]


        int ans=0;


        for(int i=1; i<=s-1; i++){
    
            if(( prefixSum[i-1] - (prefixSum[s-1]-prefixSum[i-1]))%2 ==0 ){
                ans++;
            }

        }


        return ans;
        
    }
};