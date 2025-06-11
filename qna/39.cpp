#include <everything.h>
using namespace std;

class Solution {
  void Combination(int ind, vector<int> &candidates, vector<vector<int>> &res,
                   int target, vector<int> &current) {

    if (ind == candidates.size()) {
      if (target == 0) {
        res.push_back(current);
      }
      return;
    }

    if (candidates[ind] <= target) {
      current.push_back(candidates[ind]);
      Combination(ind, candidates, res, target - candidates[ind], current);
      current.pop_back();
    }
    Combination(ind + 1, candidates, res, target, current);
  }

public:
  vector<vector<int>> getAns(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> current;
    Combination(0, candidates, res, target, current);
    return res;
  }
};

int main(void) {
  Solution obj;
  vector<int> q = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> res = obj.getAns(q, target);
  for (auto i : res) {
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
