#include <iostream>
#include <cstring>

using namespace std;

const int MX = 1005;

int n;
int weights[MX];
int dp[MX][MX];

int solve(int pos, int ans) {

	if (pos >= n) return ans;
	if (ans >= 1000) return ans;
	if (dp[pos][ans] != -1) return dp[pos][ans];

	int dont_take = solve(pos + 1, ans);
	int take = solve(pos + 1, ans + weights[pos]);

	int res = dont_take;
	if (abs(1000 - take) <= abs(1000 - dont_take)) res = take;

	return dp[pos][ans] = res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> weights[i];

	cout << solve(0, 0);

	return 0;
}