#include <everything.h>
using namespace std;

class Solution {
  vector<vector<int>> res;
  void Recursion(vector<int> freq, vector<int> &nums, vector<int> ds) {

    if (ds.size() == nums.size()) {
      res.push_back(ds);
      // cout << "d";
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!freq[i]) {
        freq[i] = 1;
        // cout << "ew" << endl;
        ds.push_back(nums[i]);
        Recursion(freq, nums, ds);
        freq[i] = 0;
        ds.pop_back();
      }
    }
  }

  void swappingMethod(int ind, vector<int> &nums) {
    if (ind == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = ind; i < nums.size(); i++) {
      swap(nums[ind], nums[i]);
      swappingMethod(ind + 1, nums);
      swap(nums[ind], nums[i]);
    }
  }

public:
  vector<vector<int>> getAns(vector<int> nums) {
    vector<int> ds;
    vector<int> freq(nums.size(), 0);
    // Recursion(freq, nums, ds);
    swappingMethod(0, nums);
    return res;
  }
};

int main(void) {
  Solution obj;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res = obj.getAns(nums);
  for (auto set : res) {
    for (int i : set) {
      cout << i << " ";
    }
    cout << endl;
  }
}
