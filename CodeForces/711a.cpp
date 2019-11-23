#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  bool done = false;
  vector<string> ans;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (!done) {
      for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] == 'O' && s[i] == 'O') {
          s[i - 1] = '+';
          s[i] = '+';
          done = true;
          break;
        }
      }
    }
    ans.push_back(s);
  }

  if (done) {
    cout << "YES\n";
    for (auto x : ans) cout << x << "\n";
  }
  else cout << "NO";

  return 0;
}
