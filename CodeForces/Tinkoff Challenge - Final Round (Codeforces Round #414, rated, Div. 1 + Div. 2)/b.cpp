#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, h;
  cin >> n >> h;

  cout << setprecision(6) << fixed;

  for (int i = 1; i < n; ++i) {
    cout << h * sqrt(i * 1.0 / n) << " ";
  }

  return 0;
}
