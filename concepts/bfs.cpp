#include <everything.h>
using namespace std;

void display_list(vector<vector<int>> list) {
  for (auto i : list) {
    for (int j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
}

class Solution {
public:
  vector<int> bfs(int V, vector<vector<int>> list) {
    int vis[V + 1] = {0};
    vis[1] = 1;
    vector<int> bfs;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      for (int i : list[node]) {
        if (!vis[i]) {
          q.push(i);
          vis[i] = 1;
        }
      }
    }
    return bfs;
  }
};

int main(void) {
  cout << "Enter the number of nodes and no. of edges : ";
  int n, m, u, v;
  cin >> n >> m;
  cout << "Enter the edges : " << endl;
  vector<vector<int>> adj_list;
  adj_list.resize(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
  }
  // display_list(adj_list);
  Solution obj;
  vector<int> res = obj.bfs(n, adj_list);
  for (int i : res) {
    cout << i << " ";
  }
}
