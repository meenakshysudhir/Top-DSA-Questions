#include <everything.h>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // uses Kadane's algorithm
    int buy = prices[0];
    int profit = 0, n = prices.size();
    for (int i = 1; i < n; i++) {
      if (prices[i] < buy) {
        buy = prices[i];
      } else if ((prices[i] - buy) > profit) {
        profit = prices[i] - buy;
      }
    }
    return profit;
  }
};
int main(void) {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  Solution obj;
  cout << obj.maxProfit(prices) << endl;
}
