#include <bits/stdc++.h>

using namespace std;

int n, m;
int v[1000005];
int dp[1000005][3][3];

int ans(int i, int j, int k) {

    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (i == m) return (v[i] - j - k) / 3;
    int res = 0;
    for (int x = 0; x < 3; ++x) {
      if (v[i] - j - k >= x && v[i + 1] - k >= x && v[i + 2] >= x) {
        res = max(res, x + ((v[i] - x - j - k) / 3) + ans(i + 1, k, x));
      }
    }
    return dp[i][j][k] = res;
}

int main () {

  memset(dp, -1, sizeof(dp));

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v[x]++;
  }
  //for (int i = 0; i < n; ++i) cout << v[i] << " ";
  if (n <= 2) cout << 0;
  else {
    int a = ans(1, 0, 0);
    cout << a;
  }
}
