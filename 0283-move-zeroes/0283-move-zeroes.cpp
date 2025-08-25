class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        int zero = 0;

        for(auto & e :  nums){
            if(e != 0){
                temp.push_back(e);
            }else{
                zero++;
            }
        }

        while(zero--){
            temp.push_back(0);
        }

        nums = temp;
        
    }
};