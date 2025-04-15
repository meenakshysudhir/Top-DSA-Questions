#include <everything.h>
using namespace std;

int main(void) {
  unordered_map<int, unordered_set<char>> map;
  map[0].insert('a');
  map[0].insert('b');
  map[0].insert('a');

  for (auto &[m, ch] : map) {
    for (char c : ch) {
      cout << c << endl;
    }
  }
}
