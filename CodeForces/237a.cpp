#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int ans = 1;
  int cur = 1;
  int prev_h, prev_m;
  cin >> prev_h >> prev_m;
  for (int i = 1; i < n; ++i) {
    int h, m;
    cin >> h >> m;
    if (h == prev_h && m == prev_m) cur++;
    else if (cur > ans) ans = cur, cur = 1;
    else cur = 1;
    prev_h = h, prev_m = m;
  }

  cout << ((ans > cur) ? ans : cur);


  return 0;
}
