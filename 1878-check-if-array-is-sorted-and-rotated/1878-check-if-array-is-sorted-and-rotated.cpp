class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();

        int rotationPoint  = 0;
         // Count the number of decreasing points
        for(int i=0; i<n; i++){
            if( nums[i] > nums[(i+1) % n]){
               rotationPoint++;
                if(rotationPoint > 1) return false;
            }
        }


        return  true;
    }
};