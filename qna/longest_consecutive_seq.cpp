#include <everything.h>

using namespace std;

int main(void) {
  vector<int> nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  unordered_set<int> set;
  unordered_map<int, int> map;
  for (int i : nums) {
    set.insert(i);
  }
  int res = 0;
  for (int i : nums) {
    if (!map[i]) {
      map[i] = map[i - 1] + map[i + 1] + 1;
      map[i - map[i - 1]] = map[i];
      map[i + map[i + 1]] = map[i];
      res = max(res, map[i]);
    }
  }
  cout << res << endl;
}
