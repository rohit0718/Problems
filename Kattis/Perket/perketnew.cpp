#include <iostream>
#include <algorithm>

using namespace std;

int N;
int S[11], B[11];


int solve(int pos, int sour, int bitter) {

	if (pos >= N) return abs(sour - bitter);
	

	int dont_take = solve(pos + 1, sour, bitter);
	int new_sour = sour * S[pos];
	int new_bitter = bitter + B[pos];
	int take = solve(pos + 1, new_sour, new_bitter);
	if (pos == N - 1 && sour == 1 && bitter == 0) return take;

	return min(dont_take, take);
}


int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> S[i] >> B[i];
	}
	cout << solve(0, 1, 0);
	return 0;
}