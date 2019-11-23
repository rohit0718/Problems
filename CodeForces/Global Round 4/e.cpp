#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int sz = s.size();
  string ans (sz / 2, '0');

  for (int i = 0; i < sz / 2; i = i + 2) {
    if (s[i] == s[sz - 1 - i]) ans[i / 2] = s[i], ans[(sz / 2) - 1 - (i / 2)] = s[sz - 1 - i];
    else if (s[i + 1] == s[sz - 1 - i]) ans[i / 2] = s[i + 1], ans[(sz / 2) - 1 - (i / 2)] = s[sz - 1 - i];
    else if (s[i] == s[sz - 2 - i]) ans[i / 2] = s[i], ans[(sz / 2) - 1 - (i / 2)] = s[sz - 2 - i];
    else if (s[i + 1] == s[sz - 2 - i]) ans[i / 2] = s[i + 1], ans[(sz / 2) - 1 - (i / 2)] = s[sz - 2 - i];
  }

  cout << ans;

  return 0;
}
