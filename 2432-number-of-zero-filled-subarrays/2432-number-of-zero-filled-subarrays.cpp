class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        // Single Pass Technique
        long long count = 0;
        long long runLength = 0;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] == 0){
                runLength++;
                count +=  runLength;
                // {0,0,0}
                // like : 1 + 2 + 3 = 6
                
            }else{
                runLength = 0;
            }

        }

        return count;
        
    }
};