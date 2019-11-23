#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int arr[105] = { 0 };
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    arr[a]++;
    if (arr[a] > ans) ans = arr[a];
  }

  cout << ans;

  return 0;
}
