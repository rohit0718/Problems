#include <bits/stdc++.h>

using namespace std;

int arr[1005];
vector<pair<int,int>> unsorted;
vector<pair<int,int>> sorted;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  // preprocessing the array
  for (int i = 1; i <= n; ++i) arr[i] = n + 1 - i;

  for (int i = 0; i < m; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) sorted.push_back(make_pair(l,r));
    else unsorted.push_back(make_pair(l,r));
  }

  // sorting out the array
  sort(sorted.begin(), sorted.end());
  for (auto &x : sorted) {
    int l = x.first;
    int r = x.second;
    for (int j = l; j <= r; ++j) arr[j] = arr[l];
  }


  // checking for validity
  for (auto &x : unsorted) {
    int l = x.first;
    int r = x.second;
    for (int j = l; j < r; ++j) {
      if (arr[j + 1] < arr[j]) break;
      else if (j == r - 1) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  // printing ans
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) cout << arr[i] << " ";

  return 0;
}
