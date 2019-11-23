#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  s += 'o';

  int x = 0;
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (s[i] == 'x') x++;
    else if (x >= 3) ans += x - 2, x = 0;
    else x = 0;
  }

  cout << ans;

  return 0;
}
