class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int zero = 0;

        int idx = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                zero++;
            }else{
                nums[idx] = nums[i];
                idx++;
            }

            
        }
        while(idx < n){
            nums[idx] = 0;
            idx++;
        }
    }
};