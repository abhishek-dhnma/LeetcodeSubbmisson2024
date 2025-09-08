class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        // insert into hashset
        unordered_set<int> st( nums.begin(), nums.end());

        // app 2

        int maxLen = 0;

        for(auto & elmt : st){
            
            if(!st.count(elmt - 1)){
                int currLen = 1;
                int currNum = elmt;


                // check = 1 -> 2 -> 3

                while(st.count(currNum + 1)){
                    currLen++;
                    currNum++;
                }

                // maxLength

                maxLen =  max(currLen, maxLen);


            }

        }

        return maxLen;


        
    }
};