#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  string x; cin >> x;
  int ans = 0;
  if (x.size() > 1) ans += (x[x.size() - 1] - '0') + ((x[x.size() - 2] - '0') * 10);
  else ans += x[0] - '0';

  cout << ((ans % 4 == 0) ? 4 : 0);

  return 0;
}
