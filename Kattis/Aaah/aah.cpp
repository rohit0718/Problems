#include <iostream>
#include <string>

using namespace std;

int main() {
  string x, y;
  cin >> x >> y;
  if (y.size() <= x.size()) cout << "go";
  else cout << "no";

  return 0;
}
