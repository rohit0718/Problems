#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, x; cin >> n >> x;

  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int c; cin >> c;
    v.push_back(c);
  }

  sort(v.begin(), v.end());

  long long ans = 0;
  for (auto c : v) {
    ans += 1LL * c * x;
    if (x > 1) x--;
  }

  cout << ans;

  return 0;
}
