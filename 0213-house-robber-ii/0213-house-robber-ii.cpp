class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int end){

    if(i > end){
        return 0;
    }
        if(t[i] != -1) {
            return t[i];
        }

        int take = nums[i] + solve(nums, i+2, end);
        int skip = solve(nums, i+1, end);


        return t[i] = max(take, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n==1) return nums[0];

        if(n==2) return max(nums[0], nums[1]);


        memset(t, -1, sizeof(t));


        int take_includefirsthouse = solve(nums, 0, n-2);

memset(t, -1, sizeof(t));
        int take_skipfirsthouse = solve(nums, 1, n-1);

        return max(take_includefirsthouse, take_skipfirsthouse);
    }
};