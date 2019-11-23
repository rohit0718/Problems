#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<int> grid;
int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(int N, int s) {
  vector<int> dist(N*N + 5, INF);
  queue<int> q({s}); dist[s] = 0;
  while (!q.empty()) {
    int curr = q.front(); q.pop();
    int cx = curr / N;
    int cy = curr % N;
    if (curr == 0) break;
    for (int i = 0; i < 8; i++) {
      int nx = cx + dr[i];
      int ny = cy + dc[i];
      int nex = nx * N + ny;
      if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if (grid[nex] == -1) continue;
      if (dist[nex] > dist[curr] + 1) {
        dist[nex] = dist[curr] + 1;
        q.push(nex);
      }
    }
  }
  return dist[0] != INF ? dist[0] : -1;
}

int main() {
  int N; cin >> N;
  grid = vector<int>(N*N + 5);

  int src = -1;
  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    for (int j = 0; j < N; j++) {
      grid[i*N + j] = (s[j] != '#') ? 1 : -1;
      if (s[j] == 'K') src = i*N + j;
    }
  }
  cout << bfs(N, src) << "\n";
}
