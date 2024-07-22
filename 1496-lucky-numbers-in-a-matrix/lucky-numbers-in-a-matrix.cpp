class Solution {
public:

    
    vector<int> LuckyNumber(vector<vector<int>> matrix){

        vector<int> row_min;
        vector<int> column_max;
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0; i<m; i++){
            int row = INT_MAX;
            for(int j=0; j<n; j++){
                if(row > matrix[i][j]){
                    row = matrix[i][j];
                }
            }
            row_min.push_back(row);
        }

        for(int i=0; i<n; i++){
            int column = INT_MIN;
            for(int j=0; j<m; j++){
                if(column < matrix[j][i]){
                    column = matrix[j][i];
                }
            }
            column_max.push_back(column);
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == row_min[i] && matrix[i][j] == column_max[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {

        return LuckyNumber(matrix);
    }
};