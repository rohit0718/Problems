#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int arr[4];
  for (int i = 0; i < 4; ++i) cin >> arr[i];

  string s; cin >> s;
  int ans = 0;
  for (auto x : s) ans += arr[x - '0' - 1];

  cout << ans;


  return 0;
}
