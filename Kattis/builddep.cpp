#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> g;
map<string, bool> visited;
vector<string> res;

void dfs(string x) {
  visited[x] = true;

  //iterate neighbours
  for (auto x : g[x]) if (!visited[x]) dfs(x);

  res.push_back(x);
}



int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  string line;
  getline(cin, line);

  for (int i = 0; i < N; ++i) {
    getline(cin, line);
    istringstream iss(line);
    string word, parent;
    while (iss >> word) {
      if (word[word.length() - 1] == ':') word.pop_back(), parent = word;
      else g[word].push_back(parent);
    }
  }

  string target;
  getline(cin, target);

  dfs(target);

  for (int i = res.size() - 1; i >= 0; --i) cout << res[i] << "\n";

  return 0;
}
