#include <bits/stdc++.h>

using namespace std;

int a[55][55], b[55][55];

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;


  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] == 4)
        b[i][j] = 1, b[i][j + 1] = 1, b[i + 1][j] = 1, b[i + 1][j + 1] = 1, ans++;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] ^ b[i][j]) return puts("-1"), 0;

  cout << ans << "\n";
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1] == 4)
        cout << i + 1 << " " << j + 1 << "\n";

  return 0;

}
