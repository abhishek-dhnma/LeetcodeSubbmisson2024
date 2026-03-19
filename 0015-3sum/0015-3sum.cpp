class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        // did sorting
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // outer loop for i 

        for(int i=0; i<=n-3; i++){

            // skip duplicate 
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            // two pointer approach 

            int j = i+1;
            int k = n-1;


            while(j < k){
                
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // if there is duplicate values
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while( k > j && nums[k] == nums[k+1]) k--;

                }else if(sum > 0){
                    // i need to reduce my sum value
                    k--;
                }else if(sum < 0){
                    // i need to increase my sum value
                    j++;
                }

            }
        }

        return ans;
    }
};