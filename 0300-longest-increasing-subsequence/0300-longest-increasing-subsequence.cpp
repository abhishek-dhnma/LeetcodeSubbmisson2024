class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> patienceSortedTechnique;

        int n = nums.size();

        for(int i=0; i<n; i++){
            
            auto it = lower_bound(patienceSortedTechnique.begin(), patienceSortedTechnique.end(), nums[i]);
            if(it != patienceSortedTechnique.end()){

                *it = nums[i];

            }else{
                patienceSortedTechnique.push_back(nums[i]);
            }


        }

        return patienceSortedTechnique.size();        
    }
};