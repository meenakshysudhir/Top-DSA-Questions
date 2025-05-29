#include <everything.h>
using namespace std;

// Greedy approach
class Solution {
public:
  int canComplete(vector<int> &A, vector<int> &B) {
    int n = A.size();

    int total = 0, curr = 0, start;
    for (int i = 0; i < n; i++) {
      total += A[i] - B[i];
      curr += A[i] - B[i];

      if (curr < 0) {
        start = i + 1;
        curr = 0;
      }
    }
    return (total >= 0) ? start : -1;
  }
};
int main(void) {
  Solution obj;
  vector<int> A = {1, 2}, B = {2, 1};
  cout << obj.canComplete(A, B) << endl;
}
