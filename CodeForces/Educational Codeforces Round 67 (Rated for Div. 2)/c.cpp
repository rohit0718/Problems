#include <iostream>
#include <vector>

using namespace std;
int sol[1005] = { 0 };
vector<int> v;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    // 1 can be a subset of 0 but 0 CANNOT be a subset of 1
    int t, l, r;
    cin >> t >> l >> r;
    l++;
    for (int j = l; j <= r; ++j) {
      if (t == 1 && sol[j] != t + 1 && sol[j] != 0 && sol[j - 1] == 1 || sol[j + 1] == 1)


      //if (sol[j] != t + 1 && sol[j] != 0) {
      //  cout << "NO";
      //  return 0;
      //}
      sol[j] = t + 1;
    }
  }

  //sol[j] == 1 means decreasing, sol[j] == 2 or 0 means same
  cout << "YES\n";
  int ans = 1001;
  for (int i = 1; i <= n; ++i) {
    if (sol[i] == 1) {
      ans--;
      cout << ans << " ";
    }
    else cout << ans << " ";
  }

  return 0;
}
