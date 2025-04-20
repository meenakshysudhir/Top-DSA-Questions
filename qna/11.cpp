/*You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i,
height[i]).Find two lines that together with the x-axis form a container, such
that the container contains the most water.Return the maximum amount of water a
container can store. Notice that you may not slant the container.*/

#include <everything.h>
using namespace std;

int main(void) {
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // vector<int> height = {1, 1};
  int i = 0, res = 0, max_prod, n = height.size();
  int k = n - 1;
  while (i < n) {
    max_prod = min(height[i], height[k]) * abs(i - k);
    res = max(res, max_prod);
    if (height[i] > height[k])
      k--;
    else
      i++;
  }
  cout << res << endl;
}
