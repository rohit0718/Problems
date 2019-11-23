#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  vector<int> std;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    std.push_back(x);
  }

  sort(std.begin(), std.end());

  int ans = 0;
  for (int i = 0; i < n - 1; i = i + 2) {
    while (std[i + 1] > std[i]) ans++, std[i]++;
  }

  cout << ans;

  return 0;
}
