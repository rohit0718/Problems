#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  bool seen = false;
  for (int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '0' && !seen) seen = true;
    else if (c == '1' && i == s.size() - 1 && !seen) break;
    else cout << c;
  }


  return 0;
}
