class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> vec;

        for(auto & x : nums){

            vec[x]++;

            if( vec[x] == 2){
                return x;
            }

        }

        return -1;
        
    }
};