#include <iostream>

using namespace std;

int main() {

  int n; cin >> n;

  int M = 0, C = 0;
  for (int i = 0; i < n; ++i) {
    int m, c;
    cin >> m >> c;
    if (m > c) M++;
    else if (c > m) C++;
  }

  if (M > C) cout << "Mishka";
  else if (M < C) cout << "Chris";
  else cout << "Friendship is magic!^^";


  return 0;
}
