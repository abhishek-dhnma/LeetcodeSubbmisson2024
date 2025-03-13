class Solution {
public:
    int n, q;

    bool CheckwithDiffArrayTeq(vector<int>& nums, vector<vector<int>>& queries,
                               int k) {
        int n = nums.size();

        vector<int> diff(n, 0);

        for (int i = 0; i <= k; i++) {
            int lidx = queries[i][0];
            int ridx = queries[i][1];
            int validx = queries[i][2];

            diff[lidx] += validx;
            if ((ridx + 1) < n)
                diff[ridx + 1] -= validx;
        }

        int cumSum = 0;

        for (int i = 0; i < n; i++) {

            cumSum += diff[i];

            diff[i] = cumSum;

            if ((nums[i] - diff[i]) > 0) {
                return false;
            }
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        // Using Difference Array technique
        int n = nums.size();
        int q = queries.size();

        auto lambda = [](int x) { return x == 0; };

        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return 0;
        }

        int l = 0;
        int r = q-1;
        int result = -1;

       while(l <= r){
            int mid = l + (r-l)/2;
            if(CheckwithDiffArrayTeq(nums, queries, mid)){
                result = mid +1;
                r = mid -1;
            }else{
                l = mid +1;
            }   
       }

        return result;
    }
};