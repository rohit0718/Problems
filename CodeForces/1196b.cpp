#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int q; cin >> q;

  for (int case_num = 0; case_num < q; ++case_num) {

    int n, k; cin >> n >> k;
    int odd = 0;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      arr.push_back(x);
      if (x & 1) odd++;
    }

    if (k > odd || (((k - odd) % 2)  != 0)) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
    for (int i = 0; k > 1; ++i) {
      if (arr[i] & 1) {
        cout << i + 1 << " ";
        k--;
      }
    }

    cout << n << "\n";

  }

  return 0;
}
