class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();

        long long ans = INT_MIN;

        for(int i=0; i<n; i++){

            for(int j = i+1; j<n; j++){
                
                for(int k = j+1; k<n; k++){

                    long long  triplet = ((long long)nums[i] - nums[j])  * (long long)nums[k];

                    ans = max(ans, triplet);


                }

            }


        }

        return ans < 0 ? 0 : ans;
        
    }
};