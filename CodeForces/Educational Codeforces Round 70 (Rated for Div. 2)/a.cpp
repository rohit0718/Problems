#include <bits/stdc++.h>

using namespace std;

int main() {

  int T; cin >> T;
  for (int i = 0; i < T; ++i) {
    string x, y;
    cin >> x >> y;

    int right_one = 0;
    for (int i = y.size() - 1; i >= 0; --i) {
      if (y[i] == '1') {
        break;
      }
      right_one++;
    }
    int ptr = 0;
    for (int i = x.size() - 1 - right_one; i >= 0; --i) {
      if (x[i] == '1') break;
      ptr++;
    }
    cout << ptr << "\n";
  }



  return 0;
}
