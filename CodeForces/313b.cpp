#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  string s; cin >> s;

  int arr[100005] = { 0 };
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == s[i + 1]) arr[i]++;
    if (i > 0) arr[i] += arr[i - 1];
  }

  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    int l, r; cin >> l >> r;
    l--, r--;
    if (l > 0) cout << arr[r - 1] - arr[l - 1] << "\n";
    else cout << arr[r - 1] << "\n";
  }

  return 0;
}
