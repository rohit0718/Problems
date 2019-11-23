#include <iostream>

using namespace std;

int main() {
  int n; cin >> n;
  string S; cin >> S;

  int s = 0, f = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (S[i + 1] == 'F' && S[i] == 'S') s++;
    else if (S[i + 1] == 'S' && S[i] == 'F') f++;
  }

  if (s > f) cout << "YES";
  else cout << "NO";

  return 0;
}
