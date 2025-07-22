class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int> cumSum(n,0);

        for(int i=0; i<n; i++){
            if(i==0){
                cumSum[i] = nums[i];
            }
            else{
                cumSum[i] = cumSum[i-1] + nums[i];
            }
        }

        vector<int> mp(10001, -1);


        int i=0;
        int j=0;

        int maxSoFar = 0;

        while(j<n){

            i = max(i, mp[nums[j]] + 1);

            int ithSum = i-1 <0 ? 0 : cumSum[i-1]; 
            int jthSum = cumSum[j];
            maxSoFar = max(maxSoFar, jthSum - ithSum );
            mp[nums[j]] = j;
            j++;



        }

return maxSoFar;


        
    }
};