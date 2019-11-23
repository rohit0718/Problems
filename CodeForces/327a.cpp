#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int arr[105] = { 0 };
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] == 1) tot++;
  }

  int mx = -1, cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if (arr[j] == 1) cnt1++;
      else cnt0++;
      mx = max(cnt0 - cnt1, mx);
    }
    cnt1 = 0, cnt0 = 0;
  }

  cout << tot + mx;


  return 0;
}
