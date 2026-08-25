class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> seenrow;
            unordered_set<char> seencol;
            for(int k=0;k<9;k++){
                if (board[i][k] != '.') {
                if (seenrow.find(board[i][k]) != seenrow.end()) return false;
                seenrow.insert(board[i][k]);
                }

                if (board[k][i] != '.') {
                    if (seencol.find(board[k][i]) != seencol.end()) return false;
                    seencol.insert(board[k][i]);
                }
            }
        }
        
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    int r = (i/3)*3+j;
                    int c = (i%3)*3+k;
                    if(board[r][c] == '.') continue;
                    if(seen.find(board[r][c]) != seen.end()) return false;
                    seen.insert(board[r][c]);
                }   
            }   
        }
        return true;
    }
};
