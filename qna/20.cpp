#include <everything.h>
using namespace std;

class Solution {
public:
  bool getAns(string s) {
    stack<char> s;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
        s.push(s[i]);
      }
    }
  }
};

int main(void) {
  Solution obj;
  cout << obj.getAns("()") << endl;
}
