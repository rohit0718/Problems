#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;

  int days = 0;
  while (n) {
    n--;
    days++;
    if (days % m == 0) n++;
  }

  cout << days;

  return 0;
}
