#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  int neg = 0;
  vector<int> arr;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    arr.push_back(x);
    if (x < 0) neg++;
  }

  sort(arr.begin(), arr.end());

  if (neg & 1) {
    cout << 1 << " " << arr[0] << "\n" << n - 2 << " ";
    for (int i = 1; i < n; ++i) {
      if (arr[i] != 0) cout << arr[i] << " ";
    }
    cout << "\n" << 1 << " " << 0;
  }
  else {
    cout << 1 << " " << arr[1] << "\n" << n - 3 << " ";
    for (int i = 2; i < n; ++i) if (arr[i] != 0) cout << arr[i] << " ";
    cout << "\n" << 2 << " " << arr[0] << " " << 0;
  }


  return 0;
}
