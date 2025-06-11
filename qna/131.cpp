#include <everything.h>
using namespace std;

class Solution {
  vector<vector<string>> res;
  int Pallindrome(string s, int ind, int i) {
    for (int j = 0; j <= (i - ind) / 2; j++) {
      if (s[ind + j] != s[i - j]) {
        // cout << s[j] << " " << s[j - i - 1] << endl;
        return 0;
      }
    }
    return 1;
  }
  void Recursion(int ind, string s, vector<string> &current) {
    if (ind == s.length()) {

      res.push_back(current);
      return;
    }

    for (int i = ind; i < s.size(); i++) {

      if (Pallindrome(s, ind, i)) {

        current.push_back(s.substr(ind, (i - ind + 1)));
        Recursion(i + 1, s, current);
        current.pop_back();
      }
    }
  }

public:
  vector<vector<string>> getAns(string s) {
    vector<string> current;
    Recursion(0, s, current);
    return res;
  }
};

int main(void) {
  Solution obj;
  string s = "aab";
  vector<vector<string>> res = obj.getAns(s);
  for (auto i : res) {
    for (string str : i) {
      cout << str << " ";
    }
    cout << endl;
  }
}
