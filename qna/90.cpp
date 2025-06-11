#include <everything.h>
using namespace std;

class Solution {
  vector<vector<int>> res;

  void f(int ind, vector<int> &nums, vector<int> &current) {
    res.push_back(current);

    for (int i = ind; i < nums.size(); i++) {
      if (i != ind && nums[i] == nums[i - 1])
        continue;
      current.push_back(nums[i]);
      f(i + 1, nums, current);
      current.pop_back();
    }
  }

public:
  vector<vector<int>> getAns(vector<int> &nums) {
    vector<int> current;
    sort(nums.begin(), nums.end());
    f(0, nums, current);
    return res;
  }
};

int main(void) {
  Solution obj;
  vector<int> q = {1, 2, 2};
  vector<vector<int>> ans = obj.getAns(q);
  for (auto i : ans) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
