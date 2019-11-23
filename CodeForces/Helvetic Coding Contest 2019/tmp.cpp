#include <iostream>

using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  if (m > n) {
    cout << 1;
    return 0;
  }

  int count[1005] = { 0 };
  for (int i = 1; i <= n; ++i) {
    if (n < m) count[i] = 1;
    else if (n == m) count[i] = 2;
    else count[i] = count[i - 1] + count[i - m];
  }

  cout << count[n];

  return 0;
}
