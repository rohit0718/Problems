#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;

  int arr[105] = { 0 };
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; ++j) arr[j]++;
  }

  vector<int> ans;
  for (int i = 1; i <= m; ++i) {
    if (arr[i] == 0) ans.push_back(i);
  }

  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << " ";

  return 0;
}
