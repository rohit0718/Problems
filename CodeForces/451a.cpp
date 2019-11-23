#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  if (n > m) {
    if (m & 1) cout << "Akshat";
    else cout << "Malvika";
  }
  else {
    if (n & 1) cout << "Akshat";
    else cout << "Malvika";
  }

  return 0;
}
