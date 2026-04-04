class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> seenBefore;
        vector<int> ans;

        for(int i=0; i<nums.size(); i++){
            
            // check 
            if(seenBefore.count(nums[i])){
                ans.push_back(i);
                ans.push_back(seenBefore[nums[i]]);
                return ans;
            }

            // insert

            seenBefore[target - nums[i]] = i;

        }
        
        return ans;
    }
};