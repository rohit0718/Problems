#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int arr[10] = { 0 };
  for (int i = 0; i < 6; ++i) {
    int x; cin >> x;
    arr[x]++;
  }

  bool has2 = false, has4 = false, has6 = false;
  for (int i = 1; i < 10; ++i) {
    if (arr[i] == 6) has6 = true;
    else if (arr[i] >= 4) has4 = true;
    else if (arr[i] == 2) has2 = true;
  }

  if ((has4 && has2) || has6) cout << "Elephant";
  else if (has4) cout << "Bear";
  else cout << "Alien";

  return 0;
}
