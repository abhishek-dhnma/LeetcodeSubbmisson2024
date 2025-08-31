class Solution {
public:

    bool isValid( vector<vector<char>> & board,char digt, int i, int  j){

        int n =9;

  // ROW AND COLUMN CHECK IS DIGIT IS PRESENT OPR NOT
    // SUDOKU RULE 1 : DIGIT SHOULD NOT PRESENT IN ITS ROW AND COLUMN 
    for (int k = 0; k < n; k++) {
        if (board[i][k] ==  digt || board[k][j] == digt) {
            return false;
        }
    }

    // CHECK 3X3 SQUARES IF THAT DIGIT IS PRESENT OR NOT
    // SUDOKU RULE 2 : DIGIT SHOULD NOT PRESENT IN ITS SQUARE
    // SUDOKU (9x9) IS DIVIDED IN 9 PARTS EACH WITH 3X3 SIZE
    int bound = sqrt(n);
    int sx = i / bound * bound;
    int sy = j / bound * bound;

    for (int i = sx; i < sx + bound; i++) {
        for (int j = sy; j < sy + bound; j++) {
            if (board[i][j] == digt) {
                return false;
            }
        }
    }

    return true;


    }



    bool sudokuSolver(vector<vector<char>>& board , int n, int i, int j) {

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {

                if (board[i][j] == '.') {

                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, d, i, j))
                        {
                            // do
                            board[i][j] = d;
                            // explore
                            if (sudokuSolver(board, 9, i, j)) {
                                return true;
                            }
                            // undo - backtrack
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {

        sudokuSolver(board, 9, 0, 0);
    }
};