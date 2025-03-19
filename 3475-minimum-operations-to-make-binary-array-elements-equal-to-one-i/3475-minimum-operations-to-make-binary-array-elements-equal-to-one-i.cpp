class Solution {
public:
    int minOperations(vector<int>& nums) {
        

        int n = nums.size();
        int flip = 0;

        for(int i=0;i<n; i++){

            if(nums[i] == 0){
                cout << i << " ";
                int j = i;
                
                if((j+1 < n) && (j+2 < n)){
                nums[j] = 1;
                nums[j+1] = (nums[j+1] == 1 )? 0 : 1;
                nums[j+2] = (nums[j+2] == 1) ? 0 : 1; 
                flip++;
                }else{
                    flip = -1;
                }

            }


        }

        return flip;
    }
};