class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        // sort the first row

        for (int i = 0; i < c; i++) {
            int row = 0;
            int col = i;

            vector<int> dia;

            while (row < r && col < c) {
                dia.push_back(mat[row][col]);
                row++;
                col++;
            }
            sort(dia.begin(), dia.end());

            row = 0;
            col = i;
            int k = 0;

            while (row < r && col < c) {
                mat[row][col] = dia[k];
                k++;
                row++;
                col++;
            }
        }

        // sort the col except first one

        for(int j=1; j<r; j++){
            int row = j;
            int col = 0;

            vector<int> dia;

            while(row < r && col < c){
                dia.push_back(mat[row][col]);

                row++;
                col++;

            }

            sort(dia.begin(), dia.end());

            row = j;
            col = 0;

            int k = 0;
            

            while(row < r && col < c){

                mat[row][col] = dia[k];
                k++;
                row++;
                col++;

            }
            


        }

        return mat;
    }
};