#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int arr[100002] = { 0 };
  int ans[100002] = { 0 };
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int mx = arr[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    if (mx >= arr[i]) ans[i] = mx - arr[i] + 1;
    else ans[i] = 0, mx = arr[i];
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";

  return 0;
}
