class Solution {
public:

    int helper(string s, char x, char y) {
        int n = s.size();

        unordered_map<int, int> diffMap;

        int countx = 0;
        int county = 0;
        int maxL = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] != x && s[i] != y) {
                diffMap.clear();
                countx = 0;
                county = 0;
                continue;
            }


            if (s[i] == x) countx++;
            if (s[i] == y) county++;


            if (countx == county) {
                maxL = max(maxL, countx + county);
            } else {
                int diff = countx - county;

                if (diffMap.count(diff)) {
                    int idx = diffMap[diff];
                    maxL = max(maxL, i - idx);
                } else {
                    
                    diffMap[diff] = i;
                }
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxL = 0;

       
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] != s[j]) {
                i = j; 
            }
            maxL = max(maxL, j - i + 1);
        }

        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'b', 'c'));
        maxL = max(maxL, helper(s, 'a', 'c'));


        int counta = 0, countb = 0, countc = 0;

        unordered_map<long long, int> diffMap;

        for (int i = 0; i < n; i++) {
            
            if (s[i] == 'a') counta++;
            if (s[i] == 'b') countb++;
            if (s[i] == 'c') countc++;

            if (counta == countb && counta == countc) {
                maxL = max(maxL, counta + countb + countc);
            }

           
            int diffab = counta - countb;
            int diffac = counta - countc;

long long key = (long long)(diffab + n) * (2 * n + 1) + (diffac + n);


            if (diffMap.count(key)) {

                maxL = max(maxL, i - diffMap[key]);
            } else {

                diffMap[key] = i;
            }
        }

        return maxL;
    }
};