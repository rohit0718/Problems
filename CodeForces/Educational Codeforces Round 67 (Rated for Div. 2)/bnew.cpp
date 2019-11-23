#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > name(26);

int main() {
  int n, m;
  string s;
  cin >> n >> s >> m;

  for (int i = 1; i <= n; ++ i) {
    name[s[i - 1] - 'a'].push_back(i);
  }

  for (int i = 0; i < m; ++i) {
    int pos[26] = { 0 };
    string t;
    cin >> t;
    int x = -1;
    for (auto &c : t) {

      x = max(name[c - 'a'][pos[c - 'a']], x);
      pos[c - 'a']++;

    }

    cout << x << "\n";

  }
}
