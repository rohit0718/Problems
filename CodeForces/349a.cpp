#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  int cnt25 = 0, cnt50 = 0;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x == 25) cnt25++;
    else if (x == 50 && cnt25 > 0) cnt50++, cnt25--;
    else if (x == 100 && cnt50 > 0 && cnt25 > 0) cnt50--, cnt25--;
    else if (x == 100 && cnt25 > 2) cnt25 -= 3;
    else {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}
