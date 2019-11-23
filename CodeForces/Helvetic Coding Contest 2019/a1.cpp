#include <iostream>

using namespace std;

int main() {

  long long r;
  cin >> r;

  if (r % 2 != 0 && r > 3) cout << 1 << " " << (r - 3) / 2;
  else cout << "NO";

  return 0;
}
