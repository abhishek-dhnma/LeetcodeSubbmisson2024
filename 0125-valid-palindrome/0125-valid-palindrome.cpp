class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // check palindrome

        int i = 0;
        int j = n - 1;

        while(i < j) {

 
            
            while (i < j && !isalnum(s[i])) {
                i++;
            }

            while (i < j && !isalnum(s[j])) {
                j--;
            }


            if (s[i] != s[j]) {
                return false;
            }

            j--;
            i++;

        }

        return true;
    }
};