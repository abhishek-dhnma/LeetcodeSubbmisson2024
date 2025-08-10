class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;

        int n =nums.size();
        vector<int> ans;


        // Optimal Approach

        for(int i=0; i<n; i++){

           int y =  target - nums[i];

            if(map.find(y) != map.end() ){
                ans.push_back(i);
                ans.push_back(map[y]);
                break;
            }
            map[ nums[i]] = i;
        }

        return ans;
        
    }
};