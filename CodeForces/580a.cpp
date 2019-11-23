#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int arr[100005] = { 0 };
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int curr = 0;
  int max = 0;
  int prv = arr[0];

  for (int i = 0; i < n; ++i) {
    if (arr[i] < prv) {
      if (curr > max) max = curr;
      curr = 1;
      prv = arr[i];
    }
    else {
      prv = arr[i];
      curr++;
    }
  }

  if (curr > max) cout << curr;
  else cout << max;

  return 0;
}
