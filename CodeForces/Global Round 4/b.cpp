#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  vector<int> L(s.size(), 0);
  vector<int> R(s.size(), 0);

  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'o') {
      L[i] = max(0, cnt - 1);
      cnt = 0;
      continue;
    }
    cnt++;
  }
  for (int i = 0; i < s.size() - 1; ++i) L[i + 1] += L[i];

  cnt = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == 'o') {
      R[i] = max(0, cnt - 1);
      cnt = 0;
      continue;
    }
    cnt++;
  }
  for (int i = s.size() - 1; i > 0; --i) R[i - 1] += R[i];

  long long ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'o') ans += 1LL * L[i] * R[i];
  }

  cout << ans;

  return 0;
}
