#include <iostream>
#include <cmath>

using namespace std;

int fact(int n) {
	if (n == 1) return 1;
	else return n * fact(n - 1);
}

int power(int x, int y) {
	int base = x;
	for (int i = 1; i < y; i++) {
		x *= base;
	}
	return x;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n, t;
	cin >> m >> n >> t;

	if (t == 1) {
		if (n >= 13) cout << "TLE";
		else if (fact(n) <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}
	if (t == 2) {
		if (n >= 13) cout << "TLE";
		else if ((1 << n) <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}
	if (t == 3) {
		if (n >= 216) cout << "TLE";
		else if (power(n, 4) <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}
	if (t == 4) {
		if (n >= 1291) cout << "TLE";
		else if (power(n, 3) <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}
	if (t == 5) {
		if (n >= 31623) cout << "TLE";
		else if (power(n, 2) <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}
	if (t == 6) {
		if (ceil(n * log2(n)) <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}
	if (t == 7) {
		if (n <= m) cout << "AC";
		else cout << "TLE";
		return 0;
	}

	return 0;
}