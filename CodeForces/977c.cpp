#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> arr;
  int n, k; cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    arr.push_back(x);
  }

  sort(arr.begin(), arr.end());

  if (k == 0) {
    if (arr[0] > 1) cout << 1;
    else cout << -1;
  }
  else if (k == n) {
    cout << 1000000000;
  }
  else {
    if (arr[k - 1] == arr[k]) cout << -1;
    else cout << arr[k - 1];
  }

  return 0;
}
