#include <everything.h>
using namespace std;

class Solution {
public:
  int getAns(vector<int> &piles, int h) {
    // int ans = BruteForce(piles, h);
    int ans = BinarySearch(piles, h);
    return ans;
  }
  int BinarySearch(vector<int> &piles, int h) {

    int l = 1;
    int r = *max_element(piles.begin(), piles.end());
    int res = r;
    while (l <= r) {

      int k = (r + l) / 2;
      long long total = 0;

      for (int pile : piles) {
        total += (pile + k - 1) / k;
      }

      if (total <= h) {
        res = k;
        r = k - 1;
      } else {
        l = k + 1;
      }
    }
    return res;
  }

  int BruteForce(vector<int> &piles, int h) {

    int k = 1;
    while (true) {

      long long totalTime = 0;
      for (int pile : piles) {
        totalTime += (pile + k - 1) / k;
      }
      if (totalTime <= h) {
        return k;
      }
      k++;
    }
  }
};

int main(void) {
  Solution obj;

  vector<int> piles = {3, 6, 7, 11};
  int h = 8;
  cout << obj.getAns(piles, h) << endl;
}
