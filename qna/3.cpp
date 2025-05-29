#include <everything.h>
using namespace std;

// Longest substring without repeating characters
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int l = 0, maxLen = 0;
    for (int r = 0; r < s.size(); r++) {
      char c = s[r];
      map[c]++;
      if (map[c] > 1) {
        map[s[l]]--;
        l++;
      }
      maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
  }
};
int main(void) {
  string s = "abcabcbb";
  Solution obj;
  cout << obj.lengthOfLongestSubstring(s);
}
