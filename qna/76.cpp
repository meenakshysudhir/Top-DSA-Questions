#include <everything.h>
#include <string.h>
using namespace std;

class Solution {
public:
  string getAns(string s, string t) {
    if (s.length() < t.length()) {
      return "";
    }
    unordered_map<char, int> windowFreq, targetFreq;
    int have = 0, l = 0, minLen = INT_MAX, minLeft = 0;

    for (auto i : t) {
      targetFreq[i]++;
    }
    int need = targetFreq.size();

    for (int r = 0; r < s.size(); r++) {
      windowFreq[s[r]]++;

      if (targetFreq.count(s[r]) && windowFreq[s[r]] == targetFreq[s[r]]) {
        have++;
      }

      while (have == need) {
        if ((r - l + 1) < minLen) {
          minLeft = l;
          minLen = r - l + 1;
        }

        windowFreq[s[l]]--;
        if (targetFreq.count(s[l]) && windowFreq[s[l]] < targetFreq[s[l]]) {

          have--;
        }
        l++;
      }
    }
    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
  }
};

int main(void) {
  Solution obj;
  string s = "ADOBECODEBANC", t = "ABC";
  cout << obj.getAns(s, t) << endl;
}
