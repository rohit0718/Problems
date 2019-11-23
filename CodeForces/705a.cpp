#include <iostream>

using namespace std;

int main() {

  int n; cin >> n;

  int x = 1;
  while (n > 1) {
    if (x) cout << "I hate that ";
    else cout << "I love that ";
    x ^= 1;
    n--;
  }

  if (x) cout << "I hate it";
  else cout << "I love it";

  return 0;
}
