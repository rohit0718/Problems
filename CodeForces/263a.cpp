#include <iostream>

using namespace std;

int main() {

  int r1, c1;

  for (int r = 0; r < 5; ++r) {
    for (int c = 0; c < 5; ++c) {
      int x;
      cin >> x;
      if (x == 1) r1 = r, c1 = c;
    }
  }

  cout << abs(r1 - 2) + abs(c1 - 2);

  return 0;
}
