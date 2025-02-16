class Solution {
public:

   bool backtrack(vector<int>& ans, int n, int index, vector<bool>& used) {
        if (index == ans.size()) return true; // Successfully filled the array

        if (ans[index] != 0) return backtrack(ans, n, index + 1, used); // Skip filled positions

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue; // Skip used numbers

            int newPos = (num == 1) ? index : index + num; // Position for second occurrence
            if (newPos < ans.size() && ans[newPos] == 0) { // Check if valid placement
                ans[index] = ans[newPos] = num;
                used[num] = true;

                if (backtrack(ans, n, index + 1, used)) return true; // Continue solving

                // Backtrack
                ans[index] = ans[newPos] = 0;
                used[num] = false;
            }
        }

        return false; // No valid number could be placed
    }

    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1; // Corrected size calculation
        vector<int> ans(size, 0);
        vector<bool> used(n + 1, false); // To track used numbers

        backtrack(ans, n, 0, used);
        return ans;
        
    }
};