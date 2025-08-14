class Solution {
public:

    bool isValidSubgrid(vector<vector<char>>& board,int sr,int er, int sc,int ec){
                unordered_set<char> sett;
        for(int r=sr; r<=er; r++){
            
            
            for(int c=sc; c<=ec; c++ ){
                char num = board[r][c];
                if(num == '.'){
                    continue;
                }

                if(sett.find(num) != sett.end()){
                    return false;
                }
                    sett.insert(num);
                
            }

            
        }

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {


     vector<unordered_set<char>> rows(9), cols(9), boxes(9);
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char num = board[r][c];
                if (num == '.') continue;
                if (num < '1' || num > '9') return false;
                int box_idx = (r / 3) * 3 + c / 3;
                if (rows[r].count(num) || cols[c].count(num) || boxes[box_idx].count(num)) return false;
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[box_idx].insert(num);
            }
        }
        return true;
    }
};