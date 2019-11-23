#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int arr[16] = { 0 };
  int n; cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];

  for (int i = 0; i < (1 << n); ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) sum += arr[j];
      else sum -= arr[j];
    }
    if (sum % 360 == 0) {
      cout << "YES";
      return 0;
    }
  }


  cout << "NO";

  return 0;
}
