class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> st;

        for(auto & n : nums){


            if(!st.count(n)){
                st.insert(n);
            }else{
                return true;
            }


        }


    return false;


        
    }
};