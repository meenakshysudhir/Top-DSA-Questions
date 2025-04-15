#include <everything.h>
// #include <iostream>
// #include <algorithm>
// #include <vector>
using namespace std;

int main(void) {
  int arr[] = {30, 40, 10, 80, 5, 12, 70};
  int k = 4; // k no. of buckets

  int maxEl = arr[0];
  int arr_size = sizeof(arr) / sizeof(int);
  for (int i = 0; i < arr_size; i++) {
    maxEl = max(maxEl, arr[i]);
  }
  maxEl++;

  // initializing buckets
  vector<int> buckets[k];
  for (int i = 0; i < arr_size; i++) {
    int buckInd = (k * arr[i]) / maxEl;
    buckets[buckInd].push_back(arr[i]);
  }

  for (int i = 0; i < k; i++) {
    sort(buckets[i].begin(), buckets[i].end());
  }

  int ind = 0;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < buckets[i].size(); j++) {
      arr[ind++] = buckets[i][j];
    }
  }

  // displaying sorted array
  for (int i = 0; i < arr_size; i++) {
    cout << arr[i] << " ";
  }
}
