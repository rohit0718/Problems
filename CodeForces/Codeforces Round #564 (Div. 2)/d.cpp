#include <iostream>

using namespace std;

typedef long long ll;

const int mod = 998244353;

int main() {

  int n; cin >> n;
  ll ans = n;
  int arr[200005] = { 0 };

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    ans = (ll) ans * (++arr[u]) % mod * (++arr[v]) % mod;
  }

  cout << ans;

  return 0;
}
