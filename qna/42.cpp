#include <everything.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;
    int leftmax = 0, rightmax = 0, res = 0;

    while (left < right) {
      if (height[left] <= height[right]) {
        if (leftmax > height[left]) {
          res += leftmax - height[left];
        } else {
          leftmax = height[left];
        }
        left++;
      } else {
        if (rightmax > height[right]) {
          res += rightmax - height[right];
        } else {
          rightmax = height[right];
        }
        right--;
      }
    }
    return res;
  }
};
int main(void) {
  Solution obj;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << obj.trap(height) << endl;
}
