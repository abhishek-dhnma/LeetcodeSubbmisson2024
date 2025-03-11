class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();

        int i = 0;
        int result = 0;

        int a = 0, b = 0, c = 0;

        for (int j = 0; j < n; j++) {

            if (s[j] == 'a')
                a++;
            if (s[j] == 'b')
                b++;
            if (s[j] == 'c')
                c++;

            while (a > 0 && b > 0 && c > 0) {
                result += (n - j);
                if (s[i] == 'a')
                    a--;
                if (s[i] == 'b')
                    b--;
                if (s[i] == 'c')
                    c--;

                i++;
            }
        }

        return result;
    }
};