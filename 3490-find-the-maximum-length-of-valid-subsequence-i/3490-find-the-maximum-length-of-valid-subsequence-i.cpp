class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int n = nums.size();

        int EvenCount = 0;
        int OddCount = 0;

        for(int & num : nums){
            if(!(num%2)){
                EvenCount++;
            }else{
                OddCount++;
            }
        }

        

        int AlternatingCount = 1;
        int FirstParity = nums[0]%2;

        for(int i=1; i<n; i++){

            // alternating logic
            int CurrParity = nums[i]%2;

            if(CurrParity != FirstParity){
                AlternatingCount++;
                FirstParity = CurrParity;
            }
        }

        return max(EvenCount,max( OddCount,AlternatingCount));
        
    }
};