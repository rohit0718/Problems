#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

int main() {

  int s, b;
  cin >> s >> b;

  vector<ii> att;
  for (int i = 0; i < s; i++) {
    int x;
    cin >> x;
    att.push_back(make_pair(x,i));
  }

  vector<ii> def;
  for (int i = 0; i < b; i++) {
    int d, g;
    cin >> d >> g;
    def.push_back(make_pair(d,g));
  }

  sort(att.begin(), att.end());
  sort(def.begin(), def.end());
  vector<int> gold(s, 0);
  int acc = 0;
  int ptr = 0;
  for (int i = 0; i < s; ++i) {
    while (att[i].first >= def[ptr].first && ptr < b) {
      acc += def[ptr].second;
      ptr++;
    }
    gold[att[i].second] = acc;
  }

  for (auto x : gold) cout << x << " ";

  return 0;
}
