class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int> sm, lg, eq;

        for(const auto & num : nums){
            if(num < pivot) sm.push_back(num);
            else if(num > pivot) lg.push_back(num);
            else eq.push_back(num);
        }

        sm.insert(sm.end(), eq.begin(), eq.end());
        sm.insert(sm.end(), lg.begin(), lg.end());
        
        
        return sm;
    }
};