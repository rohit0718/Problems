#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int prev = 0;
  vector<int> s;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (i == 0) prev = x;
    else if (x == 1) s.push_back(prev), prev = x;
    else prev = x;
  }
  s.push_back(prev);

  cout << s.size() << "\n";
  for (auto x : s) cout << x << " ";

  return 0;
}
