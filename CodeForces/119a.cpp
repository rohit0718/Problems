#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, n; cin >> a >> b >> n;

  int turn = 1;
  while(n) {
    if (turn) n -= gcd(a, n);
    else n -= gcd(b, n);
    turn ^= 1;
  }

  cout << turn;


  return 0;
}
