// valid pallindrome 2 680

#include <everything.h>
using namespace std;

int main(void) {
  string str = "aba";
  int len = str.size();
  vector<string> possible;
  cout << len << endl;
  string temp;
  for (int i = 0; i < len - 1 / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      // cout << i << endl;

      // cout << str.erase(i, 1);
      temp = str;
      possible.push_back(temp.erase(i, 1));
      temp = str;
      possible.push_back(temp.erase(len - i - 1, 1));
      break;
    }
  }
  if (possible.size() == 0) {
    temp = str;
    int ind = (len - 1) / 2;
    // cout << temp.erase(ind,)
    possible.push_back(temp.erase(ind, 1));
  }
  vector<string> res;
  int flag;
  len = len - 1;
  for (string i : possible) {
    cout << i << endl;
    flag = 0;
    for (int j = 0; j < len - 1 / 2; j++) {
      if (i[j] != i[len - j - 1]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      res.push_back(i);
    }
  }
  for (string i : res) {
    cout << "pallindrome : " << i << endl;
  }
}
