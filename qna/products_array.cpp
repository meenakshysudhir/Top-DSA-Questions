// Given an integer array nums, return an array output where output[i] is the
// product of all the elements of nums except nums[i]. Each product is
// guaranteed to fit in a 32-bit integer. Follow-up: Could you solve it inO(n)
// time without using the division operation?

#include <everything.h>
using namespace std;

int main(void) {
  // vector<int> nums = {1, 2, 4, 6};
  vector<int> nums = {-1, 0, 1, 2, 3};
  vector<int> res;

  int temp_prod = 1;
  vector<int> pref;
  vector<int> suff;
  for (int i = 0; i < nums.size(); i++) {
    if (i == 0) {
      pref.push_back(temp_prod);
    } else {
      temp_prod *= nums[i - 1];
      // cout << temp_prod << endl;
      pref.push_back(temp_prod);
    }
  }
  // suffix vector
  int len = nums.size() - 1;
  for (int i = len; i >= 0; i--) {
    if (i == len) {
      temp_prod = 1;
      suff.push_back(temp_prod);
    } else {
      temp_prod *= nums[i + 1];
      suff.push_back(temp_prod);
    }
  }
  cout << "Prefix : " << endl;
  for (int i : pref) {
    cout << i << " ";
  }
  cout << endl << "Suffix : " << endl;
  for (int i : suff) {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 0; i <= len; i++) {
    res.push_back(pref[i] * suff[len - i]);
  }
  for (int i : res) {
    cout << i << " ";
  }
}
