#include <iostream>

using namespace std;

int main() {

  int n; cin >> n;

  int arr[105];
  int high = -1;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] > high) high = arr[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) ans += high - arr[i];

  cout << ans;


  return 0;
}
