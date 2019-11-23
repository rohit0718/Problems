#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  string x; cin >> x;
  bool inv = false;

  string s;
  for (auto ch : x) {
    if (ch == '9' && !inv) s.push_back(ch);
    else if (ch < '5') s.push_back(ch);
    else s.push_back((char)(105 - ch));
    inv = true;
  }

  for (auto c : s) cout << c;

  return 0;
}
