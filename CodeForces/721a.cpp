#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  s += 'W';

  vector<int> ans;
  int b = 0;
  for (int i = 0; i <= n; ++i) {
    if (s[i] == 'B') b++;
    else if (b > 0) ans.push_back(b), b = 0;
  }

  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << " ";


  return 0;
}
