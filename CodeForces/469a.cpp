#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int arr[105] = { 0 };
  int n; cin >> n;
  int p; cin >> p;
  for (int i = 0; i < p; ++i) {
    int x; cin >> x;
    arr[x] = 1;
  }
  int y; cin >> y;
  for (int i = 0; i < y; ++i) {
    int x; cin >> x;
    arr[x] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (arr[i] == 0) {
      cout << "Oh, my keyboard!";
      return 0;
    }
  }

  cout << "I become the guy.";

  return 0;
}
