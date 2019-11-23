#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int s, n; cin >> s >> n;

  vector<ii> v;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    v.push_back({x,y});
  }

  sort(v.begin(), v.end());

  for (auto x : v) {
    if (s > x.first) s += x.second;
    else {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}
