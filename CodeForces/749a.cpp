#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  if (n & 1) {
    cout << (n - 1) / 2 << "\n";
    for (int i = 0; i < (n - 1) / 2; ++i) {
      if (i == ((n - 1) / 2) - 1) cout << 3;
      else cout << 2 << " ";
    }
  }
  else {
    cout << n / 2 << "\n";
    for (int i = 0; i < n / 2; ++i) cout << 2 << " ";
  }



  return 0;
}
