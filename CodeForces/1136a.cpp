#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<ll> chp;
  for (int i = 0; i < n; ++i) {
    ll l, r;
    cin >> l >> r;
    chp.push_back(r);
  }
  ll k; cin >> k;

  for (int i = 0; i < n; ++i) {
    if (k > chp[i]) continue;
    else {
      cout << n - i;
      return 0;
    }
  }

  return 0;
}
