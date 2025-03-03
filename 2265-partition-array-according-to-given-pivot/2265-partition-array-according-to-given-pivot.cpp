class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> sm, lg, eq, ans;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                sm.push_back(nums[i]);
            }else if(nums[i] > pivot){
                lg.push_back(nums[i]);
            }else{
                eq.push_back(nums[i]);
            }
        }

        for(int i=0; i<eq.size(); i++){
            sm.push_back(eq[i]);
        }
        
        for(int i=0; i<lg.size(); i++){
            sm.push_back(lg[i]);
        }
        
        
        return sm;
    }
};