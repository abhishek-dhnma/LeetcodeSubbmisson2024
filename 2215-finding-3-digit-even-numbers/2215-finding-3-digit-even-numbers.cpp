class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        set<int> resultSet;

        // Try all combinations of 3 digits (i, j, k)
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < digits.size(); j++) {
                for (int k = 0; k < digits.size(); k++) {
                    // All digits must be from different indices
                    if (i == j || j == k || i == k) continue;

                    int a = digits[i], b = digits[j], c = digits[k];

                    // Skip if first digit is 0 (not a 3-digit number)
                    if (a == 0) continue;

                    // Number must be even
                    if (c % 2 != 0) continue;

                    int num = a * 100 + b * 10 + c;
                    resultSet.insert(num);
                }
            }
        }

        // Convert set to sorted vector
        return vector<int>(resultSet.begin(), resultSet.end());
        
    }
};