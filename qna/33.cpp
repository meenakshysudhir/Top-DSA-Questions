#include <everything.h>
using namespace std;

class Solution {
public:
  int BinarySearch(vector<int> &nums, int target) {

    int l = 0, r = nums.size() - 1;

    while (l < r) {

      int m = (l + r) / 2;

      if (nums[m] >= nums[r]) {
        l = m + 1;
      } else {
        r = m;
      }
    }

    int pivot = l;
    r = nums.size() - 1;
    l = 0;
    // cout << "pivot" << pivot << endl;
    if (nums[pivot] <= target && target <= nums[r]) {
      l = pivot;
    } else {
      r = pivot - 1;
    }
    // cout << "l and r" << l << r << endl;
    while (l <= r) {

      int m = (l + r) / 2;
      // cout << m << endl;
      if (nums[m] == target) {
        return m;
      } else if (nums[m] > target) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return -1;
  }
};

int main(void) {
  Solution obj;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  cout << obj.BinarySearch(nums, target) << endl;
}
