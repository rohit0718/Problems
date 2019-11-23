#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;



	for (int r = 1; r <= n / 2; ++r) {
		for (int c = 1; c <= m; ++c) {
			cout << r << " " << c << "\n";
			cout << n + 1 - r << " " << m + 1 - c << "\n";
		}
	}

	if (n % 2 != 0) {
		// print out the final row at (n + 1) / 2
		for (int c = 1; c <= m / 2; ++c) {
			cout << (n + 1) / 2 << " " << c << "\n";
			cout << (n + 1) / 2 << " " << m + 1 - c << "\n";
		}

		if (m % 2 != 0) {
			// print out centre square
			cout << (n + 1) / 2 << " " << (m + 1) / 2;

		}
	}

	



	return 0;
}