#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int init = 0, party = 0, total = 0;

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (i == 1) init = x, ans.push_back(i), party = init;
    else if (init >= 2 * x) ans.push_back(i), party += x;
    total += x;
  }

  if (party > (total / 2)) {
    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
  }
  else cout << 0;

  return 0;
}
