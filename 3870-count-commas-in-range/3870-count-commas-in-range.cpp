class Solution {
public:
    int countCommas(int n) {
        // If the number is less than 1000, there are 0 commas.
        if (n < 1000) {
            return 0;
        }
        
        // Otherwise, every number from 1000 to n has exactly 1 comma.
        return (n - 1000) + 1;
    }
};