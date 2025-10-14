class Solution {
public:

    bool isIncreaing(vector<int>& nums, int start, int end){


        for(int i=start+1; i< end; i++){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }

return true;

    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        int n = nums.size();

        for(int start = 0; start + 2*k <= n; start++){

            bool first = isIncreaing(nums, start, start+k);
            bool second = isIncreaing(nums, start+k, start + 2*k);

             if(first && second){
                return true;
             }
        }

        return false;
    }
};