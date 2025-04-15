#include <everything.h>
using namespace std;

bool check3by3(vector<vector<char>> board, int row, int col) {
  unordered_set<char> set;
  int count = 0;
  for (int i = row; i < row + 3; i++) {
    for (int j = col; j < col + 3; j++) {
      if (board[i][j] != '.') {
        set.insert(board[i][j]);
        count++;
      }
    }
  }
  if (count != set.size()) {
    return false;
  }
  return true;
}
int checkrows(vector<vector<char>> board) {

  unordered_map<int, unordered_set<char>> map;
  unordered_map<int, int> count;
  for (int i = 0; i < 9; i++) {
    count[i] = 0;
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        map[i].insert(board[i][j]);
        count[i]++;
      }
    }
  }

  int i = 0;
  for (const auto &[row, elements] : map) {
    if (count[row] != elements.size()) {
      return 0;
    }
  }
  return 1;
}
int main(void) {
  vector<vector<char>> board = {
      {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
      {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
      {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
      {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

  };
  int row = 0, col = 0;
  bool flag;
  // flag = check3by3(board, row, col);
  do {
    flag = check3by3(board, row, col);
    if (col != 6) {
      col += 3;
    } else {
      row += 3;
      col = 0;
    }
  } while (flag && row != 9);
  cout << flag << endl;

  int flagr = checkrows(board);
  cout << flagr << endl;
}
