#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {

		long long n;
		cin >> n;

		int ans = 0;
		bool possible = 1;
		while (n > 1) {
			if (n % 2 == 0) {
				n /= 2;
				ans++;
			}
			else if (n % 3 == 0) {
				n = (2 * n) / 3;
				ans++;
			}
			else if (n % 5 == 0) {
				n = (4 * n) / 5;
				ans++;
			}
			else {
				cout << "-1" << endl;
				possible = 0;
				break;
			}
		}
		
		if (possible) cout << ans << endl;
		

	}


	return 0;
}