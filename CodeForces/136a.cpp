#include <iostream>

using namespace std;

int main() {

int n; cin >> n;

int pos[105] = { 0 };
for (int i = 1; i <= n; ++i) {
  int x;
  cin >> x;
  pos[x] = i;
}

for (int i = 1; i <= n; ++i) cout << pos[i] << " ";

return 0;
}
