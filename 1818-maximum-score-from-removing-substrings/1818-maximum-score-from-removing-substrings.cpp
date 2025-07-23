class Solution {
public:
    int result = 0;

    void removePairs(string& s, int & n, int val, char ch1, char ch2) {

        for (int i = 0; i < n - 1; i++) {

            while (s[i] == ch1 && s[i + 1] == ch2) {
                s.erase(i, 2);
                result += val;
                i = max(0, i - 2);// Rewind to check overlapping pairs
                n -= 2;
            }
        }
    }

    int maximumGain(string s, int x, int y) {

        char ch1;
        char ch2;
        int n = s.size();
// Determine which pair to prioritize based on the higher value
        if (x > y) {
            ch1 = 'a';
            ch2 = 'b';
        } else {
            ch1 = 'b';
            ch2 = 'a';
            swap(x,y); // Swap values so x is always the higher one
        }

        

        removePairs(s, n, x, ch1, ch2);

        removePairs(s, n, y, ch2, ch1);// Reverse pair for second pass


        return result;
    }
};