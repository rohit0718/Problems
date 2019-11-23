#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, a, b;
  cin >> n >> m >> a >> b;

  if (m >= n) {
    if (a * n > b) cout << b;
    else cout << a * n;
  }
  else {
    cout << min(((n / m) * b) + ((n % m) * a),
            min(a * n, (n / m) * b + b));
  }



  return 0;
}
