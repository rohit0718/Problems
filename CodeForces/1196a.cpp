#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    ll x, y, z;
    cin >> x >> y >> z;
    if ((x + y + z) & 1) cout << (x + y + z - 1) / 2 << "\n";
    else cout << (x + y + z) / 2 << "\n";
  }



  return 0;
}
