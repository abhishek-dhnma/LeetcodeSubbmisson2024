class Solution {
public:
 int count = 0; // To store the number of valid sequences

    void backtrack(unordered_map<char, int>& freq) {
        for (auto& [ch, f] : freq) {
            if (f > 0) {
                count++;   // Count the current arrangement
                freq[ch]--; // Use the character
                backtrack(freq); // Recursively generate further sequences
                freq[ch]++; // Backtrack
            }
        }
    }

    int numTilePossibilities(string tiles) {

      unordered_map<char, int> freq;
        for (char c : tiles) freq[c]++; // Build frequency map

        backtrack(freq);
        return count;
        
    }
};