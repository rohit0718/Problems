#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int N, K;
		cin >> N >> K;
		if ((K + 1) % (1 << N) == 0) {
			cout << "Case #" << i << ": " << "ON" << "\n";
		}
		else cout << "Case #" << i << ": " << "OFF" << "\n";
	}

	return 0;
}