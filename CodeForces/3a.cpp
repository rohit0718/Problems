#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  char x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  vector<string> ans;
  while (x1 != x2 || y1 != y2) {
    if (y1 == y2) {
      if (x1 < x2) ans.push_back("R"), x1++;
      else ans.push_back("L"), x1--;
    }
    else if (x1 == x2) {
      if (y1 < y2) ans.push_back("U"), y1++;
      else ans.push_back("D"), y1--;
    }
    else if (x1 < x2 && y1 > y2) {
      ans.push_back("RD");
      x1++;
      y1--;
    }
    else if (x1 < x2 && y1 < y2) {
      ans.push_back("RU");
      x1++;
      y1++;
    }
    else if (x1 > x2 && y1 < y2) {
      ans.push_back("LU");
      x1--;
      y1++;
    }
    else if (x1 > x2 && y1 > y2) {
      ans.push_back("LD");
      x1--;
      y1--;
    }
  }


  cout << ans.size() << "\n";
  for (auto x : ans) cout << x << "\n";

  return 0;
}
