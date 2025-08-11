class Solution {
public:
    bool isPalindrome(string s) {

        int n = s.size();

        

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




           if (tolower(s[i]) != tolower(s[j])) { // Case-insensitive comparison
                return false;
            }

            j--;
            i++;

        }

        return true;
    }
};