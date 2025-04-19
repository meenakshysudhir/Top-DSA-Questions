#include <everything.h>
using namespace std;

int palindrome(string s, int left, int right) {
  // cout << s << " " << left << " " << right << endl;
  while (left < right) {
    if (s[left] != s[right]) {
      return 0;
    }
    left++;
    right--;
  }
  // cout << s << " is palindrome" << endl;
  return 1;
}
int main(void) {
  string s = "abha";
  int right = s.size() - 1;
  int left = 0, check;
  while (left < right) {
    if (s[left] != s[right]) {
      check = palindrome(s, left + 1, right) || palindrome(s, left, right - 1);

      if (!check) {
        cout << "No palindrome" << endl;
      }
      return 0;
    }
    left++;
    right--;
  }
  cout << "Palindrome" << endl;
}
