#include <bits/stdc++.h>

using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);

  string o, i;
  cin >> o >> i;
  int sz = o.size();

  vector<int> oleg, igor, ans(sz);
  for (auto c : o) oleg.push_back(c - 'a');
  for (auto c : i) igor.push_back(c - 'a');

  sort(oleg.begin(), oleg.end());
  sort(igor.begin(), igor.end(), greater<int>());
  if (sz & 1) {
    // if sz is odd cut oleg by sz + 1/2, igor by sz/2;
    oleg.erase(oleg.begin() + (sz + 1) / 2, oleg.end());
    igor.erase(igor.begin() + sz / 2, igor.end());
  }
  else {
    // else, cut both vectors by half
    oleg.erase(oleg.begin() + sz / 2, oleg.end());
    igor.erase(igor.begin() + sz / 2, igor.end());
  }

  int r = sz - 1, l = 0, turn = 0;
  int left_o = 0, right_o = oleg.size() - 1, left_i = 0, right_i = igor.size() - 1;
  while (r >= l) {
    if (turn == 0) {
      if (oleg[left_o] >= igor[left_i]) {
        ans[r] = oleg[right_o];
        right_o--;
        r--;
      }
      else {
        ans[l] = oleg[left_o];
        left_o++;
        l++;
      }
    }
    else {
      if (igor[left_i] <= oleg[left_o]) {
        ans[r] = igor[right_i];
        right_i--;
        r--;
      }
      else {
        ans[l] = igor[left_i];
        left_i++;
        l++;
      }
    }
    turn ^= 1;
  }

  for (auto x : ans) cout << (char) (x + 'a');

  return 0;
}
