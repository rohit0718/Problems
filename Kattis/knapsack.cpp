#include <bits/stdc++.h>

using namespace std;

int val[2005], weight[2005], dp[2005][2005], C, n;

int ans(int i, int w) {
  if (dp[i][w] != -1) return dp[i][w];
  if (i >= n) return 0;
  else if (w + weight[i] <= C)
    return dp[i][w] = max(ans(i + 1, w), val[i] + ans(i + 1, w + weight[i]));
  else return dp[i][w] = ans(i + 1, w);
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> C >> n) {

    for (int i = 0; i < n; ++i) {
      cin >> val[i] >> weight[i];
    }

    memset(dp, -1, sizeof(dp));
    int val = ans(0, 0);

    vector<int> ans;
    int w = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (dp[i][w] != dp[i + 1][w]) {
        ans.push_back(i);
        w += weight[i];
      }
    }

    if (w + weight[n - 1] <= C) ans.push_back(n - 1);

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";

  }

  return 0;
}
