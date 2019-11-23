#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;

  int ans = 1;
  int prev = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (i == 0) prev = x;
    else if (x != prev) {
      ans++;
      prev = x;
    }
  }

  cout << ans;

  return 0;
}
