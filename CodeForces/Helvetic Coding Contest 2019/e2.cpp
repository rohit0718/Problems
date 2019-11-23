#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> iii;
typedef pair<int, int> ii;
int lvl[100005];

class kruskals{
  public:
    int p[14][100005];
    vector<int> sz;

    kruskals(int n) {
      sz.resize(n, 1);
      memset(p, -1, sizeof(p));
      for (int i = 0; i < n; ++i) p[0][i] = i;
    }

    inline int find(int x) {
      return (x == p[0][x] ? x : (p[0][x] = find(p[0][x])));
    }

    inline void unite(int x, int y) {
      int a = find(x);
      int b = find(y);
      if (sz[a] > sz[b]) {
        p[0][b] = a;
        sz[a] += sz[b];
      }
      else {
        p[0][a] = b;
        sz[b] += sz[a];
      }
    }
};

void dfs(int s, int l) {
  lvl[s] = l;
  for (auto x : adj[s]) {
    if (lvl[x] == -1) {
      dfs(x, l + 1);
    }
  }
  return;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  kruskals g(n);
  vector<iii> e;
  vector<int> adj[100005];

  int u1, v1;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    e.push_back(make_tuple(w, u, v));
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // first dfs through to get levels
  memset(lvl, -1, sizeof(lvl));
  dfs(0,0);

  sort(e.begin(), e.end());

  vector<ii> non_mst;

  for (auto x : e) {
    if (g.find(get<1>(x)) != g.find(get<2>(x))) {
      g.unite(get<1>(x), get<2>(x));
    }
    else non_mst.push_back(make_pair(get<1>(x), get<2>(x)));
  }

  // build binary table
  for (int i = 1; i <= (int) log2(n); ++i) {
    for (int j = 0; j < n; ++j) {

      p[i][j] = p[i - 1][p[i - 1][j]];
    }
  }

  // loop through non_mst and cout ans

  cout << 1000000000;

  return 0;
}
