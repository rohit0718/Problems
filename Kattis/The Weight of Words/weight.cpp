#include <iostream>

using namespace std;


int main() {

	int l, w;
	cin >> l >> w;

	if (w > l * 26 || w < l) {
		cout << "impossible" << "\n";
		return 0;
	}

	if (w % l != 0) {
		int repeat = w / (l - 1);

		for (int i = 2; i < l; ++i) {
			cout << (char)(repeat + 96);
		}
		if (repeat > 1) {

			cout << (char)(repeat - 1 + 96);

			cout << (char)(w - repeat * (l - 1) + 97) << "\n";
		}
		else {
			cout << (char)(repeat + 96);

			cout << (char)(w - repeat * (l - 1) + 96) << "\n";
		}
	}
	else {
		for (int i = 0; i < l; ++i) {
			cout << (char)(w / l + 96);
		}
	}

	return 0;
	
}