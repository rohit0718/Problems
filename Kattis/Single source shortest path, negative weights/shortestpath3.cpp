#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, m, q, s;

void bellman_ford(map<int, vector<ii>> edges, long long *min_path) {
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (edges[j].size() == 0) continue;
      if (min_path[j] == INT_MAX) continue;
      for (auto &x : edges[j]) {
        if (min_path[x.first] > min_path[j] + x.second)
          min_path[x.first] = min_path[j] + x.second;
      }
    }
  }

  for (int i = 1; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (edges[j].size() == 0) continue;
      if (min_path[j] == INT_MAX) continue;
      for (auto &x : edges[j]) {
        if (min_path[x.first] > min_path[j] + x.second) {
          min_path[x.first] = -1 * INT_MAX;
        }
      }
    }

  return;
}



int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  while (true) {
    cin >> n >> m >> q >> s;
    if (n == 0 && m == 0 && q == 0 && s == 0) break;

    // initialising everything
    long long min_path[1005];
    for (int i = 0; i < n; ++i) min_path[i] = INT_MAX;
    min_path[s] = 0;
    map<int, vector<ii>> edges;

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      edges[u].push_back(make_pair(v, w));
    }

    bellman_ford(edges, min_path);

    for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;
      if (min_path[x] >= INT_MAX) cout << "Impossible\n";
      else if (min_path[x] <= -1 * INT_MAX) cout << "-Infinity\n";
      else cout << min_path[x] << "\n";
    }

    cout << "\n";

  }

  return 0;
}
