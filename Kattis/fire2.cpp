#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int INF = 1e9;
int w, h, x, y, ans;
char grid[1005][1005] = { 0 };
int level[1005][1005];
queue<ii> q;

int ro[] = { 1, -1, 0, 0 };
int co[] = { 0, 0, 1, -1 };

void solve(int r = -1, int c = -1) {

  if (r != -1 && c != -1) {
    q.push(make_pair(r,c));
    level[r][c] = 0;
    ans = INF;
  }

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    if (row + 1 >= h || row - 1 < 0 || col + 1 >= w || col - 1 < 0) ans = min(ans, level[row][col] + 1);
    for (int i = 0; i < 4; ++i) {
      if (row + ro[i] < h && row + ro[i] >= 0 &&
        col + co[i] < w && col + co[i] >= 0 && grid[row + ro[i]][col + co[i]] != '#' &&
        level[row + ro[i]][col + co[i]] > level[row][col] + 1) {
          level[row + ro[i]][col + co[i]] = level[row][col] + 1;
          q.push(make_pair(row + ro[i], col + co[i]));
      }
    }
  }

  return;
}


int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  for (int case_num = 0; case_num < n; ++case_num) {

    cin >> w >> h;

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> grid[i][j];
        level[i][j] = INF;
        if (grid[i][j] == '@') x = i, y = j;
        else if (grid[i][j] == '*') q.push(make_pair(i,j)), level[i][j] = 0;
      }
    }

    // bfs for all *s at once
    solve();

    // bfs for @
    solve(x,y);

    if (ans < INF) cout << ans << "\n";
    else cout << "IMPOSSIBLE\n";

  }

  return 0;
}
