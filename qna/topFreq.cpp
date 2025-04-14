#include <everything.h>
using namespace std;

vector<int> nums = {1, 2, 2, 3, 3, 3};
int k = 2;
vector<int> res;

void sorting() {
  unordered_map<int, int> count;
  for (auto i : nums) {
    count[i]++;
  }
  vector<pair<int, int>> arr;
  for (const auto &i : count) {
    arr.push_back({i.second, i.first});
  }
  sort(arr.rbegin(), arr.rend());

  for (int i = 0; i < k; i++) {
    res.push_back(arr[i].second);
  }
  // Complexity is O(nlogn)
}

void minHeap() {
  unordered_map<int, int> map;
  for (auto i : nums) {
    map[i]++;
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      heap;

  for (auto &i : map) {
    heap.push({i.second, i.first});
    if (heap.size() > k) {
      heap.pop();
    }
  }
  for (int i = 0; i < k; i++) {
    res.push_back(heap.top().second);
    heap.pop();
  }
}

void bucketSort() {
  unordered_map<int, int> count;
  for (auto &i : nums) {
    count[i]++;
  }
  vector<vector<int>> freq(
      nums.size() +
      1); // the maximum frequency if the same no. repeats thru the array
  for (auto &i : count) {
    freq[i.second].push_back(i.first);
  }

  for (int i = nums.size() - 1; i >= 0; i--) {
    for (int j : freq[i]) {
      res.push_back(j);
      if (res.size() == k) {
        return;
      }
      // res.push_back(j);
    }
  }
}
int main(void) {
  cout << "1 - Sorting\n2 - Minheap\n3 - BucketSort\nChoice : ";
  int ch;
  cin >> ch;
  switch (ch) {

  case 1:
    sorting();
    break;
  case 2:
    minHeap();
    break;
  case 3:
    bucketSort();
    break;
  }
  for (auto i : res) {
    cout << i << endl;
  }
}
