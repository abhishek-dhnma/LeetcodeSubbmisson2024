class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        vector<int> maxRow(n+1);
        vector<int> minRow(n+1, n+1);
        vector<int> maxCol(n+1);
        vector<int> minCol(n+1, n+1);

        for(auto & b : buildings){

            int x = b[0];
            int y = b[1];

            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);

            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);

        }


        int count = 0;
        for(auto & b : buildings){
            int x = b[0];
            int y = b[1];

            if(minRow[y] < x && maxRow[y] > x && minCol[x] < y && maxCol[x] > y ){
                count++;
            }

        }

        return count;
        
    }
};