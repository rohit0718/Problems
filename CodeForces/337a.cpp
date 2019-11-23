#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<int> arr;
  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    arr.push_back(x);
  }

  sort(arr.begin(), arr.end());

  int min = 1000;
  for (int i = 0; i <= m - n; ++i) {
    if (min > arr[i + n - 1] - arr[i])
      min = arr[i + n - 1] - arr[i];
  }

  cout << min;

  return 0;
}
