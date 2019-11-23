#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;

  int arr[105] = { 0 };


  for (int i = 0; i < m; ++i) {
    int max = -1;
    int ptr = -1;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      if (x > max) max = x, ptr = i;
    }
    arr[ptr]++;
  }

  int max = -1, ans = -1;
  for (int i = 0; i < n; ++i) {
    if (arr[i] > max) max = arr[i], ans = i;
  }

  cout << ans + 1;

  return 0;
}
