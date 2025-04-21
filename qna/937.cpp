// reorder data in log files
#include <everything.h>
using namespace std;

int isAlpha(string s) {
  int i = 0;
  while (i < s.size() && s[i] != ' ')
    i++;
  i++;
  if (s[i] >= '0' && s[i] <= '9')
    return 0;
  return 1;
}
int main(void) {
  vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6",
                         "let2 own kit dig", "let3 art zero"};

  vector<pair<string, string>> letters;
  vector<string> dig;
  for (string s : logs) {
    if (isAlpha(s)) {
      int i = s.find(' ');
      letters.push_back({s.substr(i + 1), s.substr(0, i)});
    } else {
      dig.push_back(s);
    }
  }
  // sort()
  sort(letters.begin(), letters.end());
  reverse(letters.begin(), letters.end());
  reverse(dig.begin(), dig.end());

  for (auto &s : letters) {
    dig.push_back(s.second + " " + s.first);
  }
  reverse(dig.begin(), dig.end());
  for (string s : dig) {
    cout << s << endl;
  }
}
