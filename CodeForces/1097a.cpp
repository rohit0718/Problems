#include <iostream>
#include <map>

using namespace std;

int main() {

  string s; cin >> s;

  for (int i = 0; i < 5; ++i) {
    string x;
    cin >> x;
    if (x[1] == s[1] || x[0] == s[0]) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";

  return 0;
}
