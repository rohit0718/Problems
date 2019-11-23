#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int n; cin >> n;

  int total = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    total += x;
  }

  cout << setprecision(6) << fixed;
  cout << (1.0 * total) / n;

  return 0;
}
