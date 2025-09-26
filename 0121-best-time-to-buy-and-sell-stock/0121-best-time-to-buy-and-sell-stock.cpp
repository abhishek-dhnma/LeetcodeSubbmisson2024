class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int minSoFar = INT_MAX; // + infinity
        int diff = 0;
        int currMaxProfit = 0; // - infinity

        for(int i=0; i<n; i++){

            minSoFar = min(minSoFar, prices[i]);

            // equal and smaller -> skip
            if( prices[i] <= minSoFar){

                continue;

            }

            // if greater 
            if( prices[i] > minSoFar){

                diff = prices[i] - minSoFar;
            }

            currMaxProfit = max(currMaxProfit, diff);



        }

        return currMaxProfit;
        
    }
};