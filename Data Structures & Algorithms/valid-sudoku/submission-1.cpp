class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int k=0;k<9;k++){
                if(board[i][k] == '.') continue;
                if(seen.find(board[i][k]) != seen.end()) return false;
                seen.insert(board[i][k]);
            }

        }
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int k=0;k<9;k++){
                if(board[k][i] == '.') continue;
                if(seen.find(board[k][i]) != seen.end()) return false;
                seen.insert(board[k][i]);
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
