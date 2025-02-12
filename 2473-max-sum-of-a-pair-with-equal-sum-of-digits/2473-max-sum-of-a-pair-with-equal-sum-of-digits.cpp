class Solution {
public:
    int digitsum(int d) {
        int sum = 0;
        while (d > 0) {
            int dd = d % 10;
            sum += dd;
            d = d / 10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {

        int maxx = -1;
        int n = nums.size();

        unordered_map<int, int> sumTonum;

        for(int i=0; i<n; i++){

            int dsum =  digitsum(nums[i]);
            int sum = 0;

            if(sumTonum.count(dsum)){
                sum = nums[i] + sumTonum[dsum];
                
                maxx = max(maxx, sum);
            }
            sumTonum[dsum]= max(nums[i], sumTonum[dsum] );;
        }

        return maxx;
        
    }
};