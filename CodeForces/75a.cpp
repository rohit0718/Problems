#include <bits/stdc++.h>

using namespace std;

int remove_zero(int x) {
  int ptr = 1;
  int ans = 0;
  while (x > 0) {
    if (x % 10) {
      ans += (x % 10) * ptr;
      ptr *= 10;
    }
    x /= 10;
  }
  return ans;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int x, y;
  cin >> x >> y;

  if (remove_zero(x + y) == remove_zero(x) + remove_zero(y)) cout << "YES";
  else cout << "NO";

  return 0;
}
