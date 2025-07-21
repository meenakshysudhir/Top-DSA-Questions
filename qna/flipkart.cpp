#include <everything.h>
using namespace std;

class Solution {
public:
  int getAns(string str) {
    int len = str.length();
    int ind = 0;
    unordered_map<int, char> for (int i = 0; i < len; i++) {
      if ((str[i] >= 'a' && str[i] <= z) || (str[i] >= 'A' && str[i] <= 'Z')) {
        continue;
      } else {
      }
    }
  }
};

int main(void) {
  Solution obj;
  string str = "27a - 20x + 2";
  cout << obj.getAns(str) << endl;
}
