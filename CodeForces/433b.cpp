#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<long long> arr = {0}, arr_sort = {0};
  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    arr.push_back(x);
    arr_sort.push_back(x);
  }

  sort(arr_sort.begin(), arr_sort.end());
  for (int i = 1; i <= n; ++i) {
    arr[i] += arr[i - 1];
    arr_sort[i] += arr_sort[i - 1];
  }

  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      cout << arr[c] - arr[b - 1] << "\n";
    }
    else {
      cout << arr_sort[c] - arr_sort[b - 1] << "\n";
    }
  }

  return 0;
}
