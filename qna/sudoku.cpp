#include <everything.h>
using namespace std;

int check3by3(vector<vector<char>> board) {

  unordered_map<int, unordered_set<int>> map;
  unordered_map<int, int> count;
  int cn = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] != '.') {
        if (i < 3 && j < 3) {
          count[0]++;
          map[0].insert(board[i][j]);
        } else if (i < 3 && j < 6) {
          count[1]++;
          map[1].insert(board[i][j]);

        } else if (i < 3 && j < 9) {
          count[2]++;
          map[2].insert(board[i][j]);
        } else if (i < 6 && j < 3) {
          map[3].insert(board[i][j]);
          count[3]++;
        } else if (i < 6 && j < 6) {
          map[4].insert(board[i][j]);
          count[4]++;
        } else if (i < 6 && j < 9) {
          map[5].insert(board[i][j]);
          count[5]++;
        } else if (i < 9 && j < 3) {
          map[6].insert(board[i][j]);
          count[6]++;
        } else if (i < 9 && j < 6) {
          map[7].insert(board[i][j]);
          count[7]++;
        } else {
          map[8].insert(board[i][j]);
          count[8]++;
        }
      }
    }
  }
  for (const auto &[i, elements] : map) {
    if (count[i] != elements.size()) {
      return 0;
    }
  }
  return 1;
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

  for (const auto &[row, elements] : map) {
    if (count[row] != elements.size()) {
      return 0;
    }
  }
  return 1;
}

int checkcols(vector<vector<char>> board) {
  unordered_map<int, unordered_set<char>> map;
  unordered_map<int, int> count;
  for (int i = 0; i < 9; i++) {
    // first column
    count[i] = 0;
    for (int j = 0; j < 9; j++) {
      if (board[j][i] != '.') {
        map[i].insert(board[j][i]);
        count[i]++;
      }
    }
  }
  for (const auto &[col, elements] : map) {
    if (count[col] != elements.size()) {
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
  int flag = check3by3(board);
  cout << flag << endl;
  int flagr = checkrows(board);
  cout << flagr << endl;
  int flagc = checkcols(board);
  cout << flagc << endl;
  if (flag && flagr && flagc) {
    cout << "Valid soduku" << endl;
  } else {
    cout << "Invalid soduku" << endl;
  }
}
