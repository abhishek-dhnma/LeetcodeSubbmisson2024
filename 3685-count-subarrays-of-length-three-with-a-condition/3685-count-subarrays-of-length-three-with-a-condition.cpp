class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            int j = i+1;
            int k = i+2;
                    if(j <n && k< n)
                   { double sum = (double)nums[i] + nums[k];
                    double half = (double)nums[j]/2;

                    cout << sum << " " << half << "-" << i << j << k << endl;
                    if( sum == half){
                        count++;
                    }}
        }

        return count;
        
    }
};