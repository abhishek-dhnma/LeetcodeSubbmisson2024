class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> vec;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                vec.push_back(grid[i][j]);
            }
        }

        int  L =  vec.size();
        //sort(vec.begin(), vec.end());
        //Partial Sorting using nth_element
        nth_element(begin(vec), begin(vec) + L/2 , end(vec));

        int result = 0;

        int mid = vec[L/2];

        for(auto & num : vec){

            if(num%x != mid%x) return -1;

            result += (abs(mid - num) / x ) ;


        }


        return result;

        
    }
};