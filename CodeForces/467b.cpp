#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;

  vector<int> v;
  int f = 0;
  for (int i = 0; i < m + 1; ++i) {
    int x; cin >> x;
    if (i == m) f = x;
    else v.push_back(x);
  }

  int ans = 0;
  for (auto x : v) if (__builtin_popcount(x ^ f) <= k) ans++;

  cout << ans;

  return 0;
}
