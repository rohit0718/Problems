#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {

  int q; cin >> q;

  while (q--) {
    long long n, m; cin >> n >> m;

    vector<int> v;
    int S = 0;
    int x = m;
    while (true) {
      v.push_back(x % 10);
      if (!(x % 10)) break;
      S += (x % 10);
      x += m;
    }

    int sz = v.size();
    ll cnt = n / (m * sz);
    ll R = n % (m * sz);

    S *= cnt;
    for (int i = 0; i < R; ++i) S += v[i];
    cout << S << "\n";

  }

  return 0;

}
