#include <bits/stdc++.h>

using namespace std;

const int MX = 200005;

int n, log_n, level[MX], parent[19][MX];
vector<int> adj[MX];

int lca(int i, int j) {

  if (level[i] > level[j]) swap(i, j);

  // bringing j to same level as i
  int diff = level[j] - level[i];
  for (int k = 0; diff; k++) {
    if (diff & 1) j = parent[k][j];
    diff >>= 1;
  }

  if (i == j) return i;

  // moving both up together
  for (int ptr = log_n; ptr >= 0; --ptr) {
    if (parent[ptr][i] != parent[ptr][j]) {
      i = parent[ptr][i];
      j = parent[ptr][j];
    }
  }

  return parent[0][i];

}

int _dist(int i, int j) {
  return level[i] + level[j] - (2 * level[lca(i, j)]) + 1;
}

void dfs(int i, int l) {
  level[i] = l;
  for (auto x : adj[i]) {
    if (level[x] == -1) {
      parent[0][x] = i;
      dfs(x, l + 1);
    }
  }
  return;
}


int main() {
  cin >> n;
  log_n = log2(n);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  memset(level, -1, sizeof(level));
  memset(parent, -1, sizeof(parent));
  dfs(0, 0);

  // building the binary lifting table
  for (int i = 1; i <= log_n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (level[j] >= (1 << i)) {
        int mid = parent[i - 1][j];
        parent[i][j] = parent[i - 1][mid];
      }
    }
  }

  long long ans = 0LL;


  for (int i = 1; i <= n / 2; ++i) {
    for (int j = i * 2; j <= n; j += i) {
       ans += _dist(i - 1, j - 1);
    }
  }

  cout << ans;

  return 0;

}
