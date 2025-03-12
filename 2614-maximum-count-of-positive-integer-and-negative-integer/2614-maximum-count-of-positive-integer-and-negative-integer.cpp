class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pc = 0;
        int nc = 0;

        int i = 0;

        while( i < n){

            if(nums[i] < 0){
                nc++;
            }

            if(nums[i] > 0){
                pc++;
            }

            i++;
        }

        return max(nc, pc);
        
    }
};