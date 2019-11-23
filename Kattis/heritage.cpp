#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;
map<string, ll> m;
map<string, ll> dp;
int N;
string W;

ll solve(string s) {
  if (dp[s] > 0) return dp[s];
  if (s.size() == 0) return 1;
  ll tmp = 0;

  for (int i = 1; i <= s.size(); ++i) {
    if (m[s.substr(0,i)] > 0) {
      tmp += m[s.substr(0,i)] * solve(s.substr(i)) % mod;
    }
  }

  dp[s] = tmp % mod;
  return tmp % mod;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> W;

  for (int i = 0; i < N; ++i) {
    string s;
    ll n;
    cin >> s >> n;
    m[s] = n;
  }

  cout << solve(W) % mod;

  return 0;

}
