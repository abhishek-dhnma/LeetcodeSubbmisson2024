class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> vec;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                vec.push_back(grid[i][j]);
            }
        }

        sort(vec.begin(), vec.end());

        int mid = vec[vec.size()/2];

        int result = 0;

        for(auto & num : vec){

            if(num%x != mid%x) return -1;

            result += (abs(mid - num) / x ) ;


        }


        return result;

        
    }
};