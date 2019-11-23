#include <iostream>
#include <cmath>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int H, v;
	cin >> H >> v;

	if (v <= 180) {
		cout << "safe" << "\n";
		return 0;
	}
	else if (v <= 270) v = -1 * (v - 270);
	else v -= 270;

	double vRad = v * (3.141592653585 / 180);

	cout << (int) (H / cos(vRad)) << endl;

	return 0;
}