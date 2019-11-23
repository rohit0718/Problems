#include <bits/stdc++.h>

using namespace std;

int dp[2005][2005];

int lcs(vector<string> &v1, vector<string> &v2, int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  if (i >= v1.size() || j >= v2.size()) return 0;
  if (v1[i] == v2[j]) return dp[i][j] = 1 + lcs(v1, v2, i + 1, j + 1);
  else return dp[i][j] = max(lcs(v1, v2, i + 1, j), lcs(v1, v2, i, j + 1));
}

bool lex_smaller(string s1, string s2) {
  int i = 0, j = 0;
  while (i < s1.size() && j < s2.size()) {
    if ((int)(s1[i] - 'a') < (int)(s2[j] - 'a')) return true;
    else if ((int)(s1[i] - 'a') > (int)(s2[j] - 'a')) return false;
    i++;
    j++;
  }

  if (j == s2.size()) return false;

  return true;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s1, s2, word;
  while (getline(cin, s1)) {
    if (s1 == ".") break;
    getline(cin, s2);
    vector<string> v1, v2;
    istringstream iss(s1);
    while (iss >> word) v1.push_back(word);
    iss.clear();
    iss.str(s2);
    while (iss >> word) v2.push_back(word);

    memset(dp, -1, sizeof(dp));
    lcs(v1, v2, 0, 0);

    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
      if (v1[i] == v2[j]) {
        cout << v1[i] << " ";
        i++;
        j++;
        if (dp[i][j] == 0) break;
      }
      else if (dp[i + 1][j] == dp[i][j + 1]) {
        if (lex_smaller(v1[i], v2[j])) {
          cout << v1[i] << " ";
          i++;
        }
        else {
          cout << v2[j] << " ";
          j++;
        }
      }
      else if (dp[i + 1][j] > dp[i][j + 1]) {
        cout << v1[i] << " ";
        i++;
      }
      else {
        cout << v2[j] << " ";
        j++;
      }
    }
    cout << "\n";
  }

  return 0;
}
