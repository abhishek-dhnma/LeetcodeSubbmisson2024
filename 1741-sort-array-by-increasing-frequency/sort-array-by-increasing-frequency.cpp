class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        vector<int> ans;

        // Frequency Table
        unordered_map<int, int> freqMap;

        for(int i=0; i<nums.size(); i++){
            freqMap[nums[i]]++;
        }

        //Sort by value
        sort(nums.begin(), nums.end(), [&](const auto& a, const auto& b){

            if(freqMap[a] != freqMap[b]) return freqMap[a] < freqMap[b];
            else return b < a;
             
             });


        return nums;
    }

};