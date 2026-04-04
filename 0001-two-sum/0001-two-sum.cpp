class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> seenBefore;

        for(int i=0; i<nums.size(); i++){
            
            // check 
            if(seenBefore.count(nums[i])){
                return {seenBefore[nums[i]], i};
            }

            // insert

            seenBefore[target - nums[i]] = i;

        }
        
        return {};
    }
};