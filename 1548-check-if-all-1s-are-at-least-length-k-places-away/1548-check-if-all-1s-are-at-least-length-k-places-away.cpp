class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int i=0;
        int j=0;
        int n = nums.size();

        while(j<n){
            if(nums[j] == 1){
                break;
            }
            j++;
        }

        i=j;
        j++;

        while(j<n){
            if(nums[j] == 1){
                if((j-i-1) < k){
                    return false;
                }else{
                    i = j;
                }
            }
            j++;
        }

        return true;
        
    }
};