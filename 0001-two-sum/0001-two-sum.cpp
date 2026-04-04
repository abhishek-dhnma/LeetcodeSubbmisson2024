class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mapp;

        int n = nums.size();
        for(int y =0; y<n ; y++){
            mapp[target - nums[y]] = y;
        }

        vector<int> ans;

        for(int x=0; x<n; x++){

            if(mapp.count(nums[x]) && mapp[nums[x]] != x){

                ans.push_back(x);
                ans.push_back(mapp[nums[x]]);
                break;

            }


        }

        return ans;
        
    }
};