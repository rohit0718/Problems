#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> v;
int r, c, n, r1, c1, r2, c2;
bool visited[1005][1005];
int floodfill[1005][1005];
int colour = 0;


void dfs(char x, int r1, int c1) {

  if (r1 < 0 || c1 < 0 || r1 >= r ||
     c1 >= c || v[r1][c1] != x ||
     visited[r1][c1]) {
       return;
  }
  visited[r1][c1] = true;
  floodfill[r1][c1] = colour;
  dfs(x, r1, c1 - 1);
  dfs(x, r1, c1 + 1);
  dfs(x, r1 - 1, c1);
  dfs(x, r1 + 1, c1);
}


int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
      string s;
      cin >> s;
      v.push_back(s);
  }


  // flood filling the matrix
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (visited[i][j]) continue;
      else {
        // dfs on the cell
        char x = v[i][j];
        dfs(x, i, j);
        colour++;
      }
    }
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    if (floodfill[r1][c1] == floodfill[r2][c2]) {
      if (v[r1][c1] == '0') cout << "binary\n";
      else if (v[r1][c1] == '1') cout << "decimal\n";
    }
    else cout << "neither\n";
}

  return 0;

}
