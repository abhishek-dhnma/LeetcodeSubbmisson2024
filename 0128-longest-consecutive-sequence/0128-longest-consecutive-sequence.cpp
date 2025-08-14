class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int maxLen = 0;


        for(auto & num : st){
            if(!st.count(num-1)){
                int curNum = num;
                int currentLen = 0;

                while(st.count(curNum)){
                    curNum += 1;
                    currentLen += 1;
                    
                }

                maxLen = max(maxLen, currentLen);
            }
        }


        return maxLen;
        
    }
};