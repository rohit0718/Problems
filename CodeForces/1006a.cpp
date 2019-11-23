#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x & 1) cout << x << " ";
    else cout << x - 1 << " ";
  }


  return 0;
}
