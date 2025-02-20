class Solution {
public:

    // Simplify Brute Force

    string findDifferentBinaryString(vector<string>& nums) {
                int n = nums.size();
        unordered_set<int> seen;

        // Convert all binary strings to decimal and store in set
        for (const auto& str : nums) {
            seen.insert(bitset<16>(str).to_ulong());
        }

        // Find the first missing number
        for (int i = 0; i < (1 << n); i++) {
            if (!seen.count(i)) {
                return bitset<16>(i).to_string().substr(16 - n); // Return n-bit binary string
            }
        }
        return ""; // Should never reach here
    }
};