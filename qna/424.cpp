#include <everything.h>
using namespace std;

class Solution {
public:
  int getans(string s, int k) {
    unordered_map<char, int> count;
    int res = 0, maxf = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
      count[s[right]]++;
      maxf = max(maxf, count[s[right]]);
      if ((right - left + 1) - maxf > k) {
        count[s[left]]--;
        left++;
      } else {
        res = max(res, right - left + 1);
      }
    }

    return res;
  }
};

int main(void) {
  Solution obj;
  string s = "ABAB";
  cout << obj.getans(s, 0) << endl;
}
