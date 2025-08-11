class Solution {
public:
    bool isPalindrome(string s) {

 string temp;
    for(int i=0; i<s.size(); i++){
        if(isalnum(s[i])) temp.push_back(tolower(s[i]));
    }


    string tempr = temp;
    reverse(temp.begin(), temp.end());

    return temp == tempr;


       
        
    }
};