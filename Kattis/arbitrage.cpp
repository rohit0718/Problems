#include <bits/stdc++.h>

using namespace std;

typedef tuple<int,int,long double> iii;
int C;
const long double INF = 1e9;
long double dist[40000];
unordered_map<string, int> label;

int bellman_ford(vector<iii> &edges) {
  for (int i = 0; i < C - 1; ++i) {
    for (auto x : edges) {
      //if (dist[get<0>(x)] == INF) continue;
      if (dist[get<0>(x)] + get<2>(x) < dist[get<1>(x)]) {
        dist[get<1>(x)] = dist[get<0>(x)] + get<2>(x);
        //cout << get<1>(x) << ": " << dist[get<1>(x)] << endl;
      }
    }
  }

  for (auto x : edges) {
    //if (dist[get<0>(x)] == INF) continue;
    if (dist[get<0>(x)] + get<2>(x) < dist[get<1>(x)]) {
      //cout << dist[get<0>(x)] + get<2>(x) << " " << dist[get<1>(x)] << endl;
      return 0;
    }
  }

  return 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (true) {
    cin >> C;
    if (C == 0) break;
    for (int i = 0; i < C; ++i) {
      string s;
      cin >> s;
      label[s] = i;
      dist[i] = (i == 0) ? 0 : INF;
    }
    int R; cin >> R;
    vector<iii> edges;
    for (int i = 0; i < R; ++i) {
      string u, v;
      char c;
      long double w1, w2;
      cin >> u >> v >> w1 >> c >> w2;
      // auto pos = w.find(':');
      // if (pos != w.npos) {
      //   w1 = stod(w.substr(0, pos));
      //   w2 = stod(w.substr(pos + 1));
      // }
      //cout << w1 << " " << w2 << endl;
      //cout << -1 * log(w2 / w1) << " " << -1 * log(w1 / w2) << endl;
      edges.push_back(make_tuple(label[u], label[v], -1 * (log(w2) - log(w1))));
      //edges.push_back(make_tuple(v, u, -1 * log(w1 / w2)));
    }

    int ans = bellman_ford(edges);
    if (ans == 1) cout << "Ok\n";
    else cout << "Arbitrage\n";

  }

  return 0;
}
