class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        vector<bool> ans;

        int curr = 0;

        for(auto & n : nums){


            curr  = (curr * 2 + n)%5;

            if(curr%5 == 0){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }


        }

        return ans;        
    }
};