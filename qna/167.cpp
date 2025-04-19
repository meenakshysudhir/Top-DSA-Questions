#include <everything.h>
using namespace std;

int main(void) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  int left = 0;
  int right = nums.size() - 1;
  while (left < right) {
    if (nums[left] + nums[right] == target) {
      cout << left << " " << right << endl;
      break;
    } else if (nums[left] + nums[right] > target) {
      right--;
    } else {
      left++;
    }
  }
}
