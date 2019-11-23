#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int,int> ii;

bool prime[1015];
vector<ii> ans;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  memset(prime, true, sizeof(prime));

  // sieve of eratosthenes
  for (int i = 2; i < 1015; ++i) {
    if (prime[i]) {
      for (int j = i * i; j < 1015; j += i) {
        prime[j] = 0;
      }
    }
  }

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    if (i == n) ans.push_back(make_pair(n, 1));
    else ans.push_back(make_pair(i, i + 1));
  }

  int ptr = 1;
  int sep = n / 2;
  while (!prime[n]) {
    ans.push_back(make_pair(ptr, ptr + sep));
    ptr++;
    n++;
  }

  cout << ans.size() << "\n";
  for (auto x : ans) {
    cout << x.first << " " << x.second << "\n";
  }

  return 0;
}
