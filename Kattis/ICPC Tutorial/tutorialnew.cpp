#include <iostream>
#include <cmath>

using namespace std;


typedef long long ll;
const int MX = 1e9 + 2;

int m, n, t;

bool fac(int x) {
	ll ans = 1;
	while (x > 0) {
		ans *= 1LL*x;
		if (ans > MX) return false;
		x--;
	}
	return ans <= m;
}

bool pow(int x, int y) {
	ll ans = 1;
	for (int i = 0; i < y; i++) {
		ans *= x;
		if (ans > MX) return false;
	}
	return ans <= m;
}


int main() {
	bool b = 1;
	
	cin >> m >> n >> t;

	switch (t) {
		case 1:
			b = fac(n);
			break;
		case 2:
			b = pow(2, n);
			break;
		case 3:
			b = pow(n, 4);
			break;
		case 4:
			b = pow(n, 3);
			break;
		case 5:
			b = pow(n, 2);
			break;
		case 6:
			b = (1.0 * n * log2(n) <= m);
			break;
		default:
			b = (n <= m);

	}
		
	
	cout << (b ? "AC\n" : "TLE\n");
	return 0;
}