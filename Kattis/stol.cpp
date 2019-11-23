#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int R, C; cin >> R >> C;

  vector<vector<int>> v(R, vector<int>(C));

  for (int i = 0; i < R; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < C; ++j) {
      char c = s[j];
      if (c == 'X') v[i][j] = -1;
      else if (c == '.' && i > 0 && v[i - 1][j] > 0) v[i][j] = v[i - 1][j] + 1;
      else v[i][j] = 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < R; ++i) {
    stack<int> s;
    for (int j = 0; j < C; ++j) {
      if (s.empty() || v[i][s.top()] <= v[i][j]) s.push(j);
      else {
        while (v[i][s.top()] > v[i][j]) {
          int x = s.top();
          s.pop();
          if (v[i][x] == -1) continue;
          ans = max(ans, 2 * ((s.empty() ? j : j - s.top() - 1) + v[i][x]));
          if (s.empty()) break;
        }
        s.push(j);
      }
    }
    while (!s.empty()) {
      int x = s.top();
      s.pop();
      if (v[i][x] == -1) continue;
      ans = max(ans, 2 * ((s.empty() ? C : C - s.top() - 1) + v[i][x]));
    }
  }

  cout << ans - 1;


  return 0;
}
