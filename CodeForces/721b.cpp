#include <bits/stdc++.h>

using namespace std;

struct compare {
  bool operator()(const string& first, const string& second) {
    return first.size() < second.size();
  }
};

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k; cin >> n >> k;

  vector<string> v;
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    v.push_back(s);
  }

  compare c;
  sort(v.begin(), v.end(), c);

  string ans; cin >> ans;
  int sz = ans.size();

  int ptr = 0;
  while (v[ptr].size() != sz) ptr++;
  cout << (ptr + 1) + (((ptr) / k) * 5) << " ";
  while (v[ptr].size() <= sz) {
    ptr++;
    if (ptr == n) {
      cout << n + (((n - 1) / k) * 5);
      return 0;
    }
  }
  cout << ptr + (((ptr - 1) / k) * 5);


  return 0;
}
