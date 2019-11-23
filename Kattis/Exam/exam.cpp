#include <iostream>
#include <string>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;

  string x, y;
  cin >> x >> y;

  int same = 0, diff = 0;

  for (int i = 0; i < x.size(); ++i) {
    if (x[i] == y[i]) same++;
    else diff++;
  }

  if (same >= k) cout << k + diff;
  else cout << same + diff - (k - same);

  return 0;

}
