// Rotting Oranges

#include <everything.h>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> grid) {
    int res = 0;
    int time = 0;
    int max_row = grid.size();
    int max_col = grid[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    unordered_set<pair<int, int>> visited;

    for (int i = 0; i < max_row; i++) {
      for (int j = 0; j < max_col; j++) {
        if (visited.find({i, j}) == visited.end && grid[i][j] == 2) {
          bfs(res, grid, directions, visited, i, j, max_row, max_col);
        }
      }
    }
  }

private:
  void bfs(int &res, vector<vector<int>> &grid,
           vector<pair<int, int>> directions,
           unordered_set<pair<int, int>> &visited, int i, int j, int max_row,
           int max_col) {
    queue q;
    visited.insert({i, j});
    q.push({i, j});
    while (!q.empty()) {
      auto [cr, cc] = q.front();
      q.pop();
      for (auto [inc_r, inc_c] : directions) {
        int new_row = cr + inc_r;
        int new_col = cc + inc_c;
        if (new_row < max_row && new_col < max_col &&
            (visited.find(new_row, new_col) == visited.end()) &&
            grid[new_row][new_col] == 1) {
          visited.insert(new_row, new_col);
          q.push({new_col, new_row});
          res++;
        }
      }
    }
  }
};
int main(void) {
  vector<vector<int>> grind = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  Solution obj;
  int res = obj.orangesRotting(grind);
}
