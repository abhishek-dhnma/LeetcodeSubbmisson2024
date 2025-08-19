class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int moj = 0;
        int n = prices.size();

        int currmax = 0;
        int currmin = prices[0];
        int d = 0;
        for(int i =0; i<n; i++){
            
            currmin = min(currmin, prices[i]);

            if(currmin >= prices[i]){
                    continue;
            }

            if(currmin < prices[i]){
                d = prices[i] - currmin;
                
            }

            currmax = max(currmax, d);

            
            
        }

        return currmax;
        
    }
};