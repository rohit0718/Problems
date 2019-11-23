#include <iostream>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  for (int cs = 1; cs <= T; ++cs) {
      long long zero[55] = { 0 };
      long long n, m; cin >> n >> m;
      for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        for (int j = 0; j < 50; ++j)
          if (!((1LL << j) & x)) zero[j]++;
      }

      long long sum = 0, ans = 0;
      for (int i = 49; i >= 0; --i) {
        sum += min(zero[i], n - zero[i]) * (1LL << i);
        ans += (zero[i] <= n - zero[i]) ? (1LL << i) : 0;
      }
      for (int i = 49; i >= 0 && sum <= m; --i) {
        if (ans & (1LL << i)) continue;
        if ((sum + (zero[i] - (n - zero[i])) * (1LL << i)) <= m) {
          sum += (1LL << i) * (zero[i] - (n - zero[i]));
          ans += (1LL << i);
        }
      }

      cout << "Case #" << cs << ": " << ((sum > m) ? -1 : ans) << "\n";
  }

    return 0;
}
