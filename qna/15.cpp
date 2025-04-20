/*Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.Notice that the solution set must not contain duplicate
 * triplets.*/

#include <everything.h>
using namespace std;

int main(void) {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  int j, k, count = 0, target;
  sort(nums.begin(), nums.end());
  // cout << "fes";
  vector<vector<int>> res;
  for (int i = 0; i < nums.size(); i++) {
    j = i + 1;
    k = nums.size() - 1;
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    while (j < k) {
      target = nums[i] + nums[j] + nums[k];
      if ((target == 0)) {

        res.push_back({nums[i], nums[j], nums[k]});

        j++;
        while (j < k && nums[j] == nums[j - 1])
          j++;
      } else if (target > 0) {
        k--;
      } else {
        j++;
      }
    }
  }

  for (auto i : res) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}
