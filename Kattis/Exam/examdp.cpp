#include <bits/stdc++.h>

using namespace std;

string x, y;
const int NINF = -1e9;
vector<vector<int>> memo(1005, vector<int>(1005, -1));


int solve(int pos, int k) {
    if (pos >= x.size()) return k == 0 ? 0 : NINF;
    if (memo[pos][k] != -1) return memo[pos][k];

    //your friend is coorect
    int c1 = -1;
    if (k > 0) {
       c1 = (x[pos] == y[pos]) + solve(pos+1, k-1);
    }

    int c2 = (x[pos] != y[pos]) + solve(pos+1,k);
    return memo[pos][k] = max(c1, c2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  cin >> k;

  cin >> x >> y;

  cout << solve(0, k) << "\n";

}
