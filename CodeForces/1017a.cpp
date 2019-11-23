#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  int thomas = 0;
  vector<int> tot;
  for (int i = 0; i < n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    tot.push_back(a + b + c + d);
    if (i == 0) thomas = a + b + c + d;
  }

  sort(tot.begin(), tot.end(), greater<int>());

  for (int i = 0; i < n; ++i) {
    if (tot[i] == thomas) {
      cout << i + 1;
      return 0;
    }
  }

  return 0;
}
