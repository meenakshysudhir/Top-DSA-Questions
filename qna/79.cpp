#include <everything.h>
using namespace std;

class Solution {
  int row, col;
  // set<pair<int, int>> visited;

  bool dfs(vector<vector<char>> &board, string word, int ind, int r, int c) {

    if (ind == word.length())
      return true;
    // if (r >= row || c >= col || r < 0 || c < 0 || board[r][c] != word[ind] ||
    //     visited.count({r, c})) {
    //   return false;
    // }
    if (r >= row || c >= col || r < 0 || c < 0 || board[r][c] != word[ind] ||
        board[r][c] == '#') {
      return false;
    }

    // visited.insert({r, c});
    board[r][c] = '#';
    bool res = dfs(board, word, ind + 1, r + 1, c) ||
               dfs(board, word, ind + 1, r - 1, c) ||
               dfs(board, word, ind + 1, r, c + 1) ||
               dfs(board, word, ind + 1, r, c - 1);
    // visited.erase({r, c});
    board[r][c] = word[ind];
    return res;
  }

public:
  bool getAns(vector<vector<char>> &board, string word) {
    row = board.size();
    col = board[0].size();
    for (int r = 0; r < row; r++) {
      for (int c = 0; c < col; c++) {
        if (dfs(board, word, 0, r, c)) {
          return true;
        }
      }
    }
    return false;
  }
};

int main(void) {
  Solution obj;
  string word = "ABCB";
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

  cout << obj.getAns(board, word) << endl;
}
