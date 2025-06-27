#include <everything.h>
using namespace std;

class Solution {
  vector<string> res;
  vector<string> map = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "qprs", "tuv", "wxyz"};

  void Recursion(int i, string curr, string &digits) {
    if (curr.length() == digits.length()) {
      res.push_back(curr);
      return;
    }
    string chars = map[digits[i] - '0'];
    for (char c : chars) {
      Recursion(i + 1, curr + c, digits);
    }
  }

public:
  vector<string> getAns(string digits) {
    if (digits.empty())
      return res;
    Recursion(0, "", digits);
    return res;
  }
};

int main(void) {
  Solution obj;
  string digits = "23";
  vector<string> res = obj.getAns(digits);
  for (string i : res) {
    cout << i << endl;
  }
}
