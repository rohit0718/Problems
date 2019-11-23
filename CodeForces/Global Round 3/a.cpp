#include <iostream>

using namespace std;

typedef long long ll;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;

	cin >> a >> b >> c;

	ll ans = 0;

	if (a > b) {
		ans += b * 2;
		if (a - b > 0) ans++;
	}
	else {
		ans += a * 2;
		if (b - a > 0) ans++;
	}

	ans += c * 2;

	cout << ans;

	return 0;

}
