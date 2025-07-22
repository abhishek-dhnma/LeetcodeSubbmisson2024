class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int n = nums.size();
        int i =0;
        int j =0;

        int sum = 0;

        int maxSoFar = 0;

        unordered_set<int> seen;

        while(j <n){

            if(!seen.count(nums[j])){
                seen.insert(nums[j]);
                sum += nums[j];
                maxSoFar = max(maxSoFar, sum);
                j++;
            }else{
                while( i<n && seen.count(nums[j])){
                sum -= nums[i];
                seen.erase(nums[i]);
                    i++;
                }
            }
        }

        return maxSoFar;

        
    }
};