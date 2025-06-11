#include <everything.h>
using namespace std;

class Solution {
  void Subsets(vector<int> &nums, vector<vector<int>> &res, vector<int> current,
               int n, int ind) {
    if (ind == n) {
      res.push_back(current);
      return;
    }
    current.push_back(nums[ind]);
    Subsets(nums, res, current, n, ind + 1);

    current.pop_back();
    Subsets(nums, res, current, n, ind + 1);
  }

public:
  vector<vector<int>> getAns(vector<int> &nums) {

    vector<vector<int>> res;
    vector<int> current;
    Subsets(nums, res, current, nums.size(), 0);
    return res;
  }
};

int main(void) {
  Solution obj;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = obj.getAns(nums);

  for (auto i : res) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
