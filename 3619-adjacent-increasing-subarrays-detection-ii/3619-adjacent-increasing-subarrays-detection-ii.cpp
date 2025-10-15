class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int n = nums.size();


        int preRun = 0;
        int curRun = 1;

        int maxResult = 0;

        for(int i=1; i<n; i++){


            if(nums[i] > nums[i-1]){
                curRun++;
            }else {
                preRun = curRun;
                curRun = 1;
            }

            int xx = curRun/2;

            int yy = min(curRun, preRun);


            maxResult = max({maxResult, xx, yy});

        }

        return maxResult;
        
    }
};