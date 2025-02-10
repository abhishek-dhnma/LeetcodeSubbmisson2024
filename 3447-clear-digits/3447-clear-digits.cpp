class Solution {
public:
    string clearDigits(string s) {
        // Now interviwer Asks to do IN-PLACE without 
        // Any EXTRA SPACE 
        // AND with linear Time Complexity

        int i = 0;
        int j = 0;

        while(i < s.length() ){
            if(isdigit(s[i])){
                j = max(j-1,0);
            }else{
                s[j] = s[i];
                j++;
            }
            i++;
        }

        return s.substr(0,j);
        
    }
};