#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  for (int i = 0; i < t; ++i) {
    int x, y;
    cin >> x >> y;
    if (x == 0) {
      if (y < k) n -= y, k -= y;
      else n = y;
    }
    else {
      n++;
      if (y <= k) k++;
    }
    cout << n << " " << k << "\n";
  }
}
