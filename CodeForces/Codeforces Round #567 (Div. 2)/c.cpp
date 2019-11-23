#include <iostream>
#include <string>
#include <vector>

using namespace std;

string arr[1002];
int dp[1002][1002];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int c = 0; c < m; ++c) dp[0][c] = 1;

	for (int c = 0; c < m; ++c) {
		for (int r = 1; r < n; ++r) {
			if (arr[r - 1][c] == arr[r][c]) {
				dp[r][c] = dp[r - 1][c] + 1;
			}
			else dp[r][c] = 1;
		}
	}


	int ans = 0;
	for (int r = 2; r < n; ++r) {
		int cnt = 0;
		for (int c = 0; c < m; ++c) {
			int mid_row = r - dp[r][c];
			int top_row = r - 2 * dp[r][c];
			if (top_row < 0) cnt = 0;
			else if (dp[r][c] != dp[mid_row][c]) cnt = 0;
			else if (dp[r][c] > dp[top_row][c]) cnt = 0;
			else if (c == 0) cnt = 1, ans++;
			else if (arr[top_row][c - 1] == arr[top_row][c] &&
							 arr[mid_row][c - 1] == arr[mid_row][c] &&
							 arr[r][c - 1] == arr[r][c] &&
							 dp[r][c - 1] == dp[r][c] &&
							 dp[mid_row][c - 1] == dp[mid_row][c]) {
								 cnt++;
								 ans += cnt;
							 }
			else cnt = 1,	ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
