#include <everything.h>
using namespace std;

class Solution {
public:
  bool check(string s1, string s2) {
    vector<int> f1(26, 0), f2(26, 0);

    if (s1.size() > s2.size()) {
      return false;
    }

    for (char i : s1) {
      f1[i - 'a']++;
    }

    int l = 0;
    for (int r = 0; r < s2.size(); r++) {
      f2[s2[r] - 'a']++;

      if ((r - l + 1) == s1.size()) {
        if (areVectorsEqual(f1, f2))
          return true;
      }
      if ((r - l + 1 > s1.size())) {
        f2[s2[l]]--;
        l++;
      }
    }
    return false;
  }
};

int main(void) {
  Solution obj;
  string s1 = "ab";
  string s2 = "eidbaooo";
  cout << check.check(s1, s2) << endl;
}
