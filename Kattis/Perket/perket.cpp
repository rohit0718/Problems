#include <iostream>

using namespace std;

//arranged in a line
//x0, x1, x2, x3

const int MX = 11;
int N;
int S[MX], B[MX];

//x0, x1, x2,
//sour is the sour value of the items you have from [x0..xpos-1]
//bitter is the bitter value of items from [x0..xpos-1]
//pos is current food item you are looking at
int solve(int pos, int sour, int bitter) {
	if (pos >= N) return abs(sour - bitter);

	int dont_take = solve(pos + 1, sour, bitter);
	int new_sour = S[pos] * sour;
	int new_bitter = B[pos] + bitter;
	int take = solve(pos + 1, new_sour, new_bitter);

	return min(dont_take, take);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 0; i < n; i++) {
		cin >> S[i] >> B[i];
		if (S[i] == B[i]) {
			cout << 0 << "\n";
			return 0;
		}
	}

	for (int i = 0)

	return 0;
}