class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int, int> mapp;
        for(int i=0; i<n; i++){

            if(mapp.find(nums[i]) != mapp.end()){
                return {i, mapp[ nums[i]]};
            }

            mapp[target - nums[i]] = i;


        }

        return {};
        
    }
};