#include <iostream>

using namespace std;

int main() {
  string s; cin >> s;

  int a = 0;
  for (auto x : s) if (x == 'a') a++;

  int sz = s.size();
  while (a <= sz / 2) sz--;

  cout << sz;

  return 0;
}
