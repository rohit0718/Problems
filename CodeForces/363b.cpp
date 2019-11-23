#include <bits/stdc++.h>

using namespace std;

int arr[150005];

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k; cin >> n >> k;

  cin >> arr[0];
  for (int i = 1; i < n; ++i) {
    int x; cin >> x;
    arr[i] = arr[i - 1] + x;
  }

  int low = arr[k - 1];
  int ans = 0;
  for (int i = k; i < n; ++i) {
    if (arr[i] - arr[i - k] < low) {
      low = arr[i] - arr[i - k];
      ans = i - k + 1;
    }
  }

  cout << ans + 1;

  return 0;
}
