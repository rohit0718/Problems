#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int n, s, t;
    cin >> n >> s >> t;


    int b = s + t - n;
    cout << max(s - b, t - b) + 1 << "\n";



  }


  return 0;
}
