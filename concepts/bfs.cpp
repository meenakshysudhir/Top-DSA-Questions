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
  display_list(adj_list);
}
