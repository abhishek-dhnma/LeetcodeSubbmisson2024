class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size()/2;
        int ans = -1;

        unordered_map<int, int> mp;

        for(auto & n : nums){
            mp[n]++;
        } 


        for(auto & [k, v] : mp){

            if( v == n){
                ans = k;
                break;
            }

        }

        return ans;
        
    }
};