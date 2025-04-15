#include <everything.h>
using namespace std;

vector<string> input = {"we", "dont", "say", ",", "anything"};
vector<string> output;
string encoded;
void encode() {
  vector<int> sizes;

  for (auto &i : input) {
    // cout << i.size() << " ";
    sizes.push_back(i.size());
  }
  encoded = "";
  for (int i : sizes) {
    encoded += to_string(i);
    encoded += "$";
  }
  encoded += "#";

  for (string &el : input) {
    encoded += el;
  }
  cout << encoded << endl;
}
void decode() {
  string temp = encoded;
  vector<int> sizes;
  int i = 0, num;
  string len;
  // save the length of each word in a len array
  while (temp[i] != '#') {

    if (temp[i] != '$') {
      len += temp[i];
    } else {
      sizes.push_back(stoi(len));
      len = "";
    }
    i++;
  }
  i++;
  for (int sz : sizes) {
    output.push_back(temp.substr(i, sz));
    i += sz;
  }
  for (auto el : output) {
    cout << el << " ";
  }
}
int main(void) {
  encode();
  decode();
}
