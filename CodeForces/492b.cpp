#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, l; cin >> n >> l;
  vector<int> lan;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    lan.push_back(x);
  }

  sort(lan.begin(), lan.end());

  float max_gap = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (lan[i + 1] - lan[i] > max_gap)
      max_gap = lan[i + 1] - lan[i];
  }

  max_gap /= 2;
  if (lan[0] - 0 > max_gap) max_gap = lan[0] - 0;
  if (l - lan[n - 1] > max_gap) max_gap = l - lan[n - 1];

  cout << setprecision(9) << fixed;
  cout << max_gap;


  return 0;
}
