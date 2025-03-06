class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> temp;

        int n = grid.size();
        set<int> ss;


        for(int i=0; i<n; i++){

            for(int j=0; j<n; j++){

                temp.push_back(grid[i][j]);
                ss.insert(grid[i][j]);


            }
        }

        sort(temp.begin(), temp.end());

        vector<int> ans(2);
        ans[0] = INT_MAX;


        for(int i=0; i<temp.size()-1; i++){

            if(temp[i] == temp[i+1]){
                ans[0] = min(ans[0], temp[i]);
            }

            if(ss.find(i+1) == ss.end()){
                ans[1] = i+1;
            }

        }

        if(ss.find(temp.size()) == ss.end()){
            ans[1] = temp.size();
        }



        
        return ans;
    }
};