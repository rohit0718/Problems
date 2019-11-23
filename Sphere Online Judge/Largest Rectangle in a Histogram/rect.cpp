#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    stack<ll> s;
    vector<ll> v(n);
    ll ans = -1;
    for (int i = 0; i < n; ++i) {
      ll x; cin >> x;
      v[i] = x;
    }

    for (int i = 0; i < n; ++i) {
      if (s.empty() || v[i] >= v[s.top()]) s.push(i);
      else {
        while (v[s.top()] > v[i]) {
          ll t = s.top();
          s.pop();
          ans = max(ans, v[t] * (s.empty() ? i : (i - s.top() - 1)));
          if (s.empty()) break;
        }
        s.push(i);
      }
    }

    // runnign one more time to clear out set
    while (!s.empty()) {
      ll t = s.top();
      s.pop();
      ans = max(ans, v[t] * (s.empty() ? n : (n - s.top() - 1)));
    }

    cout << ans << "\n";

  }

  return 0;
}
