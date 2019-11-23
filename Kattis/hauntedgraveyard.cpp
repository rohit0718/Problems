#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
const int INF = 1e9;
int W, H;
int dist[1025];

int bellman_ford(int s, vector<vector<ii>> &edges) {
  for (int n = 0; n < W * H - 1; ++n) {
    for (int i = 0; i < W * H; ++i) {
      if (edges[i].size() == 0 || dist[i] == INF) continue;
      else {
        for (auto x : edges[i]) {
          if (dist[i] + x.second < dist[x.first]) {
            dist[x.first] = dist[i] + x.second;
          }
        }
      }
    }
  }

  for (int n = 0; n < W * H - 1; ++n) {
    for (int i = 0; i < W * H; ++i) {
      if (edges[i].size() == 0 || dist[i] == INF) continue;
      else {
        for (auto x : edges[i]) {
          if (dist[i] + x.second < dist[x.first]) {
            return 1;
          }
        }
      }
    }
  }

  return 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (true) {

    vector<vector<ii>> edges(1025);
    cin >> W >> H;
    if (W == 0 && H == 0) break;

    int G; cin >> G;
    int graveyard[1025] = { 0 };
    for (int i = 0; i < G; ++i) {
      int X, Y; cin >> X >> Y;
      graveyard[(Y * W) + X] = 1;
    }

    int E; cin >> E;
    for (int i = 0; i < E; ++i) {
      int X1, Y1, X2, Y2, w;
      cin >> X1 >> Y1 >> X2 >> Y2 >>  w;
      edges[(Y1 * W) + X1].push_back(make_pair((Y2 * W) + X2, w));
    }

    // processing informatio
    for (int i = 0; i < W * H - 1; ++i) {
      if (graveyard[i] || edges[i].size() > 0) continue;
      if (!graveyard[i + 1] && (i + 1) % W != 0) {
        edges[i].push_back(make_pair(i + 1, 1));
      }
      if (!graveyard[i + W] && ((i / W) + 1 != H)) {
        edges[i].push_back(make_pair(i + W, 1));
      }
      if (!graveyard[i - 1] && i % W != 0) {
        edges[i].push_back(make_pair(i - 1, 1));
      }
      if (!graveyard[i - W] && ((i / W) != 0)) {
        edges[i].push_back(make_pair(i - W, 1));
      }
    }

    // run bellman ford from 0 and youre done
    for (int i = 0; i < 1025; ++i) dist[i] = INF;
    dist[0] = 0;
    int exited = bellman_ford(0, edges);

    if (exited == 1) cout << "Never\n";
    else if (dist[W * H - 1] == INF) cout << "Impossible\n";
    else cout << dist[W * H - 1] << "\n";

  }


  return 0;
}
