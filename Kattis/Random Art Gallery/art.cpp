#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MX = 405;
const int INFTY = 1e7;

int N, k;
int galleries[MX];
int dp[MX][MX][MX];	


int solve(int pos, int prev_pos, int x) {
	if (pos >= 2 * N && x != 0) return INFTY;
	if (prev_pos >= 0 && dp[pos][prev_pos][x] != -1) return dp[pos][prev_pos][x];
	if (x == 0) return 0;

	int take = INFTY;
	int dont_take = solve(pos + 1, prev_pos, x);
	if (!(prev_pos >= 0 && prev_pos % 2 == 0 && pos - 3 == prev_pos)) 
		take = galleries[pos] + solve(pos + 2, pos, x - 1);
	
	int res = min(take, dont_take);
	if (prev_pos != -1) dp[pos][prev_pos][x] = res;
	return res;

}
int main() {

	memset(dp, -1, sizeof(dp));
	int end1, end2;
	int total = 0;
	cin >> N >> k;

	for (int i = 0; i < 2 * N; i++) {
		cin >> galleries[i];
		total += galleries[i];
	}

	cin >> end1 >> end2;

	cout << total - solve(0, -1, k);

	return 0;

}