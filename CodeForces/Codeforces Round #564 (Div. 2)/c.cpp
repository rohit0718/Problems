#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> deck;
int pos[200005];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, ans;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		pos[x] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		pos[x] = i;
		deck.push_back(x);
	}

	// checking to see if can solve
	if (pos[1]) {

		for (i = 2; i <= n && pos[i] == pos[1] + i - 1; ++i);
		if (pos[i - 1] == n) {
			for (j = i; j <= n && pos[j] <= j - i; ++j);
			if (j > n) {
				cout << n - i + 1 << endl;
				return 0;
			}
		}

	}


	// if cannot solve
	ans = -1;
	for (int i = 1; i <= n; ++i) ans = max(ans, pos[i] - i + 1);
	

	cout << ans + n << endl;

	return 0;
}