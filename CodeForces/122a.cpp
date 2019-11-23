#include <bits/stdc++.h>

using namespace std;

bool lucky(int x) {
  while (x > 0) {
    if ((x % 10) != 4 && (x % 10) != 7) {
      return false;
    }
    x /= 10;
  }
  return true;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int arr[1001] = { 0 };
  for (int i = 1; i <= 1000; ++i) {
    if (lucky(i)) {
      for (int j = i; j <= 1000; j = j + i)
        arr[j] = 1;
    }
  }


  int n; cin >> n;
  if (arr[n]) cout << "YES";
  else cout << "NO";

  return 0;
}
