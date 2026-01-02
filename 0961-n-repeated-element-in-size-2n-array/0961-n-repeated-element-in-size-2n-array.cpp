class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int n = nums.size();

        vector<int> vec(10001,0);

        for(auto & x : nums){

            vec[x]++;

            if( vec[x] == 2){
                return x;
            }

        }

        return -1;
        
    }
};