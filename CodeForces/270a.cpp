#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;

  for (int i = 0; i < t; ++i) {
    float a; cin >> a;
    if (a < 60) cout << "NO\n";
    else {
      bool b = 0;
      for (int i = 3; i <= 360; ++i) {
        if ((180 - (360 * 1.0 / i)) == a) {
          cout << "YES\n";
          b = 1;
          break;
        }
      }
      if (!b) cout << "NO\n";
    }
  }


  return 0;
}
