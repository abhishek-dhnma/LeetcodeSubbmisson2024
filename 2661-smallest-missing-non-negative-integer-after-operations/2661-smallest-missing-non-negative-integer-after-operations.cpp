class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        unordered_map<int, int> freq;
        int n = nums.size();

        for(int i=0; i<n; i++){

            int temp = ((nums[i]%value)+value)%value;

            freq[temp]++;
        }


        int mex = 0;

        while(freq[mex%value] > 0){
            freq[mex%value]--;
        
            mex++;
        }

        return mex;
        
    }
};