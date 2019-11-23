#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;

  vector<int> v;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    v.push_back(a);
    sum += a;
  }

  sort(v.begin(), v.end());
  long long ans = sum;
  for (int i = 0; i < n - 1; ++i) {
    sum -= v[i];
    ans += v[i] + sum;
  }

  cout << ans;

  return 0;
}
