class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Goal: Check if any permutation of s1 is a substring of s2
        // Approach: Sliding window with frequency comparison
        // 1. Track frequency of characters in s1 (freq1)
        // 2. Use sliding window in s2 to track frequency of characters (freq2)
        // 3. If freq1 == freq2 for a window of size s1.length(), a permutation exists

        vector<int> freq1(26, 0), freq2(26, 0); // Frequency arrays for lowercase letters (a-z)

        // Build frequency array for s1
        for (auto &ch : s1) {
            freq1[ch - 'a']++; // Increment count for each character in s1
        }

        int n = s1.size(); // Length of s1 (window size)
        int m = s2.size(); // Length of s2

        int i = 0; // Left pointer of sliding window
        int j = 0; // Right pointer of sliding window

        while (j < m) {
            // Add current character to freq2
            freq2[s2[j] - 'a']++;

            // If window size exceeds s1's length, shrink from left
            if (j - i + 1 > n) {
                freq2[s2[i] - 'a']--; // Remove leftmost character from freq2
                i++; // Move left pointer
            }

            // If window size equals s1's length, check for permutation
            if (j - i + 1 == n && freq1 == freq2) {
                return true; // Found a permutation (same frequency counts)
            }

            j++; // Expand window by moving right pointer
        }

        return false; // No permutation found
    }
};