#include <bits/stdc++.h>

using namespace std;
int dist[20005];

template <class T>
class graph{
  unordered_map<T, list<pair<T, int>>> m;

public:

  void add_edge(T u, T v, int w) {
    m[u].push_back(make_pair(v, w));
  }
  void print_adj(){
    for (auto i : m) {
      cout << i.first << "-->";
      for (auto j : i.second) {
        cout << "(" << j.first << "," << j.second << ")";
      }
      cout << "\n";
    }
  }
  void dijsktra(int src) {

    // setting all dist to infty except the source
    for (auto i : m) dist[i.first] = INT_MAX;
    dist[src] = 0;

    // initialising a set to extract_min
    set <pair<int, T>> s;
    s.insert(make_pair(0, src));

    while (!s.empty()) {

      // find the min value
      auto p = *(s.begin());
      T min_node = p.second;
      int node_dist = p.first;
      s.erase(s.begin());

      // iterate over neighbours of the current node
      for (auto neighbour : m[min_node]) {
          if (dist[neighbour.first] > neighbour.second + node_dist) {

            // add new value into set and remove old value
            auto f = s.find( make_pair(dist[neighbour.first],neighbour.first) );
            if (f != s.end()) s.erase(f);

            // update values of dist for the neighbouts
            dist[neighbour.first] = neighbour.second + node_dist;
            s.insert(make_pair(dist[neighbour.first], neighbour.first));

          }
      }

    }

  }

  int find_min(int node) {
    return dist[node];
  }

};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = -1, m = -1, q = -1, sr = -1;

  while (true) {
    cin >> n >> m >> q >> sr;
    if (n == 0 && m == 0 && q == 0 && sr == 0) break;

    graph<int> G;
    // adding the edges to graph G
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      G.add_edge(u, v, w);
    }

    G.dijsktra(sr);

    // printing ans
    for (int i = 0; i < q; ++i) {
      int x;
      cin >> x;
      if (G.find_min(x) == INT_MAX) cout << "Impossible\n";
      else cout << G.find_min(x) << "\n";
    }

    cout << "\n";
  }

  return 0;
}
