#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;


  char arr[102][102];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (i & 1 && j & 1) arr[i][j] = 'B';
        else if (i & 1) arr[i][j] = 'W';
        else if (j & 1) arr[i][j] = 'W';
        else arr[i][j] = 'B';
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      if (c == '-') arr[i][j] = c;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << arr[i][j];
    }
    cout << endl;
  }



  return 0;
}
