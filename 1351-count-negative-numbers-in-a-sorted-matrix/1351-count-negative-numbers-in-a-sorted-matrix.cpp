class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        for( auto & vec : grid){
            for(auto & el : vec){
                if(el < 0){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};