#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	if (n % 10 == 0) n++, ans++;

	while (n > 10) {
		ans += 10 - (n % 10);
		n += 10 - (n % 10);
		while (n % 10 == 0) n /= 10;

	}

	cout << ans + 9 << "\n";

	return 0;

}