#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  long long n, k; cin >> n >> k;
  if (n & 1) {
    if (k > (n + 1) / 2) {
      cout << (k - ((n + 1) / 2)) * 2;
    }
    else {
      cout << 1 + ((k - 1) * 2);
    }
  }
  else {
    if (k > n / 2) {
      cout << (k - (n / 2)) * 2;
    }
    else {
      cout << 1 + ((k - 1) * 2);
    }
  }

  return 0;
}
