#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> coins;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    total += x;
    coins.push_back(x);
  }

  sort(coins.begin(), coins.end(), greater<int>());

  int ans = 0;
  int taken = 0;
  for (int i = 0; i < n; ++i) {
    taken += coins[i];
    ans++;
    if (taken > total / 2) break;
  }

  cout << ans;

  return 0;
}
