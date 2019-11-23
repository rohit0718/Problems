#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  for (int i = 0; i < t; ++i) {
    long long r, l, k;
    cin >> r >> l >> k;
    if (k & 1) {
      cout << (r - l) * ((k - 1) / 2) + r << "\n";
    }
    else {
      cout << (r - l) * (k / 2) << "\n";
    }
  }


  return 0;
}
