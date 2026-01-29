class Solution {
public:
    bool isPalindrome(int x) {

        string str = to_string(x);

        string rstr = "";

        for(int i= str.size() - 1; i>=0; i--){
            rstr += str[i];
        }


        return str == rstr;

        
    }
};