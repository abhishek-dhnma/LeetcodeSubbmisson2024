class Solution {
public:
    /**
     * Helper finds the longest substring containing ONLY characters x and y 
     * where the count of x equals the count of y.
     */
    int helper(string s, char x, char y) {
        int n = s.size();
        // diffMap stores the FIRST index where a specific (countx - county) was seen.
        // Logic: If (countx - county) is the same at index i and index j,
        // then the substring between i and j has an equal number of x and y.
        unordered_map<int, int> diffMap;

        int countx = 0;
        int county = 0;
        int maxL = 0;
        
        // We initialize the difference 0 at index -1 to handle cases where 
        // the balance starts from the very beginning of the string.
        diffMap[0] = -1; 

        for (int i = 0; i < n; i++) {
            // If we hit a character that isn't x or y, the current "valid" window breaks.
            // We reset everything to start fresh for the next potential segment.
            if (s[i] != x && s[i] != y) {
                diffMap.clear();
                diffMap[0] = i; // Reset base for the next segment
                countx = 0;
                county = 0;
                continue;
            }
            
            if (s[i] == x) countx++;
            if (s[i] == y) county++;

            int diff = countx - county;

            if (diffMap.count(diff)) {
                // If we've seen this difference before, the segment between 
                // the previous index and current index is balanced.
                maxL = max(maxL, i - diffMap[diff]);
            } else {
                // Only store the first occurrence to maximize the distance (i - idx)
                diffMap[diff] = i;
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxL = 0;

        // --- CASE 1: Longest contiguous substring of a single character ---
        // Example: "aaabb" -> maxL = 3 (for "aaa")
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] != s[j]) {
                i = j; // Reset start pointer when character changes
            }
            maxL = max(maxL, j - i + 1);
        }

        // --- CASE 2: Longest balanced substring of exactly two distinct characters ---
        // We check all possible pairings: (a,b), (b,c), and (a,c).
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'b', 'c'));
        maxL = max(maxL, helper(s, 'a', 'c'));

        // --- CASE 3: Longest balanced substring of all three characters (a, b, c) ---
        // Logic: For a substring to have equal a, b, and c:
        // (countA - countB) must be the same as a previous point AND
        // (countA - countC) must be the same as a previous point.
        int counta = 0, countb = 0, countc = 0;
        unordered_map<string, int> diffMap;
        
        // Base case: at index -1, all counts are 0, so differences are (0,0)
        diffMap["0_0"] = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') counta++;
            else if (s[i] == 'b') countb++;
            else if (s[i] == 'c') countc++;

            // Create a unique key representing the relative differences
            int diffab = counta - countb;
            int diffac = counta - countc;
            string key = to_string(diffab) + "_" + to_string(diffac);

            if (diffMap.count(key)) {
                // If this pair of differences has been seen, the range is balanced for all three
                maxL = max(maxL, i - diffMap[key]);
            } else {
                diffMap[key] = i;
            }
        }

        return maxL;
    }
};