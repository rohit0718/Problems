#include <iostream>

using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int x, y, z;

	cin >> x >> y >> z;

	if (z < abs(y - x) || z == 0) {
		if (x > y) {
			cout << "+" << endl;
		}
		else if (y > x) {
			cout << "-" << endl;
		}
		else {
			cout << "0" << endl;
		}
	}
	else {

		cout << "?" << endl;
	}



	return 0;
}