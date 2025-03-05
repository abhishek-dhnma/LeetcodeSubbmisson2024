class Solution {
public:
    long long coloredCells(int n) {

        // math pattern observation

        return 1 + (2 * (long long)(n-1) * n);
        
    }
};