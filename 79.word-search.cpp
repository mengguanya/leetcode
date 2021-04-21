/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
// @lc code=start
class Solution {
    vector< vector<char> > board;
    int row, column;
    string word;
    int len;
public:
    bool search(int i, int j, int cnt){
        if(cnt == len){
            return true;
        }
        char c = word[cnt];
        if(i < 0 || i >= row || j < 0 || j >= column || board[i][j] != c){
            return false;
        }
        board[i][j] = '#';
        bool res = 
            search(i + 1, j, cnt + 1) || \
            search(i - 1, j, cnt + 1) || \
            search(i, j + 1, cnt + 1) || \
            search(i, j - 1, cnt + 1);
        board[i][j] = c;
        return res;
    }
    bool exist(vector<vector<char> >& board, string word) {
        this->board = board;
        this->word = word;
        row = board.size();
        column = board[0].size();
        len = word.size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(search(i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end

