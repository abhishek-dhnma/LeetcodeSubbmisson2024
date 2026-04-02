class Solution {
public:
    /*
     * HELPER: Finds longest balanced substring containing ONLY two characters x and y
     * (equal count of x and y)
     * 
     * CORE IDEA: Track prefix counts of x and y. The difference (countx - county) 
     * acts like a "balance key". If same difference appears again at index i and j,
     * then substring s[j+1...i] has equal x and y.
     * 
     * This is the classic "Longest Subarray with Equal 0s and 1s" trick —
     * treat x as +1, y as -1, find longest subarray with sum = 0.
     */
    int helper(string s, char x, char y) {
        int n = s.size();

        // Stores first occurrence index of each (countx - county) difference value
        // Key: difference, Value: earliest index where this difference was seen
        unordered_map<int, int> diffMap;

        int countx = 0;
        int county = 0;
        int maxL = 0;

        for (int i = 0; i < n; i++) {
            // If character is neither x nor y → it breaks any possible balanced window
            // Reset everything since no valid substring can cross this character
            if (s[i] != x && s[i] != y) {
                diffMap.clear();
                countx = 0;
                county = 0;
                continue;
            }

            // Update running prefix counts
            if (s[i] == x) countx++;
            if (s[i] == y) county++;

            // Case A: counts are equal from the very beginning → full window is balanced
            if (countx == county) {
                maxL = max(maxL, countx + county);
            } else {
                int diff = countx - county;

                // Case B: same difference seen before at index `idx`
                // → substring from idx+1 to i has equal x and y
                if (diffMap.count(diff)) {
                    int idx = diffMap[diff];
                    maxL = max(maxL, i - idx); // length = i - idx (not +1, since idx is a previous index, not a character boundary)
                } else {
                    // First time seeing this difference → record it
                    // We do NOT overwrite if already exists (we want the EARLIEST occurrence for max length)
                    diffMap[diff] = i;
                }
            }
        }
        return maxL;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxL = 0;

        /*
         * ─────────────────────────────────────────────
         * CASE 1: All characters are the SAME (single distinct character)
         * e.g., "aaaa", "bbbb", "cccc"
         * 
         * Use two-pointer / sliding window:
         * Expand window as long as s[i] == s[j]
         * When s[j] != s[i], move i to j (new character starts a fresh window)
         * 
         * NOTE: This also handles substrings like "aaa" or "bbb" inside mixed strings
         * ─────────────────────────────────────────────
         */
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (s[i] != s[j]) {
                i = j; // Reset window start to current position
            }
            maxL = max(maxL, j - i + 1);
        }

        /*
         * ─────────────────────────────────────────────
         * CASE 2: Substring contains exactly TWO distinct characters
         * Each pair must have equal counts → balanced means count(x) == count(y)
         *
         * We enumerate all 3 possible pairs: (a,b), (b,c), (a,c)
         * and use the helper above for each
         * ─────────────────────────────────────────────
         */
        maxL = max(maxL, helper(s, 'a', 'b'));
        maxL = max(maxL, helper(s, 'b', 'c'));
        maxL = max(maxL, helper(s, 'a', 'c'));

        /*
         * ─────────────────────────────────────────────
         * CASE 3: Substring contains ALL THREE characters a, b, c
         * Balanced means count(a) == count(b) == count(c)
         *
         * TRICK: Instead of tracking one difference, track TWO differences:
         *   diffab = counta - countb
         *   diffac = counta - countc
         *
         * If at two indices the pair (diffab, diffac) is identical,
         * then the substring between them has equal a, b, and c.
         *
         * We encode the pair as a string key "diffab_diffac" for the hashmap.
         * ─────────────────────────────────────────────
         */
        int counta = 0, countb = 0, countc = 0;

        // Maps "diffab_diffac" string key → first index where this pair was seen
        unordered_map<string, int> diffMap;

        for (int i = 0; i < n; i++) {
            // Update prefix counts
            if (s[i] == 'a') counta++;
            if (s[i] == 'b') countb++;
            if (s[i] == 'c') countc++;

            // All three counts equal from index 0 → entire prefix is balanced
            if (counta == countb && counta == countc) {
                maxL = max(maxL, counta + countb + countc);
            }

            // Encode the 2D difference state as a composite key
            int diffab = counta - countb;
            int diffac = counta - countc;
            string key = to_string(diffab) + "_" + to_string(diffac);

            if (diffMap.count(key)) {
                // Same (diffab, diffac) seen at index diffMap[key]
                // → s[diffMap[key]+1 ... i] has equal a, b, c
                maxL = max(maxL, i - diffMap[key]);
            } else {
                // Record earliest occurrence of this state
                diffMap[key] = i;
            }
        }

        return maxL;
    }
};