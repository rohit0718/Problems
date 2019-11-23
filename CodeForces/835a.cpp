#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;

  int b1 = (2 * t1) + (s * v1);
  int b2 = (2 * t2) + (s * v2);

  if (b1 < b2) cout << "First";
  else if (b1 > b2) cout << "Second";
  else cout << "Friendship";

  return 0;
}
