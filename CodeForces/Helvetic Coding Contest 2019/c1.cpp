#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int cd_x[51] = { 0 };
  int cd_y[51] = { 0 };
  vector<pair<int,int>> cd;

  for (int i = 0; i < (4 * n) + 1; ++i) {
    int x, y;
    cin >> x >> y;
    cd_x[x]++;
    cd_y[y]++;
    cd.push_back(make_pair(x, y));
  }

  // the max of x coordinates that appears twice is the end_x
  // the min of x coordinates that appears twice is the start_x
  // similarly for the y coordinates
  int min_x = INT_MAX;
  int max_x = -1;
  int min_y = INT_MAX;
  int max_y = -1;

  for (int i = 0; i <= 50; ++i) {
    if (cd_x[i] >= 2) {
      min_x = min(min_x, i);
      max_x = max(max_x, i);
    }
    if (cd_y[i] >= 2) {
      min_y = min(min_y, i);
      max_y = max(max_y, i);
    }
  }

  for (auto c : cd) {
    int x = c.first;
    int y = c.second;
    if (x > max_x || x < min_x || y > max_y || y < min_y
        || (x > min_x && x < max_x && y > min_y && y < max_y)) {
          cout << x << " " << y;
          return 0;
        }
  }

  return 0;
}
