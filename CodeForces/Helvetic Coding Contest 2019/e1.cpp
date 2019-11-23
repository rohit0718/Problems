#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,int> iii;

class kruskals {
  public:
    vector<int> p;
    vector<int> sz;
    int n;

    kruskals(int _n) : n(_n) {
      p.resize(n);
      sz.resize(n, 1);
      iota(p.begin(), p.end(), 0);
    }

    inline int find(int x) {
      return (x == p[x] ? x : (p[x] = find(p[x])));
    }

    inline void unite(int x, int y) {
      x = find(x);
      y = find(y);
      if (sz[x] > sz[y]) {
        p[y] = x;
        sz[x] += sz[y];
      }
      else {
        p[x] = y;
        sz[y] += sz[x];
      }
    }

};

int main() {
  int n, m;
  cin >> n >> m;

  kruskals g(n);
  vector<iii> e;

  int t1, t2;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    if (i == 0) t1 = u, t2 = v;
    else e.push_back(make_tuple(w, u, v));
  }

  // terminating condition: cycle detected, and both t1 and t2 in cycle.
  sort(e.begin(), e.end());

  for (int i = 0; i < m - 1; ++i) {
    int u = get<1>(e[i]);
    int v = get<2>(e[i]);
    if (g.find(u) != g.find(v)) g.unite(u, v);
    if (g.find(t1) == g.find(t2)) {
      cout << get<0>(e[i]);
      return 0;
    }
  }

  cout << 1000000000;
  return 0;
}
