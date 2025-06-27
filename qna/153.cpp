#include <everything.h>
using namespace std;

class Solution {
public:
  int getAns(vector<int> &nums) {
    int res = BinarySearch(nums);
    return res;
  }
  int BinarySearch(vector<int> &nums) {

    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {

      int m = (l + r) / 2;

      if (nums[m] > nums[r]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return nums[r];
  }
};

int main(void) {
  Solution obj;
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << obj.getAns(nums) << endl;
}
