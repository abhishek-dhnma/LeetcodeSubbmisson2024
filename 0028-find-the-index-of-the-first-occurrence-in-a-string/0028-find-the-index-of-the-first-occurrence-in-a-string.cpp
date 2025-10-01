class Solution {
public:
    int strStr(string str1, string str2) {

        int s1 = str1.size();
        int s2 = str2.size();

        // edge case

        if (s1 < s2)
            return -1;

        if (s2 == 0)
            return 0;

        // main logic
        int i = 0;
        while (i <= s1 - s2) {

            if (str1.substr(i, s2) == str2) {
                return i;
            }

            i++;
        }

        return -1;
    }
};