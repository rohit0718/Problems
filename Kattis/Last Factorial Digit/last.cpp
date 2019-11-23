#include <iostream>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x;
		cin >> x;

		switch (x) {
		case 1:
			cout << 1 << "\n";
			break;
		case 2:
			cout << 2 << "\n";
			break;
		case 3:
			cout << 6 << "\n";
			break;
		case 4:
			cout << 4 << "\n";
			break;
		default:
			cout << 0 << "\n";
		}
	}

	return 0;
}