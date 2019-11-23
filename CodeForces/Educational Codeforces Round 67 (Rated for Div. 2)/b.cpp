#include <iostream>
#include <string>
#include <queue>

using namespace std;
vector< queue<int> > x(27);

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  string s;
  cin >> n >> s >> m;

  for (int i = 0; i < s.size(); ++i) {
    x[s[i] - 'a'].push(i + 1);
  }

  for (int i = 0; i < m; ++i) {
    bool visited[20009] = { 0 };
    int largest = -1;
    string t;
    cin >> t;
    vector<queue<int> > tmp = x;
    for (int j = 0; j < t.size(); ++j) {
      if (tmp[t[j] - 'a'].front() > largest) {
        largest = tmp[t[j] - 'a'].front();
        tmp[t[j] - 'a'].pop();
      }
    }
    cout << largest << "\n";
  }





  return 0;
}
