#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;

  int arr1[5] = { 0 };
  int arr2[5] = { 0 };

  for (int i = 1; i <= n; ++i) arr1[i % 5]++;
  for (int i = 1; i <= m; ++i) arr2[i % 5]++;

  long long ans = 0;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      if ((i + j) % 5 == 0) {
        ans += 1LL * arr1[i] * arr2[j];
      }
    }
  }

  cout << ans;


  return 0;
}
