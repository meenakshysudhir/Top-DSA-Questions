#include <everything.h>
using namespace std;

class Solution {
public:
  vector<int> dfs(int V, vector<int> list[]) {
    int vis[V] = {0};
    vis[0] = 1;
    stack<int> s;
    s.push(0);
    vector<int> dfs;
    while (!s.empty()) {
      int node = s.top();
      s.pop();
      dfs.push_back(node);
      vis[node] = 1;
      for (int i : list[node]) {
        if (!vis[i]) {
          s.push(i);
          vis[i] = 1;
        }
      }
    }
    return dfs;
  }
};
int main(void) {
  cout << "Enter the number of nodes and edges : ";
  int u, v, n, m;
  cin >> n >> m;
  cout << "Enter the edges : ";
  vector<int> list[n];
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    list[u - 1].push_back(v - 1);
    list[v - 1].push_back(u - 1);
  }
  Solution obj;
  vector<int> res = obj.dfs(n, list);
  for (int i : res) {
    cout << i + 1 << " ";
  }
}
