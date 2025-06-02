#include <everything.h>
using namespace std;

class Solution {
public:
  vector<int> getAns(vector<int> &nums, int k) {
    unordered_map<int, int> count;

    int n = nums.size();
    vector<int> output;
    deque<int> q;
    int l = 0;

    for (int r = 0; r < nums.size(); r++) {

      while (!q.empty() && nums[q.back()] < nums[r]) {
        q.pop_back();
      }

      q.push_back(r);
      if (q.front() < l) {
        q.pop_front();
      }

      if ((r - l + 1) >= k) {
        output.push_back(nums[q.front()]);
        l++;
      }
    }
    return output;
  }
};

int main(void) {
  Solution obj;
  vector<int> question = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  vector<int> res = obj.getAns(question, k);
  for (int i : res) {
    cout << i << endl;
  }
}
