#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
set<ii> Q;
map<int, vector<ii>> E;
long long min_dist[10005];


void dijkstra(int s) {


  while (!Q.empty()) {

    // extract_min
    auto itr = Q.begin();
    ii p = *itr;
    int min_node = p.second;
    min_dist[min_node] = p.first;
    Q.erase(Q.begin());
    if (Q.empty()) break;

    // updating values of Q for attached nodes
    for (auto &x : E[min_node]) {
      // x.first is edge that min node is attached to
      // x.second is weight of the edge
      int node = x.first;
      int dist = x.second;
      if (min_dist[node] > min_dist[min_node] + dist) {
          auto f = Q.find(make_pair(min_dist[node], node));
          if (f != Q.end()) Q.erase(f);
          min_dist[node] = min_dist[min_node] + dist;
          Q.insert(make_pair(min_dist[node], node));
      }
    }
  }

  return;
}


int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, q, s;
  while (true) {
    cin >> n >> m >> q >> s;
    if (n == 0 && m == 0 && q == 0 && s == 0) break;


    E.clear(), Q.clear();
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      E[u].push_back(make_pair(v, w));
    }


    // initialising dist of source to 0 and rest to infty
    for (int i = 0; i < n; ++i) {
      if (i == s) Q.insert(make_pair(0, s));
      else Q.insert(make_pair(INT_MAX, i));
    }


    for (int i = 0; i < n; ++i) min_dist[i] = INT_MAX;

    // executing dijkstras algorithm on the source
    dijkstra(s);

    for (int case_num = 0; case_num < q; ++case_num) {
      int x;
      cin >> x;
      if (min_dist[x] >= INT_MAX || min_dist < 0) cout << "Impossible\n";
      else cout << min_dist[x] << "\n";
    }

    cout << "\n";

  }

  return 0;

}
