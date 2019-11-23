#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int ans = 0;
  while (n) {
    if (n - 100 >= 0) n -= 100;
    else if (n - 20 >= 0) n -= 20;
    else if (n - 10 >= 0) n -= 10;
    else if (n - 5 >= 0) n -= 5;
    else n -= 1;
    ans++;
  }

  cout << ans;

  return 0;
}
