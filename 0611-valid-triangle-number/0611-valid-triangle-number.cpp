class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int count = 0;
        int a, b, c;

        for (int i = 0; i < n - 2; i++) {
            
            for (int j = i + 1; j < n - 1; j++) {
                

                int sum = nums[i] + nums[j];

                auto it = lower_bound(nums.begin() + j + 1, nums.end(), sum);

                int k = (int) ( it - nums.begin()) - 1;

                if(k > j){count += (k-j);} 

                

                
            }
        }

        return count;
    }
};