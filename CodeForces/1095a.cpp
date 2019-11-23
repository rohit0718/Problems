#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;

  int ptr = 0;
  int jump = 0;
  while (ptr + jump < s.size()) {
    cout << s[ptr];
    jump++;
    ptr += jump;
  }


  return 0;
}
