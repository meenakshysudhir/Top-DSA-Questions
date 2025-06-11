#include <everything.h>
using namespace std;

class Solution {
  vector<vector<int>> res;
  void Combination2(int ind, vector<int> &nums, vector<int> &current,
                    int target) {

    if (target == 0) {
      res.push_back(current);
      return;
    }

    for (int i = ind; i < nums.size(); i++) {
      if (i > ind && nums[i] == nums[i - 1])
        continue;
      if (nums[i] > target)
        break;

      current.push_back(nums[i]);
      Combination2(i + 1, nums, current, target - nums[i]);
      current.pop_back();
    }
  }

public:
  vector<vector<int>> getAns(vector<int> &nums, int target) {
    vector<int> current;
    sort(nums.begin(), nums.end());
    Combination2(0, nums, current, target);
    return res;
  }
};

int main(void) {
  Solution obj;
  vector<int> q = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  vector<vector<int>> r = obj.getAns(q, target);
  for (auto i : r) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
