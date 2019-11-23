#include <iostream>
#include <string>

using namespace std;

int main() {

  int n; cin >> n;
  string s; cin >> s;

  int a = 0, d = 0;
  for (auto x : s) {
    if (x == 'A') a++;
    else d++;
  }

  if (a > d) cout << "Anton";
  else if (a < d) cout << "Danik";
  else cout << "Friendship";

  return 0;
}
