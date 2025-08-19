class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;;
        int j=  0;

        long long count =0;

        while(j < n){

            if(nums[j] == 0){
                i = j;

                while(j < n-1 && nums[j+1] == 0){
                j++;
            }

            int s = j - i + 1;

            count += (s * (long)(s+1))/2;
            }
            

            j++;
        }

        return count;
        
    }
};