#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int m = (n % 2 == 0) ? (n / 2) + 1: (n + 1) / 2;
	if (n == 1) m = 1;
	if (n == 2) m = 2;

	cout << m << endl;

	while (true) {
		for (int i = 1; i <= m; ++i) {
			cout << 1 << " " << i << endl;
			n--;
			if (n == 0) break;
		}
		if (n == 0) break;
		for (int i = m - n + 1; i <= m; i++) {
			cout << m << " " << i << endl;
			n--;
			if (n == 0) break;
		}
		if (n == 0) break;
	}


	return 0;
}