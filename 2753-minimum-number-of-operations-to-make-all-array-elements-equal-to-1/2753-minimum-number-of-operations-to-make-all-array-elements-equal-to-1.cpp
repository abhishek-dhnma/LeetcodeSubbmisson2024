class Solution {
public:
    int minOperations(vector<int>& nums) {

        // count # of ones in nums

        int onecount = 0;

        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                onecount++;
            }
        }
        if(onecount > 0) return n - onecount; // I only need to convert other non-one elements to one 

        // if no one if present in nums
        // we need to convert any num to 1 byself/manually and so the calculatins 

        int operations = INT_MAX;

        for(int i=0; i<n-1; i++){

            int currgcd = nums[i];

            for(int j=i+1; j<n; j++){

               currgcd =  gcd(currgcd, nums[j]);

               if(currgcd == 1){

                operations = min(operations, j-i);

               }


            }

        }

        // if operations is still int_max that's mean we cannot able to convert any element into 1
        // that's why this still int_max 
        if(operations == INT_MAX) {
            return -1;
        }

        return operations + (n-1);
        
    }
};