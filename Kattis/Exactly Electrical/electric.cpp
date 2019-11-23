#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, c, d, charge;

	cin >> a >> b >> c >> d >> charge;

	if (abs(c - a) + abs(d - b) <= charge && (charge - abs(c - a) + abs(d - b)) % 2 == 0)
		cout << "Y" << "\n";
	else cout << "N" << "\n";

	return 0;

}