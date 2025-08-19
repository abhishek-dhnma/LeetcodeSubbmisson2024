class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Problem: Best Time to Buy and Sell Stock (LeetCode 121)
        // Goal: Find max profit by choosing a day to buy and a later day to sell

        int n = prices.size();

        int currmax = 0;        // Stores maximum profit found so far
        int currmin = prices[0]; // Tracks the minimum price (best day to buy so far)
        int d = 0;              // Temporary profit difference

        // Traverse the prices array once (O(n) solution)
        for (int i = 0; i < n; i++) {

            // Update minimum price so far (potential buy day)
            currmin = min(currmin, prices[i]);

            // If today's price is same or lower than currmin → no profit, skip
            if (currmin >= prices[i]) {
                continue;
            }

            // If today's price is higher than min → possible profit
            if (currmin < prices[i]) {
                d = prices[i] - currmin; // Calculate profit (sell today - min buy price)
            }

            // Update max profit if today's profit is better
            currmax = max(currmax, d);
        }

        return currmax; // Final answer: maximum profit
    }
};
