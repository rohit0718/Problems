#include <iostream>

using namespace std;

typedef long long ll;

int main() {

	int T, W;

	cin >> T >> W;

	for (int i = 0; i < T; i++) {

		ll day30, day31, day32, day33, day34, day35;
		cout << 30 << "\n";
		cin >> day30;
		cout << 31 << "\n";
		cin >> day31;
		cout << 32 << "\n";
		cin >> day32;
		cout << 33 << "\n";
		cin >> day33;
		cout << 34 << "\n";
		cin >> day34;
		cout << 35 << "\n";
		cin >> day35;

		ll R1 = (day31 - day30) / (1ULL << 30);
		ll R3 = (day33 - day32 - (R1 * (1ULL << 32))) / (1ULL << 10);
		ll R2 = (day34 - day33 - (R1 * (1ULL << 33))) / (1ULL << 16);
		ll R5 = (day35 - day34 - (R1 * (1ULL << 34))) / (1ULL << 6);
		ll R4 = (day32 - day31 - (R1 * (1ULL << 31))
			- (R2 * (1ULL << 15))) / (1ULL << 7);
		ll R6 = (day30 - (R1 * (1ULL << 30))
			- (R2 * (1ULL << 15)) - (R3 * (1ULL << 10))
			- (R4 * (1ULL << 7)) - (R5 * (1ULL << 6))
			) / (1ULL << 5);

		cout << R1 << " " << R2 << " " << R3 << " "
			<< R4 << " " << R5 << " " << R6 << "\n";

		int ans;
		cin >> ans;
		if (ans == -1) break;

	}





	return 0;
}