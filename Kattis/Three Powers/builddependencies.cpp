#include <bits/stdc++.h>

using namespace std;

int N;
unordered_map<string, vector<string>> m;
vector<string> ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  string line, parent, target;
  //force reader to go to next line
  getline(cin, line);

  int cnt = 0;
  while (getline(cin, line)) {
    istringstream iss(line);
    string word;
    string parent;

    while (iss >> word) {
      if (cnt == N) target = word;
      else if (word[word.size() - 1] == ':') {
        word.pop_back();
        parent = word;
      }
      else m[word].push_back(parent);
    }
    cnt++;
  }

  ans.push_back(target);
  deque<string> next;
  for (auto &x : m[target]) {
    next.push_back(x);
  }
  while (!next.empty()) {
    for (auto &x : m[next[0]]) {
      next.push_back(x);
    }
    ans.push_back(next[0]);
    next.pop_front();
  }

  ans.erase( unique( ans.begin(), ans.end() ), ans.end() );

  for (auto &x : ans) {
    cout << x << "\n";
  }

  // for (auto &x : m) {
  //   cout << x.first << ": ";
  //   for (auto &y : x.second) {
  //     cout << y << " ";
  //   }
  //   cout << "\n";
  // }
  //
  // cout << "target: " << target;

  return 0;
}
