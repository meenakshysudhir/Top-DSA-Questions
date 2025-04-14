#include <everything.h>
using namespace std;

// vector<int> nums = {1, 2, 2, 3, 3, 3};
vector<int> nums = {7, 7};
int k = 1;
vector<int> res;

vector<int> sorting() {
  unordered_map<int, int> count;
  vector<int> res;
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
  return res;
}

vector<int> minHeap() {
  vector<int> res;
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
  return res;
}

vector<int> bucketSort() {
  vector<int> res;
  unordered_map<int, int> count;
  for (auto &i : nums) {
    count[i]++;
  }

  vector<vector<int>> freq(
      nums.size() +
      1); // the maximum frequency if the same no. repeats thru the array
  for (auto i : count) {
    freq[i.second].push_back(i.first);
  }

  for (int i = freq.size() - 1; i >= 0; i--) {
    for (int j : freq[i]) {
      res.push_back(j);
      // cout << j << endl;
      if (res.size() == k) {
        return res;
      }
      // res.push_back(j);
    }
  }
  return res;
}
int main(void) {
  cout << "1 - Sorting\n2 - Minheap\n3 - BucketSort\nChoice : ";
  int ch;
  vector<int> result;
  cin >> ch;
  switch (ch) {

  case 1:
    result = sorting();
    break;
  case 2:
    result = minHeap();
    break;
  case 3:
    result = bucketSort();
    break;
  }
  for (auto i : result) {
    cout << i << endl;
  }
}
